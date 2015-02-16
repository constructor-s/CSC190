#include "lab4.h"

void insertNode(int d, struct Node ** lPtr)
{
    struct Node * newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node * curNode = *lPtr;
    struct Node * prevNode = NULL;
    newNode->data=d;
    if (*lPtr == NULL)
    {
        newNode->next = *lPtr;
        *lPtr = newNode;
    }
    else
    {
        while (curNode->data < d)
        {
            prevNode = curNode;
            curNode = curNode->next;
            if (curNode == NULL) break;
        }
        newNode->next = curNode;
        if (prevNode != NULL)
        {
            prevNode->next = newNode;
        }
        else
        {
            *lPtr = newNode;
        }
    }
}

void deleteNode(int d, struct Node ** lPtr)
{
    struct Node * curNode = *lPtr;
    struct Node * prevNode = NULL;
    while (curNode != NULL)
    {
        if (curNode->data == d)
        {
            if (prevNode == NULL)
            {
                *lPtr = curNode->next;
            }
            else
            {
               prevNode->next = curNode->next;
            }
            free(curNode);
            return;
        }
        prevNode = curNode;
        curNode = curNode->next;
    }
}

void printList(struct Node * L)
{
   struct Node * curNode = L;
   while (curNode != NULL)
   {
       printf("%d ", curNode->data);
       curNode = curNode->next;
   }
   printf("\n");
}

struct Node ** createTable(int buckets)
{
    struct Node ** newTable = (struct Node **)malloc(buckets*sizeof(struct Node *));
    int i;
    for (i = 0; i < buckets; i++)
    {
        newTable[i] = NULL;
    }
    return newTable;
}

int findHash(int key, int buckets)
{
    int index = key % buckets;
    return index;
}

void insertTable(int key, int buckets, struct Node ** tablePtr)
{
    int index = findHash(key, buckets);
    insertNode(key, &tablePtr[index]);
}

void freeTable(struct Node ** tablePtr, int buckets)
{
    int i;
    struct Node * curNode;
    struct Node * temp;
    for (i = 0; i < buckets; i++)
    {
        curNode = tablePtr[i];
        while (curNode->next != NULL)
        {
            temp = curNode;
            curNode = curNode->next;
            free(temp);
        }
        free(curNode);
    }
    free(tablePtr);
}


