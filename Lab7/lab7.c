#include "lab7.h"

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