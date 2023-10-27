#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int main()
{
    time_t t;
    int square[3][3] = {{1,0,0},{0,0,0},{0,0,0}};
    long counter = 0;
    bool test = false;

    bool testRows = true;
    bool testColumns = true;
    bool testDiagnals = true;

    // Iniit random number generator
    srand((unsigned) time(&t));

    while (!(test))
    {
        //reseting test variables
        testRows = true;
        testColumns = true;
        testDiagnals = true;

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                square[i][j] = rand() % 9 + 1;
            }
        }

        counter++;

        //creating sum all rows, diagnals, and columns must be equal to.
        int sum = square[0][0] + square[0][1] + square[0][2];

        //testing rows
        for (int i = 1; i < 3; i++)
        {
            if (square[i][0] + square[i][1] + square[i][0] != sum)
            {
                testRows = false;
            }
        }

        //testing columns
        for (int i = 0; i < 3; i++)
        {
            if (square[0][i] + square[1][i] + square[2][i] != sum)
            {
                testColumns = false;
            }
        }

        //testing diagonals
        if (square[0][0] + square[1][1] + square[2][2] != sum || square[0][2] + square[1][1] + square[2][0] != sum)
            testDiagnals = false;

        //if all three are still true, thne it is a valid Lo Shu Square
        if (testDiagnals && testColumns && testRows)
        {
            test = true;
        }
    }

    printf("There were %ld", counter);
    printf( " generated squares.\n");

    printf("This was the valid generated square: \n");
    printf("[");
    for (int i = 0; i < 3; i++)
    {   
        printf(" %d",square[0][i]);
    }
    printf(" ]\n"); //printing row 1

    printf("[");
    for (int i = 0; i < 3; i++)
    {   
        printf(" %d",square[1][i]);
    }
    printf(" ]\n"); //printing row 2

    printf("[");
    for (int i = 0; i < 3; i++)
    {   
        printf(" %d",square[2][i]);
    }
    printf(" ]\n"); //printing row 3



    return 0;
}