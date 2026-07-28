#ifndef ADMIN_H
#define ADMIN_H
 
#include "../graph/graph.h"
 
void adminMenu(Graph *graph);
 
void addMetroStationAdmin(Graph *graph);
 
void addRailwayStationAdmin(Graph *graph);
 
void addRouteAdmin(Graph *graph);
 
void removeConnectionAdmin(Graph *graph);
 
void removeStationAdmin(Graph *graph);
 
#endif