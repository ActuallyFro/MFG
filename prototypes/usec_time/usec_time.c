#define TL_HELP_MESSAGE		\
"\n cp\
\n ===\
\n A Poor excuse of a copy of cp...\
\n\
\n                                                ActuallyFro - Feb 2015		\
\n\
\n Example Commandline Excecution:\
\n -------------------------------\
\n %s <source file> <dest file>\
\n\
\n\n",TL_ProgName
#include <sys/time.h>
#include "../../include/TL_0_01d.h"

int main(int argc, char **argv) {
	TL_TIME_INIT();
	TL_TIME_INIT_STRING_FULL_SAFE_ARRAY();
	TL_TIME_GET();
	TL_TIME_CONVERT_STRING_FULL_SAFE();


	/*
 struct timeval tv;
 struct tm* ptm;
 //time_t *timetemp;
 char time_string[40];
 long milliseconds;

 // Obtain the time of day, and convert it to a tm struct.
 gettimeofday (&tv, NULL);
 //timetemp=tv.tv_sec;
 ptm = localtime (&tv.tv_sec);
 
 // Format the date and time, down to a single second. 
 strftime (time_string, sizeof (time_string), "%Y-%m-%d %H:%M:%S", ptm);
 // Compute milliseconds from microseconds.
 milliseconds = tv.tv_usec ;
 // Print the formatted time, in seconds, followed by a decimal point
   and the milliseconds. 
 printf ("%s.%06ld\n", time_string, milliseconds);
*/
char time_string[40];
struct timeval tp;
gettimeofday(&tp, 0);
time_t curtime = tp.tv_sec;
struct tm* t = localtime(&curtime);
strftime(time_string, sizeof (time_string), "%Y-%m-%d %H:%M:%S", t);
printf("%02d:%02d:%02d:%ld\n", t->tm_hour, t->tm_min, t->tm_sec, tp.tv_usec/1000);

	
    return EXIT_SUCCESS;
}