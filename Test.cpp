struct TestData
{
    double a, b, c;
    double x1, x2;
    int nROOTS;
    const char Name[NAME_SIZE];
};

/*int TestOne (double a, double b, double c, double x1ref, double x2ref, int nROOTSref)
{
    double x1 = 0, x2 = 0;

    int nROOTS = SolveSqrEq (a, b, c, &x1, &x2);

    if ((x1 != x1ref || x2 != x2ref) && (x1 != x2ref || x2 != x1ref) || nROOTS != nROOTSref)
    {
        printf("FAILED: x1=%lg, x2=%lg, nROOTS=%d, expected: x1ref=%lg, x2ref=%lg, nROOTSref=%d\n", x1, x2, nROOTS, x1ref, x2ref, nROOTSref);
        return 0;
    }
    else
    {
        printf("Test OK\n");
        return 1;
    }
}

int TestAll ()
{
    int nOk = 0;
    nOk += TestOne(1, 0, -4, -2, 2, 2);
    nOk += TestOne(0, 0, 0, 0, 0, INF_ROOTS);
    nOk += TestOne(0, 0, 3, 0, 0, 0);
    nOk += TestOne(1, -5, 4, 1, 4, 2);
} */

TestData data1 = {0, 0, 0, 0, 0, INF_ROOTS, "InfTest"};
/*
void TestOne(TestData data)
{
    double x1 = 0, x2 = 0;
    int nROOTS = SolveSqrEq (data.a, data.b, data.c, &x1, &x2);
    if ((x1 != data.x1 || x2 != data.x2) && (x1 != data.x1 || x2 != data.x2) || nROOTS != data.nROOTS)
    {
        printf("FAILED: x1=%lg, x2=%lg, nROOTS=%d, expected: x1ref=%lg, x2ref=%lg, nROOTSref=%d\n", x1, x2, nROOTS, data.x1, data.x2, data.nROOTS);
        return;
    }
    else
    {
        printf("Test OK\n");
    }
}
*/

TestData allData[nTESTS] = {{.a = 0, .b = 0, .c = 0, .x1 = 0, .x2 = 0, .nROOTS = INF_ROOTS, "zero_arguments"},
                            {.a = 1, .b = 0, .c = -4, .x1 = -2, .x2 = 2, .nROOTS = 2, "Basic_test1"},
                            {.a = 0, .b = 0, .c = 3, .x1 = 0, .x2 = 0, .nROOTS = 0, "zero_roots"},
                            {.a = 1, .b = -5, .c = 4, .x1 = 1, .x2 = 4, .nROOTS = 2, "Basic_test2"}};

/*
void TestOne(TestData* data)
{
    printf("%lg %lg %lg %lg %lg",&(data -> a),&(data -> b),&(data -> c), data -> Name, &(data -> Name[0] ));
    double x1 = 0, x2 = 0;
    int nROOTS = SolveSqrEq (data -> a, data -> b, data -> c, &x1, &x2);
    if ((x1 != data -> x1 || x2 != data -> x2) && (x1 != data -> x2 || x2 != data -> x1) || nROOTS != data -> nROOTS)
    {
        printf("%s: FAILED: x1=%lg, x2=%lg, nROOTS=%d, expected: x1ref=%lg, x2ref=%lg, nROOTSref=%d\n", data -> Name, x1, x2, nROOTS, data -> x1, data -> x2, data -> nROOTS);
        return;
    }
    else
    {
        printf("%s: Test OK\n", data -> Name);
    }
}
*/
void TestOne(TestData* data)
{
    //printf("%lg %lg %lg %lg %lg",&(data -> a),&(data -> b),&(data -> c), data -> Name, &(data -> Name[0] ));
    double x1 = 0, x2 = 0;
    int nROOTS = SolveSqrEq (data -> a, data -> b, data -> c, &x1, &x2);
    if (((!(CompareDoubleNumbers(x1, data -> x1))) || (!(CompareDoubleNumbers(x2, data -> x2)))) && ((!(CompareDoubleNumbers(x1, data -> x2)) || !(CompareDoubleNumbers(x2, data -> x1)))) || nROOTS != data -> nROOTS)
    {
        printf("%s: FAILED: x1=%lg, x2=%lg, nROOTS=%d, expected: x1ref=%lg, x2ref=%lg, nROOTSref=%d\n", data -> Name, x1, x2, nROOTS, data -> x1, data -> x2, data -> nROOTS);
        return;
    }
    else
    {
        printf("%s: Test OK\n", data -> Name);
    }
}
