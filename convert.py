import re, collections


Field = collections.namedtuple('Field', ['name', 'contents'])


def parse_fields(block_contents):
    field_re = re.compile(r'\n *([\S ]+?):\s*?(\S.*?)?^$', re.MULTILINE | re.DOTALL)
    for m in field_re.finditer(block_contents):
        yield Field(m.group(1), m.group(2))


Block = collections.namedtuple('Block', ['fields'])


def match_blocks(contents):
    start = r'^/\*+\\$'
    middle = r'.*?'
    end = r'^\\\*+/$'
    block = start + middle + end
    block_re = re.compile(block, re.MULTILINE | re.DOTALL)

    for m in block_re.finditer(contents):
        yield Block(list(parse_fields(m.group())))


def convert_file(file):
    with open(file) as f:
        contents = f.read()

    for block in match_blocks(contents):
        print(block)
