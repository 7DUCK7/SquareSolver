#include "TXlib.h"
#include "FUNCS.h"
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <assert.h>

struct TestData
{
    double a, b, c;
    double x1, x2;
    int nROOTS;
    const char Name[NAME_SIZE];
};
//#include "func.cpp"
//#include "test.cpp"
int main(int argc, char* argv[])
{
    TestData allData[nTESTS] = {{.a = 0, .b = 0, .c = 0, .x1 = 0, .x2 = 0, .nROOTS = INF_ROOTS, "zero_arguments"},
                            {.a = 1, .b = 0, .c = -4, .x1 = -2, .x2 = 2, .nROOTS = 2, "Basic_test1"},
                            {.a = 0, .b = 0, .c = 3, .x1 = 0, .x2 = 0, .nROOTS = 0, "zero_roots"},
                            {.a = 1, .b = -5, .c = 4, .x1 = 1, .x2 = 4, .nROOTS = 2, "Basic_test2"}};
    TestData data1 = {0, 0, 0, 0, 0, INF_ROOTS, "InfTest"};

    if (strcmp(argv[1], "-test") != 0 && strcmp(argv[1] , "-perform") != 0)
    {
        printf("Доступны только два аргумента командной строки -test и -perform\n");
        return 1;
    }

    if (strcmp(argv[1], "-test") == 0)
    {
        for(int i = 0; i < nTESTS; i++)
        {
            TestOne(&allData[i]);
        }
        return 2;
    }
    else
    {

        printf ("# Программа для решения квадратного уравнения\n");

        int where_to_read_from = 0;
        FILE* choice_of_how_to_read = 0;
        char file_name[40] = "";
        double a = 0, b = 0, c = 0;

        printf("Выберете способ которым хотите ввести данные:\n");
        printf("1 - вручную\n");
        printf("2 - через файл\n");


        get_type_of_the_input_from_user(&where_to_read_from);



        int num_of_successful_solution = Read(&a, &b, &c, choose_how_to_read(where_to_read_from, file_name, choice_of_how_to_read));

        printf("В ходе попытки %d:\n", num_of_successful_solution);

        double x1 = 0, x2 = 0;
        int nROOTS = SolveSqrEq (a, b, c, &x1, &x2);

        Return_the_answer(nROOTS, x1, x2);
        return 3;
    }
}
