#include "TXlib.h"
#include <math.h>
#include <stdio.h>
#include "FUNCS.h"
#include "func.cpp"
#include "test.cpp"

int main()
{
    printf ("# Программа для решения квадратного уравнения\n");

    for(int i = 0; i < nTests; i++)
    {
        TestOne(&allData[i]);
    }

    int r = 2;
    double a = 0, b = 0, c = 0;
    // check correctness +

    printf("Выберете способ которым хотите ввести данные:\n");
    printf("1 - вручную\n");
    printf("Любая другой символ - через файл\n");
    scanf("%d", &r);
    if (r == 1)
        ReadManual (&a, &b, &c);
    else
        ReadFile (&a, &b, &c);

    double x1 = 0, x2 = 0;
    int nROOTS = SolveSqrEq (a, b, c, &x1, &x2);

    switch (nROOTS)
    {
    case 0: printf ("Решений нет");
            break;
    case 1: printf ("x = %lg", x1);
            break;
    case 2: printf ("x1 = %lg, x2 = %lg", x1, x2);
            break;
    case INF_ROOTS: printf("Бесконечное число корней");       // const for inf
            break;
    default: printf("main(): ERROR: nROOTS = %d\n", nROOTS);
            return 1;
    }
}
