#include "lab1.h"

void p1(void)
{
	int matrix[MATSIZE][MATSIZE]={{1, 2, 3, 4, 5},{1, 2, 3, 4, 5},{1, 2, 3, 4, 5},{1, 2, 3, 4, 5},{1, 2, 3, 4, 5}};
	printMatrix(matrix);
}

void p2(void)
{
	readMatrix("matrix1.txt");
	readMatrix("matrix2.txt");
}

void p3(int operation)
{
	matrixOperation("matrix1.txt", "matrix2.txt", operation);
}

void p4(void)
{
	findDeterminant("matrix2.txt");
	findDeterminant("matrix1.txt");

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
			else if(atoi(argv[1])==4)
			{
				p4();
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
                        p3(atoi(argv[2]));
                }
	}
	else
	{
		printf("The argument supplied is %s\n", argv[1]);
	}
}
