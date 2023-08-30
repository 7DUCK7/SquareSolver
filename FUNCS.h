#define isZERO 0.0000000001

enum INPUT_TYPE {NOT_CHOSEN_YET = 0, FROM_CONSOLE = 1, FROM_FILE = 2};
enum NUMBER_OF_ROOTS {INF_ROOTS = 3, ONE = 1, TWO = 2, ZERO = 0};
enum SOME_CONSTS {NAME_SIZE = 30, nTESTS = 4, FILE_NAME_SIZE = 40};

struct TestData
{
    double a, b, c;
    double x1, x2;
    int nROOTS;
    const char Name[NAME_SIZE];
};

int Perform();
int IsItZero (double);
int SolveLinearEq (double, double, double*);
int SolveSqrEq (double, double, double, double*, double*);
int ReadFile (double* a_pointer, double* b_pointer, double* c_pointer);
int ReadManual (double* a_pointer, double* b_pointer, double* c_pointer);
int TestAll ();
int Read (double* a_pointer, double* b_pointer, double* c_pointer, FILE* chosen_type_of_input);
int CompareDoubleNumbers(double number1, double number2);
int get_type_of_the_input_from_user(INPUT_TYPE* where_to_read_from);
int get_file_name(char* file_name);
int Mystrcmp(const char* str1, const char* str2);

void scan_file_name(char* name);
void Print_the_answer(int nROOTS, double x1, double x2);
void buffer_clean(FILE* chosen_type_of_input);
void TestOne(TestData*);
void first_msg();
//void Inizialization();

FILE* choose_how_to_read(INPUT_TYPE where_to_read_from, char* file_name, FILE* chosen_type_of_input);
