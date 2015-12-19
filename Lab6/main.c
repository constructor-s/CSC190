#include "lab6.h"

void p1(void)
{
    int i,n;
    struct Data d[MaxHeapSize-1];
    struct Data tempD;
    int A[]={5,2,8,6,1,9,21,42,0};
    struct Queue * pQ;
    struct Heap * mH=initMinHeap();
    initQueue(&pQ);

    for (i=0; i<MaxHeapSize-1; i++) {
        d[i].data=A[i];
    }
    for (i=0; i<MaxHeapSize-1; i++) {
        insertMinHeap(mH,d[i]);
    }
    for (i=0; i<MaxHeapSize-1; i++) {
        tempD=removeMinHeap(mH);
        enqueue(pQ, tempD);
    }
    printf("Elements in the priority queue are:");
    while (isEmpty(pQ)!=1) {
        dequeue(pQ, &tempD);
        printf(" %d ", tempD.data);
    }
    printf("\n");
    freeQueue(pQ);
    freeMinHeap(mH);
}

int main( int argc, char *argv[] ){
    if( argc < 2 ){
        printf("Expecting at least one argument. Please try again\n");
   	}
    else if(argc==2){
        if(atoi(argv[1])==1){
            p1();
        }
        else{
            printf("Incorrect argument supplied.\n");
        }
    }
    else
    {
        printf("Expecting only one argument\n");
    }
}
