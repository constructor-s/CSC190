#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node * next;
};

void insertNode(int d, struct Node ** lPtr);
void deleteNode(int d, struct Node ** lPtr);
void printList(struct Node * L);

struct Node ** createTable(int buckets);
int findHash(int key, int buckets);
void insertTable(int key, int buckets, struct Node ** tablePtr);
void freeTable(struct Node ** tablePtr, int base);



