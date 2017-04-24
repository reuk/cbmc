-[ ] Set up doxygen config
-[ ] Work out what information we need to parse for
  - files
  - functions
  - classes

-[ ] Replace file headers

Global-scope objects are only documented if their files are documented.

Doc blocks in cpp_typecheck_conversions.cpp are tricky, because the Purpose
field may contain multiple paragraphs separated by blank lines.
Expand field parser so that entries that don't start with `<word>:` are appended
to the previous field.
