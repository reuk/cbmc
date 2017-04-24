import re, collections, textwrap, sys, argparse, platform
import clang.cindex


Field = collections.namedtuple('Field', ['name', 'contents'])

Header = collections.namedtuple('Header', ['module', 'author'])

Function = collections.namedtuple('Function',
        ['pos', 'name', 'purpose', 'inputs', 'returns'])


def warn(message):
    """ Print a labelled message to stderr.  """
    sys.stderr.write('Warning: %s\n' % message)


def header_from_block(block):
    """ Create a Header structure from a parsed Block.  """
    return Header(block.fields['Module'], block.fields['Author'])


def function_from_block(block):
    """ Create a Function structure from a parsed Block.  """
    return Function(block.pos, block.fields['Function'],
            block.fields['Purpose'], block.fields['Inputs'],
            block.fields['Outputs'])


def parse_fields(block_contents):
    """ Extract the named fields of an old-style comment block.  """
    text_wrapper = textwrap.TextWrapper(width=75)

    field_re = re.compile(
            r'(?:\n *(Purpose):(.*))|(?:\n *([a-zA-Z0-9]+?):\s*?(\S.*?)?^$)',
            re.MULTILINE | re.DOTALL)
    whitespace_re = re.compile(r'\n\s*', re.MULTILINE | re.DOTALL)
    for m in field_re.finditer(block_contents):
        # If the field is a Purpose field
        if m.lastindex == 2:
            field_name = m.group(1)
            field_contents = m.group(2)
            # Remove spacing from first paragraph
            paragraph_re = re.compile(r'(.*?)^$(.*)', re.MULTILINE | re.DOTALL)
            match = paragraph_re.match(field_contents)
            first_paragraph = match.group(1)
            first_paragraph, _ = whitespace_re.subn(' ',
                    first_paragraph) if first_paragraph else ('', None)
            tail_paragraphs = ('\n' + match.group(2)) if match.group(2) else ''
            yield Field(field_name,
                    text_wrapper.fill(first_paragraph) + tail_paragraphs)
        # If the field is any other field
        elif m.lastindex == 3 or m.lastindex == 4:
            contents = m.group(4)
            text, _ = whitespace_re.subn(' ',
                    contents) if contents else ('', None)
            yield Field(m.group(3), text)


Block = collections.namedtuple('Block', ['pos', 'fields'])


def has_field(block, field_name):
    """ Return whether the block has a field with the given name.  """
    return field_name in block.fields


def is_header_doc(block):
    """ Return whether the block appears to be a file header.  """
    return has_field(block, 'Module') and has_field(block, 'Author')


def convert_header_doc(header):
    """ Return a doxygen-style header string.  """
    return ''


def is_function_doc(block):
    """ Return whether the block appears to be a function descriptor.  """
    return has_field(block, 'Function')

def convert_function_doc(function, file, definitions):
    """ Return a doxygen-style doc string for the supplied Function.  """
    function_name_re = re.compile(r'(?:.*?::)?(\S*)')
    function_name = function_name_re.match(function.name).group(1)

    # Search definitions for matching name
    definition = next(
            (x for x in definitions
                if x.spelling == function_name and
                function.pos < x.location.offset and
                file == str(x.location.file)), None)

    if definition:
        # Check that there are no other definitions between the comment and the
        # function we're probably documenting
        for d in definitions:
            if (function.pos < d.location.offset and
                    d.location.offset < definition.location.offset and
                    file == str(d.location.file)):
                warn('docs for %s do not immediately precede that function' %
                        d.spelling)
        # TODO Now we can be smart about finding function parameter names
    else:
        warn('no function with name "%s" found' % function_name)

    text_wrapper = textwrap.TextWrapper(width=75)

    sections = []

    if function.purpose:
        sections.append(function.purpose.strip())

    if function.inputs:
        sections.append(text_wrapper.fill(function.inputs))

    if function.returns:
        sections.append(text_wrapper.fill('\\returns %s' % function.returns))

    if sections:
        text = '\n\n'.join(sections)
        if text:
            text, _ = re.subn(r'^(?!$)', r'/// ', text, flags=re.MULTILINE)
            text, _ = re.subn(r'^(?=$)', r'///' , text, flags=re.MULTILINE)
        return text + '\n'

    return ''


def replace_block(start, block_contents, file, definitions):
    """
    Replace an old-style documentation block with the doxygen equivalent
    """
    block = Block(start,
            {f.name: f.contents for f in parse_fields(block_contents)})

    if is_header_doc(block):
        return convert_header_doc(header_from_block(block))

    if is_function_doc(block):
        return convert_function_doc(
                function_from_block(block), file, definitions)

    warn('block in file %s has unrecognised format:\n%s' %
            (file, block_contents))

    return ''


def method_definitions(cursor):
    """
    Return each syntactic item which appears to be a documentable definition.

    Inspired by
    http://stackoverflow.com/questions/37336867/how-to-get-class-method-definitions-using-clang-python-bindings
    """
    for i in cursor.walk_preorder():
        if ((i.kind == clang.cindex.CursorKind.CXX_METHOD or
                i.kind == clang.cindex.CursorKind.CONSTRUCTOR) and
                i.is_definition()):
            yield i


def convert_file(file):
    """ Replace documentation in file with doxygen-styled comments.  """
    index = clang.cindex.Index.create()
    translation_unit = index.parse(file, ['-x', 'c++'])
    definitions = list(method_definitions(translation_unit.cursor))

    with open(file) as f:
        contents = f.read()

    block_re = re.compile(
            r'^/\*+\\$(.*?)^\\\*+/$\s*', re.MULTILINE | re.DOTALL)
    contents, _ = block_re.subn(
            lambda match: replace_block(match.start(), match.group(1), file,
                definitions), contents)

    sys.stdout.write(contents)


def get_lib_path():
    """ Return the most likely location of the clang library.  """
    return {
            'Darwin': '/usr/local/Cellar/llvm/4.0.0/lib/libclang.dylib',
            'Linux': '/usr/lib/llvm-3.8/lib/libclang.so.1',
        }[platform.system()]


def main():
    """ Run convert_file from the command-line.  """
    parser = argparse.ArgumentParser()
    parser.add_argument('file', type=str, help='The file to process')
    parser.add_argument('--libclang', type=str, help='The clang library')
    args = parser.parse_args()

    lib_path = args.libclang if args.libclang else get_lib_path()

    if not clang.cindex.Config.loaded:
        clang.cindex.Config.set_library_file(lib_path)

    convert_file(args.file)

    return 0


if __name__ == '__main__':
    sys.exit(main())
