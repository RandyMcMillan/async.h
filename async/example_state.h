#include "async.h"

#include <stdio.h>
#include <time.h>

typedef struct {
    async_state;
    struct async nested1;
    struct async nested2;
} state;

// Store the formatted string of time in the output
void format_time(char *output){
    
    printf("format_time:\n");

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
    printf("nested:async_begin(pt);\n");

    time_t rawtime;
    struct tm * timeinfo;
    time ( &rawtime );
    timeinfo = localtime ( &rawtime );
    char output = timeinfo->tm_sec;
    printf ( "Current local time and date: %s", asctime (timeinfo) );
    format_time(&output);

/*
 The precision given after the . specifies the maximum number
 of characters to output from the string.
 It can be given as a decimal number or as *
 and provided as an int argument before the char pointer.
*/

    printf("value of a_static: %.40s\n", &output);
    printf("value of b_static: %.*s\n", (int)sizeof(output), &output);

    
    printf("nested:async_end;\n");
    async_end;

}
state pt3;
