#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include "log.h"
FILE* log;

void initLog() {
    if (!(log = fopen("log.log", "a+"))) {
        perror("fail open file log");
    }
}

void addLog(int level, char* msg) {
    time_t intps;
    struct tm* date;
    intps = time(NULL);
    date = localtime(&intps);
    switch (level)
    {
        case LOG_INFO:
            printLog(log, "INFO", date, msg);
            break;
        case LOG_WARN:
            printLog(log, "WARNING", date, msg);
            break;
        case LOG_ERR:
            printLog(log, "ERROR", date, msg);
            break;
        default:
            break;
    }
}

void printLog(FILE* log,char* level, struct tm* date, char *msg) {
    int lenght = fprintf(log, "%d:%d:%d : %d:%d:%d  |  %s : %s\n", date->tm_mday, date->tm_mon, date->tm_year + 1900, date->tm_hour, date->tm_min, date->tm_sec, level, msg);
    if (lenght < 0)
      return 1;
}