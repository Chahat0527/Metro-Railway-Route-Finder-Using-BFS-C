#include <stdio.h>
#include <time.h>
 
#include "performance.h"
 
static clock_t startTime;
static clock_t endTime;
 
void startPerformanceCounter(void)
{
    startTime = clock();
}
 
void stopPerformanceCounter(void)
{
    endTime = clock();
}
 
void displayExecutionTime(void)
{
    double executionTime =
      ((double)(endTime - startTime))
      / CLOCKS_PER_SEC;
 
    printf("\n");
    printf("=================================\n");
    printf(" PERFORMANCE REPORT\n");
    printf("=================================\n");
 
    printf("Execution Time : %.6f seconds\n",
           executionTime);
 
    printf("=================================\n");
}