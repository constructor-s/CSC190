#include <stdio.h>
#include <stdlib.h>
#define MaxQueueSize 100
#define NODES 9
#define INF 1000000

struct Edge{
    int flow;
    int flowCap;
};

struct Data{
    int vertex;
};

struct flowNetwork{
    struct Edge ** adjMatrix;
    int visitedNodes[NODES];
    int parent[NODES];
};

struct Edge ** initAdjMatrix();
void insertAdjMatrix(struct Edge ** aM, int vi, int vj, int flow, int flowCap);
void deleteAdjMatrix(struct Edge ** aM);
void printAdjMat(struct Edge ** aM);

struct flowNetwork * initFlowNetwork();
void deleteFlowNetwork(struct flowNetwork * fN);