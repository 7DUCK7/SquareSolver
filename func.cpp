#include "TXlib.h"
#include "FUNCS.h"
#include <stdio.h>
#include <math.h>
#include <assert.h>

int IsItZero (double a)
{
    if (fabs(a) <= isZERO)
        return 1;
    else
        return 0;
}

int SolveLinearEq (double b, double c, double* x1)
{
    assert(isfinite(b));
    assert(isfinite(c));

    if (x1 == 0)
    {
        printf("Введён некорректный указатель для корня x1 в %s, в функции SolveLinearEq. Строка %d.\n", __FILE__, __LINE__);
    }
    else
    {
        if (IsItZero(b))
        {
            return (IsItZero(c)) ? INF_ROOTS : 0;
        }
        else
        {
            *x1 = -c / b;
            return 1;
        }
    }
    return 9;
}

int SolveSqrEq (double a, double b, double c, double* x1, double* x2)
{
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));

    if (x1 == 0 || x2 == 0)
    {
        printf("Введены некорректные указатели для корней уравнения в %s, в функции SolveSqrEq. Строка %d.\n", __FILE__, __LINE__);  // __LINE__
    }
    else
    {
        if (IsItZero(a))
        {
            return (SolveLinearEq (b, c, x1));
        }
        else
        {
            double d = b*b - 4*a*c;

            if (d > 0)
            {
                double sqrt_d = sqrt (d);
                *x1 = (-b + sqrt_d) / (2 * a);
                *x2 = (-b - sqrt_d) / (2 * a);
                return 2;
            }
            else
            {
                if (IsItZero(d))
                {
                    *x1 = -b / (2 * a);
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
        }
    }
    return 0;

}

int Read (double* a_pointer, double* b_pointer, double* c_pointer, FILE* chosen_type_of_input)          //fixxxxxxxxxxxx
{
    if (a_pointer == 0 || b_pointer == 0 || c_pointer == 0 || chosen_type_of_input == 0)
    {
        printf("Введены неверные указатели в %s в функции Read. Строка %d.\n", __FILE__, __LINE__);
    }
    else
    {
        int num_of_input = 1;
        int successful_fscanfs = 0;

        while (successful_fscanfs != 3)
        {
            successful_fscanfs = fscanf (chosen_type_of_input, "%lg %lg %lg", a_pointer, b_pointer, c_pointer);
            if (successful_fscanfs != 3)
            {

                printf("Введены неверные данные в %d попытке (a=%lg b=%lg c=%lg). Повторите попытку:\n",
                    num_of_input, *a_pointer, *b_pointer, *c_pointer);
                *a_pointer = 0; *b_pointer = 0; *c_pointer = 0;
            }

            num_of_input += 1;
            buffer_clean(chosen_type_of_input);
            if (successful_fscanfs == 3)
                break;
        }

        return num_of_input - 1;
    }
    return num_of_input - 1;
}

int CompareDoubleNumbers(double number1, double number2)
{
    assert(isfinite(number1));
    assert(isfinite(number2));

    if (fabs(number1 - number2) < isZERO)
        return 1;
    else
        return 0;

}

void Print_the_answer(int nROOTS, double x1, double x2)
{
    assert(isfinite(nROOTS));
    assert(isfinite(x1));
    assert(isfinite(x2));

    switch (nROOTS)
    {
    case ZERO:
            printf ("Решений нет\n");
            break;
    case ONE:
            printf ("x = %lg\n", x1);
            break;
    case TWO:
            printf ("x1 = %lg, x2 = %lg\n", x1, x2);
            break;
    case INF_ROOTS:
            printf("Бесконечное число корней\n");
            break;
    default:
            printf("main(): ERROR: nROOTS = %d\n", nROOTS);
    }

}

int get_file_name(char* file_name)
{
    printf("Введите название файла с расширением:\n");
    buffer_clean(stdin);
    scan_file_name(file_name);
    while (fopen(file_name ,"r") == NULL)
        {
            printf("Имя файла введено неверно, повторите попытку:\n");
            //printf(file_name);
            //buffer_clean(stdin);
            scan_file_name(file_name);
                                                         //write this func urself using for i...
        }
    return 1;
}


int get_type_of_the_input_from_user(INPUT_TYPE* where_to_read_from)
{
    scanf("%d", where_to_read_from);
    while((*where_to_read_from != FROM_FILE) && (*where_to_read_from != FROM_CONSOLE))
    {
        buffer_clean(stdin);
        printf("Введена неверная команда\n"
               "Попробуйте заново\n");
        scanf("%d", where_to_read_from);
    }
    return 1;
}

int Perform()
{
        INPUT_TYPE where_to_read_from = NOT_CHOSEN_YET;
        FILE* chosen_type_of_input;      //fix names of variables
        char file_name[FILE_NAME_SIZE] = "";
        double a = 0, b = 0, c = 0;

        first_msg();

        get_type_of_the_input_from_user(&where_to_read_from);

        int num_of_successful_solution = Read(&a, &b, &c, choose_how_to_read(where_to_read_from, file_name, chosen_type_of_input));

        printf("В ходе попытки %d:\n", num_of_successful_solution);

        double x1 = 0, x2 = 0;
        int nROOTS = SolveSqrEq (a, b, c, &x1, &x2);

        Print_the_answer(nROOTS, x1, x2);
        return 3;
}

FILE* choose_how_to_read(INPUT_TYPE where_to_read_from, char* file_name, FILE* chosen_type_of_input)
{
    if (where_to_read_from == FROM_FILE)
    {
        get_file_name(file_name);
        chosen_type_of_input = fopen(file_name,"r");
    }
    else
    {
        chosen_type_of_input = stdin;
        printf("Введите коэффициенты уравнения\n");
    }
    return chosen_type_of_input;
}

int Mystrcmp(const char* str1, const char* str2)
{
    int j = 0;
    while(str1[j] != '\0' || str2[j] != '\0')
    {
        if (str1[j] != str2[j])
        {
            return 1;
        }
        j += 1;
    }
    return 0;
}

void buffer_clean(FILE* chosen_type_of_input)
{
    while (getc(chosen_type_of_input) != '\n')
                    ;
}

void first_msg()
{
    printf ("# Программа для решения квадратного уравнения\n");
    printf("Выберете способ которым хотите ввести данные:\n");
    printf("1 - вручную\n");
    printf("2 - через файл\n");
}


void scan_file_name(char* name)
{
    for (int i = 0; i < FILE_NAME_SIZE; i++)
    {
        name[i] = getchar();
        if (name[i] == '\n')
        {
            name[i] = '\0';
            break;
        }
    }
}
/*
void Inizialization(int argc, char* argv)
{
    if (argc != 2)
    {
        printf("Можно ввести только один аргумент командной строки (-test или -perform). Попробуйте заново.\n");
        return 1;                                                                           //make if easier
    }

    if (Mystrcmp(argv[1], "-test") == 0)
    {
        for(int i = 0; i < nTESTS; i++)
        {
            TestOne(&allData[i]);
        }
        return 2;
    }
    else
    {
        if (Mystrcmp(argv[1], "-perform") == 0)
        {
            Perform();
            return 3;

        }
        else
        {
            printf("Можно ввести только один аргумент командной строки (-test или -perform). Попробуйте заново.\n");
            return 1;
        }
    }
}   */
