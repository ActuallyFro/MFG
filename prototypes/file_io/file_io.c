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

	TL_LOGFILE_INSTALL();
	TL_LOGFILE_START();
	
	TL_PARSEARGS_INSTALL();	
	TL_PARSEARGS_START(TL_ENFORCEPARSING_OFF)
	TL_PARSEARGS_STOP

	TL_FILE_IO_INSTALL();
	
    if(argc != 3){
		TL_QUIT_HELPMSG();
    }
 
	//1. Open Source File
	TL_FILE_OPEN_READ_MODE_BINARY(argv[1]); 
	
    //2.1 Open Destination File -- New File
//	TL_FILE_OPEN_WRITE_MODE_NEW(argv[2], 0644);

	//2.2 Open Destination File -- Append File
//	TL_DEBUGGING_ENABLE();
	TL_FILE_OPEN_WRITE_MODE_APPEND(argv[2], 0644);
//	TL_DEBUGGING_DISABLE();
 
    //Read from source process
    while((TL_FILE_READ_IN_BYTES = read (TL_FILE_OPEN_READ_RET_VAL, &TL_FILE_BUF, TL_FILE_BUF_SIZE)) > 0){
            TL_FILE_WRITE_OUT_BYTES = write (TL_FILE_OPEN_WRITE_RET_VAL, &TL_FILE_BUF, (ssize_t) TL_FILE_READ_IN_BYTES);
            if(TL_FILE_WRITE_OUT_BYTES != TL_FILE_READ_IN_BYTES){
                fprintf(stderr,"\n[ERROR] The copy process has been aborted! Bytes writen != Bytes read.");
                return EXIT_FAILURE;
            }
    }
 
    //Close files
	TL_FILE_CLOSE(TL_FILE_OPEN_READ_RET_VAL);
	TL_FILE_CLOSE(TL_FILE_OPEN_WRITE_RET_VAL);

	char thisstring[20]="Done!";
	int value=23;
	TL_LOGFILE_WRITE_STRING_ARRAY(thisstring);
	TL_LOGFILE_WRITE_STRING_ARRAY(thisstring);
	TL_LOGFILE_WRITE_STRING_ARRAY(thisstring);
	TL_LOGFILE_WRITE(" W00T! ", 7);
	TL_LOGFILE_WRITE((char *)&value, sizeof(value));
//	TL_LOGFILE_WRITE(&thisstring, strlen(thisstring));
	TL_LOGFILE_WRITE_STRING_ARRAY(thisstring);
	TL_LOG("\r\nStart Time: ");
	TL_LOGFILE_WRITE_STRING_ARRAY(TL_TIME_STRING_FULL_SAFE);
	TL_LOGFILE_WRITE("\r\nStop Time: ", 13);
	TL_TIME_GET();
	TL_TIME_CONVERT_STRING_FULL_SAFE();
	TL_LOGFILE_WRITE_STRING_ARRAY(TL_TIME_STRING_FULL_SAFE);

	TL_LOGFILE_STOP();
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