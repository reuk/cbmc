import re, collections
import clang.cindex


Field = collections.namedtuple('Field', ['name', 'contents'])


def parse_fields(block_contents):
    field_re = re.compile(
            r'\n *( *[a-zA-Z0-9]+?):\s*?(\S.*?)?^$', re.MULTILINE | re.DOTALL)
    whitespace_re = re.compile(r'\n\s*', re.MULTILINE | re.DOTALL)
    for m in field_re.finditer(block_contents):
        contents = m.group(2)
        text, _ = whitespace_re.subn(' ', contents) if contents else ('', None)
        yield Field(m.group(1), text)


Block = collections.namedtuple('Block', ['fields'])


def has_field(block, field_name):
    return field_name in block.fields


def is_file_header(block):
    return has_field(block, 'Module') and has_field(block, 'Author')


def convert_file_header(block):
    return ''


def is_function_doc(block):
    return (has_field(block, 'Function') and has_field(block, 'Inputs') and
            has_field(block, 'Outputs') and has_field(block, 'Purpose'))


def method_definitions(cursor):
    """
    http://stackoverflow.com/questions/37336867/how-to-get-class-method-definitions-using-clang-python-bindings
    """
    for i in cursor.walk_preorder():
        if i.kind != clang.cindex.CursorKind.CXX_METHOD:
            continue
        if not i.is_definition():
            continue
        yield i


def convert_function_doc(block, definitions):
    function_name = block.fields['Function']
    print('converting %s' % function_name)

    # TODO search definitions for matching name

    # TODO if no match, just use the immediately following function def

    return ''


def replace_block(match, definitions):
    block = Block({f.name: f.contents for f in (parse_fields(match.group()))})

    if is_file_header(block):
        return convert_file_header(block)

    if is_function_doc(block):
        return convert_function_doc(block, definitions)

    return ''


def convert_file(file):
    # TODO set from cmdline
    if not clang.cindex.Config.loaded:
        clang.cindex.Config.set_library_path(
                '/usr/local/Cellar/llvm/4.0.0/lib')

    index = clang.cindex.Index.create()
    translation_unit = index.parse(file, ['-x', 'c++'])
    definitions = list(method_definitions(translation_unit.cursor))

    with open(file) as f:
        contents = f.read()

    block_re = re.compile(r'^/\*+\\$.*?^\\\*+/$', re.MULTILINE | re.DOTALL)
    contents, _ = block_re.subn(
            lambda match: replace_block(match, definitions), contents)

    print(contents)
