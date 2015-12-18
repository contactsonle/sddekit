/* Apache 2.0 INS-AMU 2015 */

#ifndef SK_TEST_H
#define SK_TEST_H

#ifdef __cplusplus
extern "C" {
#endif

void sk_test_true_(int cond, char *scond, char *fname, int lineno);

int sk_test_report();

#define sk_test_true(cond) sk_test_true_(cond, #cond, __FILE__, __LINE__)

#define sk_test_tol(l, r, tol)\
sk_test_true((((l)-(r))*((l)-(r)))<tol)

#ifdef __cplusplus
}; /* extern "C" */
#endif

#endif
