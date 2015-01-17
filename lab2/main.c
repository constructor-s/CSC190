#include "lab2.h"

void p1(void)
{
    int **matrix;
    initMatrix(&matrix,MATSIZE);
    printMatrix(MATSIZE,matrix);
}

void p2(void)
{
    int ** matrix1=readMatrix("matrix1.txt");
    printMatrix(MATSIZE,matrix1);
}

void p3a(void)
{
    int ** matrix1=readMatrix("matrix1.txt");
    int ** matrix2=readMatrix("matrix2.txt");
    int ** sumMatrix = sum(matrix1, matrix2, 1, 1, 0, 1, 3);
    printMatrix(MATSIZE,matrix1);
    printMatrix(MATSIZE,matrix2);
    printMatrix(3,sumMatrix);
}

void p3b(void)
{
    int ** matrix1=readMatrix("matrix1.txt");
    int ** matrix2=readMatrix("matrix2.txt");
    int ** subMatrix = sub(matrix1, matrix2, 1, 1, 0, 1, 3);
    printMatrix(MATSIZE,matrix1);
    printMatrix(MATSIZE,matrix2);
    printMatrix(3,subMatrix);
}

int main( int argc, char *argv[] )
{
    if( argc < 2 )
   	{
        printf("Expecting at least one argument. Please try again\n");
   	}
    else if(argc==2)
    {
        if(atoi(argv[1])==3)
        {
            printf("Expecting two arguments for this part. Please try again.\n");
        }
        else
        {
            if(atoi(argv[1])==1)
            {
                p1();
            }
            else if(atoi(argv[1])==2)
            {
                p2();
            }
            else
            {
                printf("Incorrect argument supplied.\n");
            }
        }
    }
    else if(argc==3)
    {
        if(atoi(argv[1])!=3)
        {
            printf("Expecting two arguments only for Part 3. Please try again.\n");
        }
        else
        {
            if(atoi(argv[2])==1)
            {
                p3a();
            }
            else if(atoi(argv[2])==2)
            {
                p3b();
            }
        }
    }
    else
    {
        printf("The argument supplied is %s\n", argv[1]);
    }
    return EXIT_SUCCESS;
}
