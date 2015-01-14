#include <stdio.h>
#include <stdlib.h>
#include "math.h"
/*
 * Include definitions of MATSIZE, STRINGSIZE and enum set containing constants ADD, SUBTRACT and MULTIPLY here
 */
 #define MATSIZE 5
 #define STRINGSIZE 15
void printMatrix(int matrix[MATSIZE][MATSIZE]);
void readMatrix(char filename[MATSIZE]);
void add(int matrix1[MATSIZE][MATSIZE], int matrix2[MATSIZE][MATSIZE]);
void sub(int matrix1[MATSIZE][MATSIZE], int matrix2[MATSIZE][MATSIZE]);
void mult(int matrix1[MATSIZE][MATSIZE], int matrix2[MATSIZE][MATSIZE]);
void matrixOperation(char filename1[STRINGSIZE], char filename2[STRINGSIZE], int operation);
void findDeterminant(char filename[STRINGSIZE]);
int determinant(int n, int matrix[n][n]);

enum matrixOperations {ADD, SUBTRACT, MULTIPLY};
