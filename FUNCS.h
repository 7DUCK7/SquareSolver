#define isZERO 0.0000000001

struct TestData;

enum where_to_read_from {FROM_CONSOLE = 1, FROM_FILE = 2};
enum number_of_roots {INF_ROOTS = 3, ONE = 1, TWO = 2, ZERO = 0};
enum some_consts {NAME_SIZE = 30, nTESTS = 4};

int CompareWithZero (double);
int SolveLinearEq (double, double, double*);
int SolveSqrEq (double, double, double, double*, double*);
int ReadFile (double* a_pointer, double* b_pointer, double* c_pointer);
int ReadManual (double* a_pointer, double* b_pointer, double* c_pointer);
int TestAll ();
int Read (double* a_pointer, double* b_pointer, double* c_pointer, FILE* choice_of_how_to_read);
//int how_to_read_coeffs(double* a_ptr, double* b_ptr, double* c_ptr, int where_to_read_from);
//int TestOne ();
int CompareDoubleNumbers(double number1, double number2);
int get_type_of_the_input_from_user(int* where_to_read_from);
int get_file_name(char* file_name);

void TestOne(TestData*);
int Return_the_answer(int nROOTS, double x1, double x2);

FILE* choose_how_to_read(int where_to_read_from, char* file_name, FILE* choice_of_how_to_read);
