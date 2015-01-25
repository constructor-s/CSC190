/*
 * Include necessary libraries (stdio.h and stdlib.h)
 */
#include <stdio.h>
#include <stdlib.h>

#define MATSIZE		5

void freeMatrix(int n, int ** matrix);
void printMatrix(int n, int ** A);
int readMatrixSize(char * filename);
int **readMatrix(char * filename);
void initMatrix(int ***mat, int n);
int **sum(int ** A, int ** B, int x1, int y1, int x2, int y2, int n);
int **sub(int ** A, int ** B, int x1, int y1, int x2, int y2, int n);
