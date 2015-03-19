#include <stdio.h>
#include <stdlib.h>
#include "lab6.h"

struct Heap * initMinHeap()
{
    struct Heap * h=(struct Heap *)malloc(sizeof(struct Heap));
    h->count=0;
    return h;
}

void insertMinHeap(struct Heap * h, struct Data d)
{
    int childIndex=++(h->count);
    int parentIndex=childIndex/2;
    while (parentIndex>0) {
        if (h->heapArray[parentIndex].data.data > d.data) {
            h->heapArray[childIndex]=h->heapArray[parentIndex];
            childIndex=parentIndex;
            parentIndex=parentIndex/2;
        }
        else{
            h->heapArray[childIndex].data = d;
            return;
        }
    }
    h->heapArray[childIndex].data = d;
}

struct Data removeMinHeap(struct Heap * h)
{
    struct Data returnData = h->heapArray[1].data;
    struct Data item = h->heapArray[h->count].data;
    h->count--;
    int parentIndex=1;
    int childIndex=2*parentIndex;
    
    while (childIndex<=h->count) {
        if(childIndex<h->count)
        {
            if(h->heapArray[childIndex].data.data > h->heapArray[childIndex+1].data.data){
                childIndex++;
            }
        }
        if (item.data > h->heapArray[childIndex].data.data) {
            h->heapArray[parentIndex]=h->heapArray[childIndex];
            parentIndex=childIndex;
            childIndex=childIndex*2;
        }
        else{
            break;
        }
    }
    h->heapArray[parentIndex].data = item;
    return returnData;
}

void freeMinHeap(struct Heap * h)
{
    free(h);
}