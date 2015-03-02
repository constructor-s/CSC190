#include "queue.h"

struct Queue initQueue()
{
    struct Queue queue;
    queue.currSize = 0;
    queue.front = NULL;
    queue.rear = NULL;
    return queue;
}

void enqueue(struct Queue *qPtr, struct Data d)
{
    struct Node * newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = d;
    newNode->next = NULL;
    if (qPtr->rear == NULL)
    {
        qPtr->rear = newNode;
        qPtr->front = newNode;
    }
    else
    {
        qPtr->rear->next = newNode;
        qPtr->rear = newNode;
    }
    qPtr->currSize++;
}

struct Data dequeue(struct Queue *qPtr)
{
    struct Node * temp;
    struct Data d;
    if (qPtr->currSize)
    {
        temp = qPtr->front;
        d = temp->data;
        if (qPtr->front == qPtr->rear)
        {
            qPtr->front = NULL;
            qPtr->rear = NULL;
        }
        else
        {
            qPtr->front = temp->next;
        }
        free(temp);
        qPtr->currSize--;        
    }
    return d;
}
void freeQueue(struct Queue *qPtr)
{
    struct Node * temp = qPtr->front;
    struct Node * prev;
    while (temp != NULL)
    {
        prev = temp;
        temp = prev->next;
        free(prev);
    }
}
