#include "assignment1.h"

void denseMatrixMult(int ** A, int ** B, int *** resultMatrix, int n)
{
	if (n == 1)
	{
        initMatrix(resultMatrix, n);
		*resultMatrix[0][0] = A[0][0] * B[0][0];
	}

	else
	{
		int **m0, **m1, **m2, **m3, **m4, **m5, **m6;
        int **zero;
        initMatrix(&zero, n);
        int **c00, **c01, **c10, **c11;
        int **temp1, **temp2;
        
		denseMatrixMult(temp1 = sum(A, A, 0, 0, n/2, n/2, n/2), temp2 = sum(B, B, 0, 0, n/2, n/2, n/2), &m0, n/2);
        freeMatrix(n/2, temp1);
        freeMatrix(n/2, temp2);
        
        denseMatrixMult(temp1 = sum(A, A, n/2, 0, n/2, n/2, n/2), temp2 = sum(B, zero, 0, 0, 0, 0, n/2), &m1, n/2);
        freeMatrix(n/2, temp1);
        freeMatrix(n/2, temp2);
        
        denseMatrixMult(temp1 = sum(A, zero, 0, 0, 0, 0, n/2), temp2 = sub(B, B, 0, n/2, n/2, n/2, n/2), &m2, n/2);
        freeMatrix(n/2, temp1);
        freeMatrix(n/2, temp2);
        
        denseMatrixMult(temp1 = sum(A, zero, n/2, n/2, 0, 0, n/2), temp2 = sub(B, B, n/2, 0, 0, 0, n/2), &m3, n/2);
        freeMatrix(n/2, temp1);
        freeMatrix(n/2, temp2);
        
        denseMatrixMult(temp1 = sum(A, A, 0, 0, 0, n/2, n/2), temp2 = sum(B, zero, n/2, n/2, 0, 0, n/2), &m4, n/2);
        freeMatrix(n/2, temp1);
        freeMatrix(n/2, temp2);
        
        denseMatrixMult(temp1 = sub(A, A, n/2, 0, 0, 0, n/2), temp2 = sum(B, B, 0, 0, 0, n/2, n/2), &m5, n/2);
        freeMatrix(n/2, temp1);
        freeMatrix(n/2, temp2);
        
        denseMatrixMult(temp1 = sub(A, A, 0, n/2, n/2, n/2, n/2), temp2 = sum(B, B, n/2, 0, n/2, n/2, n/2), &m6, n/2);
        freeMatrix(n/2, temp1);
        freeMatrix(n/2, temp2);

        c00 = sum(temp2 = sub(temp1 = sum(m0, m3, 0, 0, 0, 0, n/2), m4, 0, 0, 0, 0, n/2), m6, 0, 0, 0, 0, n/2);
        freeMatrix(n/2, temp1);
        freeMatrix(n/2, temp2);
        
        c01 = sum(m2, m4, 0, 0, 0, 0, n/2);
        c10 = sum(m1, m3, 0, 0, 0, 0, n/2);
        
        c11 = sum(temp2 = sum(temp1 = sub(m0, m1, 0, 0, 0, 0, n/2), m2, 0, 0, 0, 0, n/2), m5, 0, 0, 0, 0, n/2);
        freeMatrix(n/2, temp1);
        freeMatrix(n/2, temp2);
        
        freeMatrix(n/2, m0);
        freeMatrix(n/2, m1);
        freeMatrix(n/2, m2);
        freeMatrix(n/2, m3);
        freeMatrix(n/2, m4);
        freeMatrix(n/2, m5);
        freeMatrix(n/2, m6);

        int i, j;
        int **matrix;
        initMatrix(&matrix, n);

        for (i = 0; i < n/2; i++)
        {
            for (j = 0; j < n/2; j++)
            {
                matrix[i][j] = c00[i][j];
                matrix[i][j+n/2] = c01[i][j];
                matrix[i+n/2][j] = c10[i][j];
                matrix[i+n/2][j+n/2] = c11[i][j];
            }
        }
        *resultMatrix = matrix;        
         
        freeMatrix(n, zero);
        
        freeMatrix(n/2, c00);
        freeMatrix(n/2, c01);
        freeMatrix(n/2, c10);
        freeMatrix(n/2, c11);
        
	}
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
            //printf("%d%d %d\n", i, j, matrix[i][j]);
            //matrix[i][j] = i+j;
            //printf("%d%d %d\n", i, j, matrix[i][j]);
        }
    }
    fclose(fp);

    //printMatrix(MATSIZE, matrix);
    return matrix;
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

    //freeMatrix(n, A);
}
