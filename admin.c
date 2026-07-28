#include <stdio.h>
#include <string.h>
 
#include "admin.h"
#include "../logger/logger.h"
#include "../file/file.h"
#include "../graph/graph.h"
 
void addMetroStationAdmin(Graph *graph)
{
    char station[50];
 
    printf("Enter Metro Station Name : ");
    fgets(station, sizeof(station), stdin);
 
    station[strcspn(station, "\n")] = '\0';
 
    addStation(graph, station);
 
    logInfo("Metro Station Added");
}
 
void addRailwayStationAdmin(Graph *graph)
{
    char station[50];
 
    printf("Enter Railway Station Name : ");
    fgets(station, sizeof(station), stdin);
 
    station[strcspn(station, "\n")] = '\0';
 
    addStation(graph, station);
 
    logInfo("Railway Station Added");
}
 
void removeStationAdmin(Graph *graph)
{
    char station[50];
 
    printf("Station Name : ");
 
    fgets(station,
          sizeof(station),
          stdin);
 
    station[strcspn(station,"\n")] = '\0';
 
    int id =
        findStation(graph,
                    station);
 
    if(id == -1)
    {
        printf("Station Not Found\n");
        return;
    }
 
    removeStation(graph,id);
}
 
void removeConnectionAdmin(Graph *graph)
{
    char source[50];
    char destination[50];
 
    printf("Source Station : ");
    fgets(source,sizeof(source),stdin);
 
    source[strcspn(source,"\n")] = '\0';
 
    printf("Destination Station : ");
    fgets(destination,sizeof(destination),stdin);
 
    destination[strcspn(destination,"\n")] = '\0';
 
    int src =
        findStation(graph,
                    source);
 
    int dest =
        findStation(graph,
                    destination);
 
    if((src == -1) ||
       (dest == -1))
    {
        printf("Invalid Stations\n");
        return;
    }
 
    removeConnection(graph,
                     src,
                     dest);
}
 
void addRouteAdmin(Graph *graph)
{
    char source[50];
    char destination[50];
 
    printf("Source Station : ");
    fgets(source, sizeof(source), stdin);
    source[strcspn(source, "\n")] = '\0';
 
    printf("Destination Station : ");
    fgets(destination, sizeof(destination), stdin);
    destination[strcspn(destination, "\n")] = '\0';
 
    int src =
        findStation(graph, source);
 
    int dest =
        findStation(graph, destination);
 
    if((src == -1) || (dest == -1))
    {
        printf("Invalid Stations\n");
        return;
    }
 
    addConnection(graph, src, dest);
 
    printf("Connection Added Successfully\n");
}
 
void adminMenu(Graph *graph)
{
    int choice;
 
    while(1)
    {
        printf("\n===== ADMIN MENU =====\n");
 
        printf("1. Add Metro Station\n");
        printf("2. Add Railway Station\n");
        printf("3. Add Connection\n");
        printf("4. Remove Connection\n");
        printf("5. Remove Station\n");
        printf("6. View Stations\n");
        printf("7. Save Network\n");
        printf("8. Load Network\n");
        printf("9. Back\n");
 
        printf("\nEnter Choice : ");
 
        scanf("%d", &choice);
 
        getchar();
 
        switch(choice)
        {
            case 1:
 
                addMetroStationAdmin(graph);
 
                break;
 
            case 2:
 
                addRailwayStationAdmin(graph);
 
                break;
 
            case 3:
 
                addRouteAdmin(graph);
 
                break;
 
            case 4:
 
                removeConnectionAdmin(graph);
 
                break;
 
            case 5:
 
                removeStationAdmin(graph);
 
                break;
 
            case 6:
 
                displayStations(graph);
 
                break;
 
            case 7:
 
                saveNetwork(graph);
 
                break;
 
            case 8:
 
                loadNetwork(graph);
 
                break;
 
            case 9:
 
                return;
 
            default:
 
                printf("Invalid Choice\n");
        }
    }
}

 
