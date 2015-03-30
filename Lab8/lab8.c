#include "lab8.h"

struct flowNetwork * initFlowNetwork(){
    int i;
    struct flowNetwork * fN = (struct flowNetwork *) malloc(sizeof(struct flowNetwork));
    fN->adjMatrix = initAdjMatrix();
    for (i=0; i<NODES; i++)
    {
        fN->parent[i] = -1;
        fN->visitedNodes[i] = 0;
    }
    return fN;
}

void deleteFlowNetwork(struct flowNetwork * fN){
    deleteAdjMatrix(fN->adjMatrix);
    free(fN);
}

int breadthFirstPathSearch(struct flowNetwork * fN, int s, int t){
    int i, j;
    struct Queue * q;
    struct Data node;
    
    for (i=0; i<NODES; i++)
    {
        fN->parent[i] = -1;
        fN->visitedNodes[i] = 0;
    }
    
    initQueue(&q);
    node.vertex = s;
    enqueue(q, node);
    
    while(!isQueueEmpty(q)){
        dequeue(q,&node);
        i = node.vertex;
        
        for (j=0; j<NODES; j++)
        {
            if (fN->adjMatrix[i][j].flowCap
                && fN->adjMatrix[i][j].flowCap - fN->adjMatrix[i][j].flow > 0
                && !fN->visitedNodes[j])
            {
                fN->parent[j] = i;
                fN->visitedNodes[j] = 1;
                node.vertex = j;
                enqueue(q, node);
            }
        }
    }

    free(q);
    
    return (fN->visitedNodes[t] == 1);
}
