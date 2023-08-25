#include <math.h>

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

int Read (double* a_pointer, double* b_pointer, double* c_pointer, FILE* how_to_read_ptr)
{
    while (fscanf (how_to_read_ptr, "%lg %lg %lg", a_pointer, b_pointer, c_pointer) != 3)    // correctness check
    {
        while (getchar() != '\n')
            ;
        printf("Введены неверные данные (a=%lg b=%lg c=%lg). Повторите попытку:\n", *a_pointer, *b_pointer, *c_pointer);
    }
    return 1;
}

int CompareDoubleNumbers(double number1, double number2)
{
    if (fabs(number1 - number2) < isZERO)
        return 1;
    else
        return 0;

}


int how_to_read_coeffs(double* a_ptr, double* b_ptr, double* c_ptr, int where_to_read_from, FILE* how_to_read)
{
    if (where_to_read_from == 1)
    {
        printf ("# Введите коэффициенты уравнения\n");
        while (getchar() != '\n')
            ;
        Read (a_ptr, b_ptr, c_ptr, how_to_read);
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
        Read (a_ptr, b_ptr, c_ptr, how_to_read);
        return 2;

    }

}
