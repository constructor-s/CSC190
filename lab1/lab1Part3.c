#include "lab1.h"

void add(int matrix1[MATSIZE][MATSIZE], int matrix2[MATSIZE][MATSIZE] )
{
    int res_matrix[MATSIZE][MATSIZE];
    int i = 0, j = 0;
    for (i = 0; i < MATSIZE; i++)
    {
        for (j = 0; j < MATSIZE; j++)
        {
            res_matrix[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    printMatrix(res_matrix);
}

void sub(int matrix1[MATSIZE][MATSIZE], int matrix2[MATSIZE][MATSIZE] )
{
    int res_matrix[MATSIZE][MATSIZE];
    int i = 0, j = 0;
    for (i = 0; i < MATSIZE; i++)
    {
        for (j = 0; j < MATSIZE; j++)
        {
            res_matrix[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
    printMatrix(res_matrix);
}

void mult(int matrix1[MATSIZE][MATSIZE], int matrix2[MATSIZE][MATSIZE] )
{
    int res_matrix[MATSIZE][MATSIZE];
    int i = 0, j = 0, k = 0;
    for (i = 0; i < MATSIZE; i++)
    {
        for (j = 0; j < MATSIZE; j++)
        {
            res_matrix[i][j] = 0;
            for (k = 0; k < MATSIZE; k++)
                res_matrix[i][j] += matrix1[i][k] * matrix2[k][j];
        }
    }
    printMatrix(res_matrix);
}

void matrixOperation(char filename1[STRINGSIZE], char filename2[STRINGSIZE], int operation)
{
    int matrix1[MATSIZE][MATSIZE];
    int matrix2[MATSIZE][MATSIZE];
    int i = 0, j = 0;

    FILE *fp1=fopen(filename1, "r");
    for (i = 0; i < MATSIZE; i++)
    {
        for (j = 0; j < MATSIZE; j++)
        {
            fscanf(fp1,"%d",&matrix1[i][j]);
        }
    }
    fclose(fp1);

    FILE *fp2=fopen(filename2, "r");
    for (i = 0; i < MATSIZE; i++)
    {
        for (j = 0; j < MATSIZE; j++)
        {
            fscanf(fp2,"%d",&matrix2[i][j]);
        }
    }
    fclose(fp2);

    switch(operation)
    {
        case ADD:
            add(matrix1, matrix2);
            break;
        case SUBTRACT:
            sub(matrix1, matrix2);
            break;
        case MULTIPLY:
            mult(matrix1, matrix2);
            break;
    }
}
