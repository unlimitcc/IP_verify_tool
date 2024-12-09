#ifdef __VERIHAR_KLEE__
#include <klee/klee.h>
#define _AND_ &
#define _OR_ |
#else
#define _AND_ &&
#define _OR_ ||
#endif

extern unsigned nondet_uint(void);
extern int nondet_int(void);
extern char nondet_char(void);

void __VERIFIER_assume(int expression) { if (!expression) { LOOP: goto LOOP; }; return; }
void reach_error() { ERROR: return; };
void __VERIFIER_assert(int expression) { if (!expression) { reach_error(); ERROR: return; } }

void __VERIHAR_PRECONDITION__(){};
void __VERIHAR_POSTCONDITION__(){};

void __MAKE_SYMBOLIC(void *addr, size_t nbytes, const char *name){
#ifdef __VERIHAR_KLEE__
    klee_make_symbolic(addr, nbytes, name);
#endif
}

#ifdef __VERIHAR_CBMC__
#define __ASSUME(condition) __CPROVER_assume(condition)
#define __ASSERT(condition) assert(condition)
#define __FORALL(condition) __CPROVER_forall {condition}
#define __EXISTS(condition) __CPROVER_exists {condition}
#elif __VERIHAR_ESBMC__
#define __ASSUME(condition) __ESBMC_assume(condition)
#define __ASSERT(condition) assert(condition)
#define __FORALL(condition) 1
#define __EXISTS(condition) 1
#elif __VERIHAR_CPACHECKER__
#define __ASSUME(condition) __VERIFIER_assume(condition)
#define __ASSERT(condition) __VERIFIER_assert(condition)
#define __FORALL(condition) 1
#define __EXISTS(condition) 1
#elif __VERIHAR_KLEE__
#define __ASSUME(condition) klee_assume(condition)
#define __ASSERT(condition) assert(condition)
#define __FORALL(condition) 1
#define __EXISTS(condition) 1
#else
#define __ASSUME(condition) {}
#define __ASSERT(condition) {}
#define __FORALL(condition) 1
#define __EXISTS(condition) 1
#endif