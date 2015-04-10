#include "lab7.h"

struct Edge ** initAdjMatrix(){
    int i, j;
    struct Edge ** aM = (struct Edge **) malloc(sizeof(struct Edge *)*NODES);
    
    for (i=0; i<NODES; i++)
    {
        aM[i] = (struct Edge *)malloc(sizeof(struct Edge)*NODES);
        for (j=0; j<NODES; j++)
        {
            aM[i][j].flow = 0;
            aM[i][j].flowCap = 0;
        }
    }
    return aM;
}

void insertAdjMatrix(struct Edge ** aM, int vi, int vj, int flow, int flowCap){
    aM[vi][vj].flow = flow;
    aM[vi][vj].flowCap = flowCap;
}

void deleteAdjMatrix(struct Edge ** aM){
    int i;
    
    for (i=0; i<NODES; i++)
        free(aM[i]);
    
    free(aM);        
}

void printAdjMat(struct Edge ** aM){
    int i, j;
    
    for (i=0; i<NODES; i++)
    {
        for (j=0; j<NODES; j++)
        {
            if (aM[i][j].flowCap)
                printf("Edge: (%d, %d) Flow: %d Max Cap: %d \n",
                       i, j, aM[i][j].flow, aM[i][j].flowCap);
        }
    }
}