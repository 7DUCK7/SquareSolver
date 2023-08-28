#include "TXlib.h"
#include "FUNCS.h"
#include <stdio.h>
#include <math.h>
#include <assert.h>

int CompareWithZero (double a)
{
    if (fabs(a) <= isZERO)
        return 1;
    else
        return 0;
}

int SolveLinearEq (double b, double c, double* x1)
{
    if (CompareWithZero(b))
    {
        return (CompareWithZero(c))? INF_ROOTS : 0;
    }
    else
    {
     *x1 = -c / b;
     return 1;
    }
}

int SolveSqrEq (double a, double b, double c, double* x1, double* x2)    // if for x pointer
{
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));
    // fix indentation
    // float comparison
    if (x1 == 0 || x2 == 0)
    {
        printf("Введены некорректные указатели для корней уравнения\n");
    }
    else
    {
        if (CompareWithZero(a))
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
                if (CompareWithZero(d))
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
/*
int ReadManual (double* a_pointer, double* b_pointer, double* c_pointer)
{
    // check correctness +
    printf ("# Введите коэффициенты уравнения\n");
    while (fscanf (stdin, "%lg %lg %lg", a_pointer, b_pointer, c_pointer) != 3)    // correctness check
    {
        while (getchar() != '\n')
            ;
        printf("Введены неверные данные (a= %lg b= %lg c= %lg)\n", *a_pointer, *b_pointer, *c_pointer);
    }
    return 1;
}

int ReadFile (double* a_pointer, double* b_pointer, double* c_pointer)
{
    FILE * file = fopen("RT.txt", "r");

    while (fscanf(file, "a=%lg b=%lg c=%lg", a_pointer, b_pointer, c_pointer) != 3)
    {
        while (getchar() != '\n')
            ;
        printf("Введены неверные данные (a= %lg b= %lg c= %lg)\n", *a_pointer, *b_pointer, *c_pointer);
    }

    fclose(file);
    return 1;
}  */

int Read (double* a_pointer, double* b_pointer, double* c_pointer, FILE* choice_of_how_to_read)
{
    int num_of_input = 0;
    int flag = 0;

    while (flag != 3)    // correctness check
    {
        flag = fscanf (choice_of_how_to_read, "%lg %lg %lg", a_pointer, b_pointer, c_pointer);
        if (flag != 3)
        {
            num_of_input += 1;
            printf("Введены неверные данные в %d попытке (a=%lg b=%lg c=%lg). Повторите попытку:\n", num_of_input, *a_pointer, *b_pointer, *c_pointer);
            while (getc(choice_of_how_to_read) != '\n')
                    ;
        }
        else
        num_of_input += 1;
    }
    return num_of_input;
}

int CompareDoubleNumbers(double number1, double number2)
{
    if (fabs(number1 - number2) < isZERO)
        return 1;
    else
        return 0;

}

/*
int how_to_read_coeffs(double* a_ptr, double* b_ptr, double* c_ptr, int where_to_read_from, FILE* how_to_read)
{
    if (where_to_read_from == 1)
    {
        printf ("# Введите коэффициенты уравнения\n");
        while (getchar() != '\n')
            ;
        Read (a_ptr, b_ptr, c_ptr, where_to_read_from, how_to_read);
        return 1;
    }
    else
    {
        char file_name[40] = {};
        printf("Введите название файла с расширением:\n");
        scanf("%s", file_name);
        while ((how_to_read = fopen(file_name,"r")) == NULL)
        {
            printf("Имя файла введено неверно, повторите попытку:\n");
            while (getchar() != '\n')
                ;
            scanf("%s", file_name);
        }
        Read (a_ptr, b_ptr, c_ptr, where_to_read_from, how_to_read);
        return 2;

    }

}
   */
int Return_the_answer(int nROOTS, double x1, double x2)
{
    switch (nROOTS)
    {
    case ZERO: printf ("Решений нет");
            break;
    case ONE: printf ("x = %lg", x1);
            break;
    case TWO: printf ("x1 = %lg, x2 = %lg", x1, x2);
            break;
    case INF_ROOTS: printf("Бесконечное число корней");
            break;
    default: printf("main(): ERROR: nROOTS = %d\n", nROOTS);
            return 1;
    }
    return 3;

}

int get_file_name(char* file_name)
{
    printf("Введите название файла с расширением:\n");
    scanf("%s", file_name);
    while ((fopen(file_name,"r")) == NULL)
        {
            printf("Имя файла введено неверно, повторите попытку:\n");
            while (getchar() != '\n')
                ;
            scanf("%s", file_name);
        }
    return 1;
}


int get_type_of_the_input_from_user(int* where_to_read_from)
{

    scanf("%d", where_to_read_from);

    while(*where_to_read_from != FROM_FILE && *where_to_read_from != FROM_CONSOLE)
    {
        printf("Введена неверная команда\nПопробуйте заново\n");
        while (getchar() != '\n')
                ;
        scanf("%d", where_to_read_from);
    }

    return 1;
}

FILE* choose_how_to_read(int where_to_read_from, char* file_name, FILE* choice_of_how_to_read)
{
    if (where_to_read_from == FROM_FILE)
    {
        get_file_name(file_name);
        choice_of_how_to_read = fopen(file_name,"r");
    }
    else
    {
        choice_of_how_to_read = stdin;
        printf("Введите коэффициенты уравнения\n");
    }
    return choice_of_how_to_read;
}
