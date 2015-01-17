#include "lab2.h"

void initMatrix(int ***mat,int n)
{
    int i, j;
    int **matrix;
    matrix = (int **)malloc(sizeof(int*)*(unsigned long)n);
    
    if (matrix!=NULL)
    {
        for (i = 0; i < n; i++)
        {
            matrix[i] = (int*)malloc(sizeof(int)*(unsigned long)n);
            for (j = 0; j < n; j++)
            {
                matrix[i][j] = 0;
                //printf("%d\n", matrix[i][j] = 0);
            }
                
        }
    }
    *mat = matrix;
    //printf("%p\n", &matrix[0][0]);
    //printf("%p\n", mat);
}

void freeMatrix(int n, int ** matrix)
{
    int i;
    for (i = 0; i < n; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}

int **readMatrix(char * filename)
{
    int **matrix;
    initMatrix(&matrix,MATSIZE);
    //matrix = *p;
    //printf("%p\n", &matrix[0][0]);
    FILE *fp=fopen(filename, "r");
    int i = 0, j = 0;
    for (i = 0; i < MATSIZE; i++)
    {
        for (j = 0; j < MATSIZE; j++)
        {
            fscanf(fp,"%d",&matrix[i][j]);
            //matrix[i][j] = i+j;
            //printf("%d%d %d\n", i, j, matrix[i][j]);
        }
    }
    fclose(fp);
    
    //printMatrix(MATSIZE, matrix);
    return matrix;
}

void printMatrix(int n, int ** A)
{
    int i = 0, j = 0;
    
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", A[i][j]);
        }
        
        printf("\n");
    }
    
    freeMatrix(n, A);
}

int **sum(int ** A, int ** B, int x1, int y1, int x2, int y2, int n)
{
    int **matrix;
    int i = 0, j = 0, rowA = x1, colA = y1, rowB = x2, colB = y2;
    initMatrix(&matrix,n);
    for (i = 0; i < n; i++)
    {
        rowA = x1 + i, rowB = x2 + i;
        for (j = 0; j <n; j++)
        {
            colA = y1 + j;
            colB = y2 + j;
            matrix[i][j] = A[rowA][colA] + B[rowB][colB];
        }
    }
    
    return matrix;
}

int **sub(int **A, int **B, int x1, int y1, int x2, int y2, int n)
{
    int **matrix;
    int i = 0, j = 0, rowA = x1, colA = y1, rowB = x2, colB = y2;
    initMatrix(&matrix,n);
    for (i = 0; i < n; i++)
    {
        rowA = x1 + i, rowB = x2 + i;
        for (j = 0; j <n; j++)
        {
            colA = y1 + j;
            colB = y2 + j;
            matrix[i][j] = A[rowA][colA] - B[rowB][colB];
        }
    }
    
    return matrix;
}
