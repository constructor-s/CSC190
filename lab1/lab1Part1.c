#include "lab1.h"

void printMatrix(int matrix[MATSIZE][MATSIZE])
{
    int i = 0, j = 0;

    for (i = 0; i < MATSIZE; i++)
    {
        for (j = 0; j < MATSIZE; j++)
        {
            printf("%d ", matrix[i][j]);
        }

        printf("\n");
    }
}
