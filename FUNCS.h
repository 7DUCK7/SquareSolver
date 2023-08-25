#define isZERO 0.0000000001
struct TestData;

enum number_of_roots {INF_ROOTS = 3, ONE = 1, TWO = 2, ZERO = 0};
enum some_consts {NAME_SIZE = 30, nTESTS = 4};

int CompareWithZero (double);
int SolveLinearEq (double, double, double*);
int SolveSqrEq (double, double, double, double*, double*);
int ReadFile (double* a_pointer, double* b_pointer, double* c_pointer);
int ReadManual (double* a_pointer, double* b_pointer, double* c_pointer);
int TestAll ();
int Read (double* a_pointer, double* b_pointer, double* c_pointer, FILE* how_to_read);
int how_to_read_coeffs(double* a_ptr, double* b_ptr, double* c_ptr, int where_to_read_from, FILE* how_to_read);
//int TestOne ();
int CompareDoubleNumbers(double number1, double number2);

void TestOne(TestData*);
