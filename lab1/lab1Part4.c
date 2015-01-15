#include "lab1.h"

void findDeterminant(char filename[STRINGSIZE])
{
	int det=0, i = 0, j = 0;
	int matrix[MATSIZE][MATSIZE];

	FILE *fp=fopen(filename, "r");
    for (i = 0; i < MATSIZE; i++)
    {
        for (j = 0; j < MATSIZE; j++)
        {
            fscanf(fp,"%d",&matrix[i][j]);
        }
    }
    fclose(fp);

    det = determinant(MATSIZE, matrix);

	printf("The determinant of the matrix in %s is %d\n", filename, det);
}

int determinant(int n, int matrix[n][n])
{

    int det, i, j, k, k1;
    int reduced[n-1][n-1];
    if (n==1)
    {
        det = matrix[0][0];
    }
    else if (n == 2)
    {
        det = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix [1][0];
    }
    else
    {
        det = 0;
        for (i = 0; i < n; i++)
        {
            for (j = 1; j < n; j++)
            {
                k1 = 0;
                for (k = 0; k < n; k++)
                {
                    if (k == i) continue;
                    reduced[j-1][k1] = matrix[j][k];
                    k1++;
                }
            }
            det += (int)pow(-1, i+2) * matrix[0][i] * determinant(n-1, reduced);
        }
    }
    return det;
}
