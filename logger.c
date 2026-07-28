#include <stdio.h>
#include <time.h>
 
#include "logger.h"
 
static void writeLog(const char *level,
                     const char *message)
{
    FILE *fp;
 
    fp = fopen("data/logs.txt", "a");
 
    if(fp == NULL)
    {
        return;
    }
 
    time_t currentTime =
        time(NULL);
 
    fprintf(fp,
            "[%s] %s : %s\n",
            level,
            ctime(&currentTime),
            message);
 
    fprintf(fp,
            "----------------------------------\n");
 
    fclose(fp);
}
 
void logInfo(const char *message)
{
    writeLog("INFO",
             message);
}
 
void logError(const char *message)
{
    writeLog("ERROR",
             message);
}
 
void logWarning(const char *message)
{
    writeLog("WARNING",
             message);
}