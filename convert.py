import re, collections


Field = collections.namedtuple('Field', ['name', 'contents'])


def parse_fields(block_contents):
    field_re = re.compile(
            r'\n *([\S ]+?):\s*?(\S.*?)?^$', re.MULTILINE | re.DOTALL)
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
        yield Block(list(parse_fields(m.group())))


def convert_file(file):
    with open(file) as f:
        contents = f.read()

    for block in match_blocks(contents):
        print('Block:')
        for field in block.fields:
            print('%s: %s' % (field.name, field.contents))
