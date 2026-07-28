#include <stdio.h>
#include <time.h>
 
#include "bfs.h"
#include "../queue/queue.h"
#include "../logger/logger.h"
 
void printPath(int parent[],
               int current,
               Graph *graph)
{
    if(current == -1)
    {
        return;
    }
 
    printPath(parent,
              parent[current],
              graph);
 
    printf("%s\n",
           graph->stations[current]
           .stationName);
}
 
void BFS(Graph *graph,
         int source,
         int destination)
{
    if(graph == NULL)
    {
        logError("NULL Graph Pointer");
        return;
    }
 
    clock_t startTime;
    clock_t endTime;
 
    startTime = clock();
 
    int visited[MAX_STATIONS] = {0};
 
    int parent[MAX_STATIONS];
 
    for(int i = 0;
        i < MAX_STATIONS;
        i++)
    {
        parent[i] = -1;
    }
 
    Queue q;
 
    initQueue(&q);
 
    visited[source] = 1;
 
    enqueue(&q,
            source);
 
    logInfo("BFS Route Search Started");
 
    while(!isEmpty(&q))
    {
        int current =
            dequeue(&q);
 
        if(current == destination)
        {
            break;
        }
 
        Edge *temp =
            graph->adjList[current];
 
        while(temp != NULL)
        {
            int neighbor =
                temp->destination;
 
            if(visited[neighbor] == 0)
            {
                visited[neighbor] = 1;
 
                parent[neighbor] =
                    current;
 
                enqueue(&q,
                        neighbor);
            }
 
            temp = temp->next;
        }
    }
 
    if(visited[destination] == 0)
    {
        printf("\nNo Route Found\n");
 
        logError("Route Not Found");
 
        return;
    }
 
    printf("\n=========================\n");
    printf("SHORTEST ROUTE FOUND\n");
    printf("=========================\n\n");
 
    printPath(parent,
              destination,
              graph);
 
    endTime = clock();
 
    double executionTime =
        ((double)
        (endTime - startTime))
        / CLOCKS_PER_SEC;
 
    printf("\nExecution Time : %.6f sec\n",
           executionTime);
 
    logInfo("Route Found Successfully");
}