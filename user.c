#include <stdio.h>
#include <string.h>
 
#include "user.h"
#include "../bfs/bfs.h"
#include "../train/train.h"
 
void userMenu(Graph *graph)
{
    int choice;
 
    char source[50];
    char destination[50];
 
    while(1)
    {
        printf("\n===== USER MENU =====\n");
 
        printf("1. Find Shortest Route\n");
        printf("2. View Alternate Route\n");
        printf("3. View Available Trains\n");
        printf("4. Back\n");
 
        printf("\nEnter Choice : ");
 
        scanf("%d",&choice);
 
        getchar();
 
        switch(choice)
        {
            case 1:
            {
                printf("Source : ");
 
                fgets(source,
                      sizeof(source),
                      stdin);
 
                source[strcspn(source,"\n")] = '\0';
 
                printf("Destination : ");
 
                fgets(destination,
                      sizeof(destination),
                      stdin);
 
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
                    printf("\nInvalid Station\n");
 
                    break;
                }
 
                BFS(graph,
                    src,
                    dest);
 
                break;
            }
 
            case 2:
            {
                printf("Source : ");
 
                fgets(source,
                      sizeof(source),
                      stdin);
 
                source[strcspn(source,"\n")] = '\0';
 
                printf("Destination : ");
 
                fgets(destination,
                      sizeof(destination),
                      stdin);
 
                destination[strcspn(destination,"\n")] = '\0';
 
                showAlternateRoutes(source,
                                    destination);
 
                break;
            }
 
            case 3:
            {
                printf("Source : ");
 
                fgets(source,
                      sizeof(source),
                      stdin);
 
                source[strcspn(source,"\n")] = '\0';
 
                printf("Destination : ");
 
                fgets(destination,
                      sizeof(destination),
                      stdin);
 
                destination[strcspn(destination,"\n")] = '\0';
 
                showAvailableTrains(source,
                                    destination);
 
                break;
            }
 
            case 4:
 
                return;
 
            default:
 
                printf("\nInvalid Choice\n");
        }
    }
}