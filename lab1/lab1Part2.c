#include "lab1.h"

void readMatrix(char fileName[STRINGSIZE])
{
    FILE *fp=fopen(fileName, "r");
    int matrix[MATSIZE][MATSIZE];
    int i = 0, j = 0;
    for (i = 0; i < MATSIZE; i++)
    {
        for (j = 0; j < MATSIZE; j++)
        {
            fscanf(fp,"%d",&matrix[i][j]);
        }
    }
    fclose(fp);

    printMatrix(matrix);
}
