#include "TXlib.h"
#include "FUNCS.h"
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <assert.h>                                    //fix TestOne func using switch
                                                       //static
                                                       //scanf 40 symbols only
                                                       //fix long lines make em readable
                                                       //enum
                                  // successful scanfs

int main(int argc,const char* argv[])
{
    TestData allData[nTESTS] = {{.a = 0, .b = 0,  .c = 0,  .x1 = 0,  .x2 = 0, .nROOTS = INF_ROOTS, "zero_arguments"},     // fix codestyle
                                {.a = 1, .b = 0,  .c = -4, .x1 = -2, .x2 = 2, .nROOTS = 2,         "Basic_test1"},
                                {.a = 0, .b = 0,  .c = 3,  .x1 = 0,  .x2 = 0, .nROOTS = 0,         "zero_roots"},
                                {.a = 1, .b = -5, .c = 4,  .x1 = 0,  .x2 = 4, .nROOTS = 2,         "Basic_test2"}};
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

}
