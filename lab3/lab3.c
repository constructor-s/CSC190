#include "lab3.h"

struct functionCall * createStructArray(int n)
{
    return (struct functionCall *)malloc(n*sizeof(struct functionCall));
}

void assignValues(struct functionCall * array, int index, int currentValueRes, int recursiveCallNumber, int exp )
{
    array[index].currentValueRes = currentValueRes;
    array[index].recursiveCallNumber = recursiveCallNumber;
    array[index].exp = exp;
}

void initArray(struct functionCall * array, int n)
{
    int i;
    for (i=0; i<n; i++)
    {
        assignValues(array, i, 0, 0, 0);
    }
}

void recordRecursiveCalls(struct functionCall * array, int exp, int base)
{
    int i;
    for (i=0; i<exp+1; i++)
    {
        if (i == 0) array[exp-i].currentValueRes = 1;
        else array[exp-i].currentValueRes = array[exp-i+1].currentValueRes * base;
        array[i].recursiveCallNumber = i+1;
        array[i].exp = exp-i;
    }
}

void printArray(struct functionCall * array, int n)
{
    int i;
    for (i=0; i<n; i++)
    {
        printf("%d ", array[i].currentValueRes);
        printf("%d ", array[i].recursiveCallNumber);
        printf("%d \n", array[i].exp);
    }
}

void freeArray(struct functionCall * array)
{
    free(array);
}
