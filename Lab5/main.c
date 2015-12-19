#include "queue.h"

void p1(void)
{
    int i,n;
    struct Queue Q=initQueue();
    struct Data d;
    d.arrivalTime=3;
    d.departureTime=3.1;
    enqueue(&Q, d);
    d.arrivalTime=3.5;
    d.departureTime=3.6;
    enqueue(&Q, d);
    d.arrivalTime=3.8;
    d.departureTime=3.9;
    enqueue(&Q, d);
    d.arrivalTime=4.1;
    d.departureTime=4.2;
    enqueue(&Q,d);
    
    n=Q.currSize;
    for (i=0; i<n-1; i++) {
        d=dequeue(&Q);
        printf("Arrival Time: %f, Departure Time: %f\n", d.arrivalTime, d.departureTime);
    }
    freeQueue(&Q);
}

int main( int argc, char *argv[] ){
    if( argc < 2 ){
        printf("Expecting at least one argument. Please try again\n");
   	}
    else if(argc==2){
        if(atoi(argv[1])==1){
            p1();
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
