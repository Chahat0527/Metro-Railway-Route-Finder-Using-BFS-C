#ifndef MEMORY_H
#define MEMORY_H
 
#include <stdint.h>
 
void memoryInit(void);
 
void incrementAllocations(void);
 
void incrementFrees(void);
 
void displayMemoryStatistics(void);
 
uint32_t getTotalAllocations(void);
 
uint32_t getTotalFrees(void);
 
#endif