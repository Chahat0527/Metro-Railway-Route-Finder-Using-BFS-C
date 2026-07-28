#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "file.h"
#include "../logger/logger.h"

void saveNetwork(Graph *graph)
{
    if(graph == NULL)
    {
        logError("Graph NULL During Save");
        return;
    }

    FILE *fp;

    fp = fopen("data/stations.txt",
               "w");

    if(fp == NULL)
    {
        printf("\nFile Open Error\n");

        logError("Station File Open Failed");

        return;
    }

    fprintf(fp,
            "%d\n",
            graph->vertices);

    for(int i = 0;
        i < graph->vertices;
        i++)
    {
        fprintf(fp,
                "%d,%s\n",
                graph->stations[i].stationId,
                graph->stations[i].stationName);
    }

    fclose(fp);

    printf("\nNetwork Saved Successfully\n");

    logInfo("Network Saved");
}

void loadNetwork(Graph *graph)
{
    if(graph == NULL)
    {
        logError("Graph NULL During Load");
        return;
    }

    FILE *fp;

    fp = fopen("data/stations.txt",
               "r");

    if(fp == NULL)
    {
        printf("\nNo Existing Network File Found\n");

        logError("Load Network Failed");

        return;
    }

    graph->vertices = 0;

    int stationCount = 0;

    fscanf(fp,
           "%d\n",
           &stationCount);

    char line[100];

    for(int i = 0;
        i < stationCount;
        i++)
    {
        if(fgets(line,
                 sizeof(line),
                 fp) == NULL)
        {
            break;
        }

        line[strcspn(line,
                     "\n")] = '\0';

        int stationId = 0;

        char stationName[NAME_LEN];

        sscanf(line,
               "%d,%49[^\n]",
               &stationId,
               stationName);

        addStation(graph,
                   stationName);
    }

    fclose(fp);

    printf("\nNetwork Loaded Successfully\n");

    logInfo("Network Loaded");
}
