enum {INF_ROOTS = 3, name_size = 30, nTests = 4};
#define isZERO 0.0000000001

int FloatComparison (double);
int SolveLinearEq (double, double, double*);
int SolveSqrEq (double, double, double, double*, double*);
int ReadFile (double* a_pointer, double* b_pointer, double* c_pointer);
int ReadManual (double* a_pointer, double* b_pointer, double* c_pointer);
int TestAll ();

//int TestOne ();
void TestOne();
