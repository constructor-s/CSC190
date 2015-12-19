#include "lab4.h"

void p1(void)
{
    struct Node * L=NULL;
    insertNode(3, &L);
    printList(L);
    insertNode(1, &L);
    printList(L);
    insertNode(5, &L);
    printList(L);
    insertNode(5, &L);
    printList(L);
    insertNode(0, &L);
    printList(L);
    insertNode(4, &L);
    printList(L);
    
    deleteNode(5, &L);
    printList(L);
    deleteNode(3, &L);
    printList(L);
    deleteNode(1, &L);
    printList(L);
    deleteNode(5, &L);
    printList(L);
    deleteNode(0, &L);
    printList(L);
    deleteNode(4, &L);
    printList(L);
}

void p2(void)
{
    int i, sizeArray=11, buckets=3;
    struct Node ** tablePtr = createTable(buckets);
    int array[]={8,10,9,1,5,0,6,4,3,2,7};
    for (i=0; i<sizeArray; i++) {
        insertTable(array[i], buckets, tablePtr);
    }
    for (i=0; i<buckets; i++) {
        printList(tablePtr[i]);
    }
    freeTable(tablePtr, buckets);
}

int main( int argc, char *argv[] ){
    if( argc < 2 ){
        printf("Expecting at least one argument. Please try again\n");
   	}
    else if(argc==2){
        if(atoi(argv[1])==1){
            p1();
        }
        else if(atoi(argv[1])==2){
            p2();
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
