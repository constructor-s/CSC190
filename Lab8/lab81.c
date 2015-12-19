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
    
    return (fN->visitedNodes[t] == 1);
}

void maximizeFlowNetwork(struct flowNetwork * fN, int s, int t){
    int maxFlow = -1, i, j;
    
    while (breadthFirstPathSearch(fN, s, t))
    {
        maxFlow = -1;
        i = t;
        j = fN->parent[i];
        while (i != s && j != -1)
        {
            if (maxFlow == -1 || maxFlow > fN->adjMatrix[j][i].flowCap - fN->adjMatrix[j][i].flow)
                maxFlow = fN->adjMatrix[j][i].flowCap - fN->adjMatrix[j][i].flow;
            if (j > i && maxFlow > fN->adjMatrix[i][j].flow)
                maxFlow = fN->adjMatrix[i][j].flow;
            i = j;
            j = fN->parent[i];
        }
        
        i = t;
        j = fN->parent[i];
        while (i != s && j != -1)
        {
            fN->adjMatrix[j][i].flow += maxFlow;
            i = j;
            j = fN->parent[i];
        }
//        printAdjMat(fN->adjMatrix);
    }
}