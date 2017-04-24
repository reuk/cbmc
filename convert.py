import re, collections


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


def match_blocks(contents):
    start = r'^/\*+\\$'
    middle = r'.*?'
    end = r'^\\\*+/$'
    block = start + middle + end
    block_re = re.compile(block, re.MULTILINE | re.DOTALL)

    for m in block_re.finditer(contents):
        yield Block(list(parse_fields(m.group()))), m.start(), m.end()


def has_field(block, field_name):
    return any(map(lambda x: re.match(field_name, x.name, re.IGNORECASE),
        block.fields))


def is_file_header(block):
    return has_field(block, 'module') and has_field(block, 'author')


def convert_file_header(block):
    return ''


def convert_block(block):
    if is_file_header(block):
        return convert_file_header(block)
    return str(block)


def convert_file(file):
    with open(file) as f:
        contents = f.read()

    for block, start, end in match_blocks(contents):
        contents = contents[:start] + convert_block(block) + contents[end:]

    print(contents)
