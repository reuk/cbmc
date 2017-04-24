# todo

-[ ] Set up doxygen config
-[ ] Work out what information we need to parse for
  - files
  - functions
  - classes

-[x] Replace file headers

-[ ] Handle multi-paragraph fields gracefully
-[ ] If any word in any field matches the name of a function parameter, prepend
     it with `\p`
-[ ] Write a function to format Block into Doxygen style
  -[ ] line wrapping

-[x] Work out how to properly substitute a text range while running finditer
  - Use re.sub instead

# notes

Global-scope objects are only documented if their files are documented.

Doc blocks in cpp_typecheck_conversions.cpp are tricky, because the Purpose
field may contain multiple paragraphs separated by blank lines.
Expand field parser so that entries that don't start with `<word>:` are appended
to the previous field.

# setup

## macOS

```
# Get LLVM with Python bindings
brew install llvm --with-python --with-lldb --with-clang
# Make sure Python can find the bindings
echo /usr/local/opt/llvm/lib/python2.7/site-packages >> /usr/local/lib/python2.7/site-packages/llvm.pth
```
