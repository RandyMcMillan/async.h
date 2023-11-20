#ifndef __EXAMPLESTATE_H__
#define __EXAMPLESTATE_H__

#include "async.h"

#ifndef _STDIO_H
#include <stdio.h>
#endif

#ifndef _TIME_H
#include <time.h>
#endif

typedef struct {
    async_state;
    struct async nested1;
    struct async nested2;
} state;

// Store the formatted string of time in the output
void format_time(char *output){
    
    printf("format_time: ");

    time_t rawtime;
    struct tm * timeinfo;
    
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    
    sprintf(output, "[%d %d %d %d:%d:%d]", timeinfo->tm_mday,
            timeinfo->tm_mon + 1, timeinfo->tm_year + 1900,
            timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
}

async nested(struct async *pt3){

    async_begin(pt3);
    //printf("nested: async_begin(pt);\n");

    time_t rawtime;
    struct tm * timeinfo;
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    printf ( "nested: Current local time and date: %s", asctime (timeinfo) );
    printf("format_time: ");
    printf("[%d %d %d %d:%d:%d]\n", timeinfo->tm_mday,
            timeinfo->tm_mon + 1, timeinfo->tm_year + 1900,
            timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);

    async_end;

}
state pt3;

#endif
