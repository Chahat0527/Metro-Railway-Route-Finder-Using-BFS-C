#include <stdio.h>
#include <stdint.h>
 
#include "memory.h"
 
static uint32_t totalAllocations = 0U;
static uint32_t totalFrees = 0U;
 
void memoryInit(void)
{
    totalAllocations = 0U;
    totalFrees = 0U;
}
 
void incrementAllocations(void)
{
    totalAllocations++;
}
 
void incrementFrees(void)
{
    totalFrees++;
}
 
uint32_t getTotalAllocations(void)
{
    return totalAllocations;
}
 
uint32_t getTotalFrees(void)
{
    return totalFrees;
}
 
void displayMemoryStatistics(void)
{
    printf("\n");
    printf("=================================\n");
    printf(" MEMORY STATISTICS\n");
    printf("=================================\n");
 
    printf("Allocations : %u\n",
           totalAllocations);
 
    printf("Frees       : %u\n",
           totalFrees);
 
    if(totalAllocations ==
       totalFrees)
    {
        printf("Memory Status : OK\n");
    }
    else
    {
        printf("Memory Status : Possible Leak\n");
    }
 
    printf("=================================\n");
}