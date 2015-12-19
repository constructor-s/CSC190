#include <stdio.h>
#include <stdlib.h>

#define MaxHeapSize 10
#define MaxQueueSize 10

struct qNode{
    char data;
};

struct Data{
    int data;
};

struct Node{
    struct Data data;
};

struct Queue{
    int currSize;
    int front;
    int rear;
    struct Node queueArray[MaxQueueSize];
};

struct Heap{
    int count;
    struct Node heapArray[MaxHeapSize];
};

struct Heap * initMinHeap();
void insertMinHeap(struct Heap * h, struct Data d);
struct Data removeMinHeap(struct Heap * h);
void freeMinHeap(struct Heap * h);

void initQueue(struct Queue ** qPtr);
int isEmpty(struct Queue * Q);
void enqueue(struct Queue * Q, struct Data d);
void dequeue(struct Queue * Q, struct Data *d);
void freeQueue(struct Queue * Q);
