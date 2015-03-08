#include "assignment2.h"

double calcAverageWaitingTime(struct Simulation * S)
{
    struct Node * curr = S->eventQueue.front;
    struct Data d;
    double totalWaitingTime = 0;
    int counter = 0;
    while (curr != NULL)
    {
        curr = curr->next;
        d = dequeue(&S->eventQueue);
        totalWaitingTime += d.departureTime - d.arrivalTime;
        //printf("%f %f %f\n", d.arrivalTime, d.departureTime, d.departureTime - d.arrivalTime);
        counter++;
    }
    return totalWaitingTime/counter;
}

struct Simulation initSimulation(double arrivalRate, double serviceTime, double simTime)
{
    struct Simulation sim;
//    struct Data d;

    sim.currTime = 0;
    sim.arrivalRate = arrivalRate;
    sim.serviceTime = serviceTime;
    sim.timeForNextArrival = getRandTime(sim.arrivalRate);
    sim.timeForNextDeparture = sim.timeForNextArrival + sim.serviceTime;
    sim.totalSimTime = simTime;
    sim.buffer = initQueue();
    sim.eventQueue = initQueue();

//    d.arrivalTime = sim.timeForNextArrival;
//    enqueue(&sim.buffer, d);

    return sim;
}

double runSimulation(double arrivalRate, double serviceTime, double simTime)
{
    struct Simulation sim = initSimulation(arrivalRate, serviceTime, simTime);
    struct Data d;
    double avg;
//    int i;
//    for (i=0; i < 50; i++)
//    {
//        printf("-");
//    }
//    printf("\n");
    sim.e = ARRIVAL;

    while (sim.e == ARRIVAL)
    {
        sim.currTime = sim.timeForNextArrival;
        //                if (sim.currTime > sim.totalSimTime) break;
        //                printf("Current time:%f\n", sim.currTime);
        d.arrivalTime = sim.currTime;
        //                printf("Arrival: Arrival Time: %f\n", d.arrivalTime);
        enqueue(&sim.buffer, d);
//        printf("Arrive: %f\n", sim.buffer.rear->data.arrivalTime);
        sim.timeForNextArrival = sim.currTime + getRandTime(sim.arrivalRate);
        if (sim.timeForNextArrival > sim.totalSimTime) sim.e = DEPARTURE;
    }
    //printf("33%%...");

    while (sim.e == DEPARTURE)
    {
        sim.currTime = sim.timeForNextDeparture;
        d = dequeue(&sim.buffer);
        d.departureTime = sim.currTime;
        enqueue(&sim.eventQueue, d);
        if (sim.buffer.front == NULL) break;
        if (sim.currTime < sim.buffer.front->data.arrivalTime)
            sim.timeForNextDeparture = sim.buffer.front->data.arrivalTime + serviceTime;
        else
            sim.timeForNextDeparture = sim.currTime + serviceTime;
        if (sim.timeForNextDeparture > sim.totalSimTime) sim.e = ARRIVAL;
    }
    //printf("67%%");
//
//
//
//
//
//
//    while (sim.e <= DEPARTURE)
//    {
//        while (sim.currTime < sim.totalSimTime && sim.timeForNextArrival < sim.totalSimTime && sim.timeForNextDeparture < sim.totalSimTime)
//        {
//
//            printf("%f", sim.currTime);
////        if (sim.currTime > prev + sim.totalSimTime / 50)
////        {
////            printf("*");
////            prev = sim.currTime;
////        }
//            //sim.e = (sim.timeForNextDeparture < sim.timeForNextArrival);
//            switch (sim.e)
//            {
//                case ARRIVAL:
//                    sim.currTime = sim.timeForNextArrival;
//    //                if (sim.currTime > sim.totalSimTime) break;
//    //                printf("Current time:%f\n", sim.currTime);
//                    d.arrivalTime = sim.currTime;
//    //                printf("Arrival: Arrival Time: %f\n", d.arrivalTime);
//                    enqueue(&sim.buffer, d);
//                    sim.timeForNextArrival = sim.currTime + getRandTime(sim.arrivalRate);
//                    break;
//
//                case DEPARTURE:
//                    sim.currTime = sim.timeForNextDeparture;
//    //                if (sim.currTime > sim.totalSimTime) break;
//    //                printf("Current time:%f\n", sim.currTime);
//                    if (sim.buffer.front != NULL && sim.buffer.front->data.arrivalTime + sim.serviceTime > sim.currTime)
//                        sim.currTime = sim.buffer.front->data.arrivalTime + serviceTime;
//                    sim.buffer.front->data.departureTime = sim.currTime;
//                    d = dequeue(&sim.buffer);
//                    enqueue(&sim.eventQueue, d);
////                    printf("Arrival Time: %f\nDeparture Time: %f\n", d.arrivalTime, d.departureTime);
//                    sim.timeForNextDeparture = sim.currTime + serviceTime;
//                    break;
//            }
//        }
//        sim.currTime = 0;
//        sim.timeForNextArrival = 0;
//        sim.e++;
////        printf("%f%f%f% d\n", sim.currTime, sim.timeForNextArrival, sim.timeForNextDeparture, (sim.e == DEPARTURE));
//    }

   // printf("\n");
    avg = calcAverageWaitingTime(&sim);
    freeQueue(&sim.buffer);
    freeQueue(&sim.eventQueue);
    return avg;
}

