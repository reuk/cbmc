# todo

-[ ] Set up doxygen config

-[ ] If any word in any field matches the name of a function parameter, prepend
     it with `\p`

-[ ] add filename to 'no function with name' message

-[ ] stop adding blank lines to the ends of files

-[ ] comments look weird if the comment block has just a returns statement

-[x] Handle multi-paragraph fields properly

-[x] Issue a warning if a doc block doesn't appear next to the named function

-[x] Replace file headers

-[x] Write a function to format Block into Doxygen style
  -[x] line wrapping

-[x] Work out how to properly substitute a text range while running finditer
  - Use re.sub instead

# notes

Global-scope objects are only documented if their files are documented.

Doc blocks in cpp_typecheck_conversions.cpp are tricky, because the Purpose
field may contain multiple paragraphs separated by blank lines.
Expand field parser so that entries that don't start with `<word>:` are appended
to the previous field.

Might it be easier to extract blocks and insert them separately?

# setup

## macOS

```
# Get LLVM with Python bindings
brew install llvm --with-python --with-lldb --with-clang
# Make sure Python can find the bindings
echo /usr/local/opt/llvm/lib/python2.7/site-packages >> /usr/local/lib/python2.7/site-packages/llvm.pth
```
