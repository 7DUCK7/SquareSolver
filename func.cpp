#include <math.h>
int FloatComparison (double a)
{
    if (fabs(a) <= isZERO)
        return 1;
    else
        return 0;
}

int SolveLinearEq (double b, double c, double* x1)
{
    if (FloatComparison(b))
    {
        return (c == 0)? INF_ROOTS : 0;
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
        printf("¬ведены некорректные указатели дл€ корней уравнени€\n");
    }
    else
    {
        if (FloatComparison(a))
        {
            //SolveLinearEq (b, c, x1);
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
                if (FloatComparison(d))
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

int ReadManual (double* a_pointer, double* b_pointer, double* c_pointer)
{
    // check correctness +
    printf ("# ¬ведите коэффициенты уравнени€\n");
    while (fscanf (stdin, "%lg %lg %lg", a_pointer, b_pointer, c_pointer) != 3)    // correctness check
    {
        while (getchar() != '\n')
            ;
        printf("¬ведены неверные данные (a= %lg b= %lg c= %lg)\n", *a_pointer, *b_pointer, *c_pointer);
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
        printf("¬ведены неверные данные (a= %lg b= %lg c= %lg)\n", *a_pointer, *b_pointer, *c_pointer);
    }

    fclose(file);
    return 1;
}

