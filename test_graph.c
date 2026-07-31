#include <stdio.h>
#include <assert.h>

#include "../../src/graph/graph.h"
#include "../../src/memory/memory.h"

int main(void)
{
    memoryInit();

    Graph *graph = createGraph();

    assert(graph != NULL);

    int chennai = addStation(graph, "Chennai");
    int delhi = addStation(graph, "Delhi");

    assert(chennai >= 0);
    assert(delhi >= 0);

    addConnection(graph, chennai, delhi);

    assert(findStation(graph, "Chennai") != -1);
    assert(findStation(graph, "Delhi") != -1);

    removeStation(graph, delhi);

    assert(graph->stations[delhi].active == 0);

    freeGraph(graph);

    printf("Graph Unit Test Passed\n");

    return 0;
}