#ifndef CPROVER_UTIL_LISPIREP_H
#define CPROVER_UTIL_LISPIREP_H

class irept;
class lispexprt;

void lisp2irep(const lispexprt &src, irept &dest);
void irep2lisp(const irept &src, lispexprt &dest);

#endif // CPROVER_UTIL_LISPIREP_H
