#include "TXlib.h"
#include "FUNCS.h"
#include <stdio.h>
#include "func.cpp"
#include "test.cpp"
int main()
{
    printf ("# ��������� ��� ������� ����������� ���������\n");

    for(int i = 0; i < nTESTS; i++)
    {
        TestOne(&allData[i]);
    }

    int where_to_read_from = 0;
    double a = 0, b = 0, c = 0;

    printf("�������� ������ ������� ������ ������ ������:\n");
    printf("1 - �������\n");
    printf("����� ������ ������ - ����� ����\n");

    FILE* how_to_read = stdin;
    scanf("%d", &where_to_read_from);

    how_to_read_coeffs(&a, &b, &c, where_to_read_from, how_to_read);

    double x1 = 0, x2 = 0;
    int nROOTS = SolveSqrEq (a, b, c, &x1, &x2);

    switch (nROOTS)
    {
    case ZERO: printf ("������� ���");
            break;
    case ONE: printf ("x = %lg", x1);
            break;
    case TWO: printf ("x1 = %lg, x2 = %lg", x1, x2);
            break;
    case INF_ROOTS: printf("����������� ����� ������");
            break;
    default: printf("main(): ERROR: nROOTS = %d\n", nROOTS);
            return 1;
    }
}
