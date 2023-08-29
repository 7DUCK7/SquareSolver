#include "TXlib.h"
#include "FUNCS.h"
#include <stdio.h>
#include <math.h>

void TestOne(TestData* data)
{
    double x1 = 0, x2 = 0;
    int nROOTS = SolveSqrEq (data -> a, data -> b, data -> c, &x1, &x2);
    if (((!(CompareDoubleNumbers(x1, data -> x1))) ||
            (!(CompareDoubleNumbers(x2, data -> x2)))) &&
                ((!(CompareDoubleNumbers(x1, data -> x2)) || !(CompareDoubleNumbers(x2, data -> x1)))) ||
                    nROOTS != data -> nROOTS)
    {
        printf("В ходе тестирования %s получено:\n", data -> Name);
        Print_the_answer(nROOTS, x1, x2);
        printf("Ожидалось:\n");
        Print_the_answer(data -> nROOTS, data -> x1, data -> x2);

    /*
        printf("%s: FAILED: x1=%lg, x2=%lg, nROOTS=%d, expected: x1ref=%lg, x2ref=%lg, nROOTSref=%d\n", data -> Name, x1, x2, nROOTS, data -> x1, data -> x2, data -> nROOTS);
        return; */
    }
    else
    {
        printf("%s: Test OK\n", data -> Name);
    }
}
