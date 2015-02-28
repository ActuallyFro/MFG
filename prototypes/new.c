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
 
#include "../include/TL_0_01d.h"

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
	TL_LOGFILE_WRITE_STRING(thisstring);
	TL_LOGFILE_WRITE_STRING(thisstring);
	TL_LOGFILE_WRITE_STRING(thisstring);
	#if WINDOWS
		strcpy(thisstring,"\r\n\r\n");
	#else
		strcpy(thisstring,"\n\n");
	#endif
	TL_LOGFILE_WRITE_STRING(thisstring);
	TL_LOGFILE_WRITE_STRING(TL_TIME_STRING_FULL_SAFE);
	TL_LOGFILE_STOP();
	
    return EXIT_SUCCESS;
}#define TL_HELP_MESSAGE		\
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
 
#include "../include/TL_0_01d.h"

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
	TL_LOGFILE_WRITE_STRING_ARRAY(thisstring);
	TL_LOGFILE_WRITE_STRING_ARRAY(thisstring);
	TL_LOGFILE_WRITE_STRING_ARRAY(thisstring);
	TL_LOGFILE_WRITE(" W00T! ", 7);
	#if WINDOWS
		strcpy(thisstring,"\r\n\r\n");
	#else
		strcpy(thisstring,"\n\n");
	#endif
	TL_LOGFILE_WRITE_STRING_ARRAY(thisstring);
	TL_LOGFILE_WRITE_STRING_ARRAY(TL_TIME_STRING_FULL_SAFE);
	TL_LOGFILE_STOP();
	
    return EXIT_SUCCESS;
}#define TL_HELP_MESSAGE		\
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
 
#include "../include/TL_0_01d.h"

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
	TL_LOGFILE_WRITE_STRING_ARRAY(thisstring);
	TL_LOGFILE_WRITE_STRING_ARRAY(thisstring);
	TL_LOGFILE_WRITE_STRING_ARRAY(thisstring);
	TL_LOGFILE_WRITE(" W00T! ", 7);
	TL_LOGFILE_WRITE(&thisstring, strlen(thisstring));
	#if WINDOWS
		strcpy(thisstring,"\r\n\r\n");
	#else
		strcpy(thisstring,"\n\n");
	#endif
	TL_LOGFILE_WRITE_STRING_ARRAY(thisstring);
	TL_LOGFILE_WRITE_STRING_ARRAY(TL_TIME_STRING_FULL_SAFE);
	TL_LOGFILE_STOP();
	
    return EXIT_SUCCESS;
}#define TL_HELP_MESSAGE		\
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
 
#include "../include/TL_0_01d.h"

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
	TL_LOGFILE_WRITE(&value, sizeof(value));
	TL_LOGFILE_WRITE(&thisstring, strlen(thisstring));
	#if WINDOWS
		strcpy(thisstring,"\r\n\r\n");
	#else
		strcpy(thisstring,"\n\n");
	#endif
	TL_LOGFILE_WRITE_STRING_ARRAY(thisstring);
	TL_LOGFILE_WRITE_STRING_ARRAY(TL_TIME_STRING_FULL_SAFE);
	TL_LOGFILE_STOP();
	
    return EXIT_SUCCESS;
}#define TL_HELP_MESSAGE		\
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
 
#include "../include/TL_0_01d.h"

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
	TL_LOGFILE_WRITE(&thisstring, strlen(thisstring));
	#if WINDOWS
		strcpy(thisstring,"\r\n\r\n");
	#else
		strcpy(thisstring,"\n\n");
	#endif
	TL_LOGFILE_WRITE_STRING_ARRAY(thisstring);
	TL_LOGFILE_WRITE_STRING_ARRAY(TL_TIME_STRING_FULL_SAFE);
	TL_LOGFILE_STOP();
	
    return EXIT_SUCCESS;
}#define TL_HELP_MESSAGE		\
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
 
#include "../include/TL_0_01d.h"

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
	TL_LOGFILE_WRITE(&thisstring, strlen(thisstring));
	#if WINDOWS
		strcpy(thisstring,"\r\n\r\n");
	#else
		strcpy(thisstring,"\n\n");
	#endif
	TL_LOGFILE_WRITE_STRING_ARRAY(thisstring);
	TL_LOGFILE_WRITE("Start Time: ", 12);
	TL_LOGFILE_WRITE_STRING_ARRAY(TL_TIME_STRING_FULL_SAFE);
	#if WINDOWS
		strcpy(thisstring,"\r\n\r\n");
	#else
		strcpy(thisstring,"\n\n");
	#endif
	TL_LOGFILE_WRITE("Stop Time: ", 11);
	TL_TIME_GET();
	TL_TIME_CONVERT_STRING_FULL_SAFE();
	TL_LOGFILE_WRITE_STRING_ARRAY(TL_TIME_STRING_FULL_SAFE);

	TL_LOGFILE_STOP();
	
    return EXIT_SUCCESS;
}#define TL_HELP_MESSAGE		\
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
 
#include "../include/TL_0_01d.h"

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
	TL_LOGFILE_WRITE(&thisstring, strlen(thisstring));
	TL_LOGFILE_WRITE_STRING_ARRAY(thisstring);
	TL_LOGFILE_WRITE("\nStart Time: ", 12);
	TL_LOGFILE_WRITE_STRING_ARRAY(TL_TIME_STRING_FULL_SAFE);
	TL_LOGFILE_WRITE("\nStop Time: ", 11);
	TL_TIME_GET();
	TL_TIME_CONVERT_STRING_FULL_SAFE();
	TL_LOGFILE_WRITE_STRING_ARRAY(TL_TIME_STRING_FULL_SAFE);

	TL_LOGFILE_STOP();
	
    return EXIT_SUCCESS;
}#define TL_HELP_MESSAGE		\
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
 
#include "../include/TL_0_01d.h"

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
	TL_LOGFILE_WRITE(&thisstring, strlen(thisstring));
	TL_LOGFILE_WRITE_STRING_ARRAY(thisstring);
	TL_LOGFILE_WRITE("\r\nStart Time: ", 12);
	TL_LOGFILE_WRITE_STRING_ARRAY(TL_TIME_STRING_FULL_SAFE);
	TL_LOGFILE_WRITE("\r\nStop Time: ", 11);
	TL_TIME_GET();
	TL_TIME_CONVERT_STRING_FULL_SAFE();
	TL_LOGFILE_WRITE_STRING_ARRAY(TL_TIME_STRING_FULL_SAFE);

	TL_LOGFILE_STOP();
	
    return EXIT_SUCCESS;
}#define TL_HELP_MESSAGE		\
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
 
#include "../include/TL_0_01d.h"

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
	TL_LOGFILE_WRITE(&thisstring, strlen(thisstring));
	TL_LOGFILE_WRITE_STRING_ARRAY(thisstring);
	TL_LOGFILE_WRITE("\r\nStart Time: ", 14);
	TL_LOGFILE_WRITE_STRING_ARRAY(TL_TIME_STRING_FULL_SAFE);
	TL_LOGFILE_WRITE("\r\nStop Time: ", 13);
	TL_TIME_GET();
	TL_TIME_CONVERT_STRING_FULL_SAFE();
	TL_LOGFILE_WRITE_STRING_ARRAY(TL_TIME_STRING_FULL_SAFE);

	TL_LOGFILE_STOP();
	
    return EXIT_SUCCESS;
}#define TL_HELP_MESSAGE		\
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
 
#include "../include/TL_0_01d.h"

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
	TL_LOGFILE_WRITE(&thisstring, strlen(thisstring));
	TL_LOGFILE_WRITE_STRING_ARRAY(thisstring);
	TL_LOGFILE_WRITE("\r\nStart Time: ", 14);
	TL_LOGFILE_WRITE_STRING_ARRAY(TL_TIME_STRING_FULL_SAFE);
	TL_LOGFILE_WRITE("\r\nStop Time: ", 13);
	TL_TIME_GET();
	TL_TIME_CONVERT_STRING_FULL_SAFE();
	TL_LOGFILE_WRITE_STRING_ARRAY(TL_TIME_STRING_FULL_SAFE);

	TL_LOGFILE_STOP();
	
	    struct timeval start, end;
 
    long mtime, seconds, useconds;    
 
    gettimeofday(&start, NULL);
    usleep(2000);
    gettimeofday(&end, NULL);
 
    seconds  = end.tv_sec  - start.tv_sec;
    useconds = end.tv_usec - start.tv_usec;
 
    mtime = seconds + useconds;
 
    printf("Elapsed time: %ld microsecons\n", mtime);
	
    return EXIT_SUCCESS;
}#define TL_HELP_MESSAGE		\
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
 
#include "../include/TL_0_01d.h"

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
	TL_LOGFILE_WRITE(&thisstring, strlen(thisstring));
	TL_LOGFILE_WRITE_STRING_ARRAY(thisstring);
	TL_LOGFILE_WRITE("\r\nStart Time: ", 14);
	TL_LOGFILE_WRITE_STRING_ARRAY(TL_TIME_STRING_FULL_SAFE);
	TL_LOGFILE_WRITE("\r\nStop Time: ", 13);
	TL_TIME_GET();
	TL_TIME_CONVERT_STRING_FULL_SAFE();
	TL_LOGFILE_WRITE_STRING_ARRAY(TL_TIME_STRING_FULL_SAFE);

	TL_LOGFILE_STOP();
	
	    struct timeval start, end;
 
    long mtime, seconds, useconds;    
 
    gettimeofday(&start, NULL);
    usleep(2000);
    gettimeofday(&end, NULL);
 
    seconds  = end.tv_sec  - start.tv_sec;
    useconds = end.tv_usec - start.tv_usec;
 
    mtime = seconds + useconds;
 
    printf("Elapsed time: %ld microsecons\n", mtime);
	
    return EXIT_SUCCESS;
}#define TL_HELP_MESSAGE		\
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
 
#include "../include/TL_0_01d.h"

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
	TL_LOGFILE_WRITE(&thisstring, strlen(thisstring));
	TL_LOGFILE_WRITE_STRING_ARRAY(thisstring);
	TL_LOGFILE_WRITE("\r\nStart Time: ", 14);
	TL_LOGFILE_WRITE_STRING_ARRAY(TL_TIME_STRING_FULL_SAFE);
	TL_LOGFILE_WRITE("\r\nStop Time: ", 13);
	TL_TIME_GET();
	TL_TIME_CONVERT_STRING_FULL_SAFE();
	TL_LOGFILE_WRITE_STRING_ARRAY(TL_TIME_STRING_FULL_SAFE);

	TL_LOGFILE_STOP();
	
 struct timeval tv;
 struct tm* ptm;
 char time_string[40];
 long milliseconds;

 /* Obtain the time of day, and convert it to a tm struct. */
 gettimeofday (&tv, NULL);
 ptm = localtime (&tv.tv_sec);
 /* Format the date and time, down to a single second. */
 strftime (time_string, sizeof (time_string), "%Y-%m-%d %H:%M:%S", ptm);
 /* Compute milliseconds from microseconds. */
 milliseconds = tv.tv_usec / 1000;
 /* Print the formatted time, in seconds, followed by a decimal point
   and the milliseconds. */
 printf ("%s.%03ld\n", time_string, milliseconds);


	
    return EXIT_SUCCESS;
}#define TL_HELP_MESSAGE		\
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
 
#include "../include/TL_0_01d.h"

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
	TL_LOGFILE_WRITE(&thisstring, strlen(thisstring));
	TL_LOGFILE_WRITE_STRING_ARRAY(thisstring);
	TL_LOGFILE_WRITE("\r\nStart Time: ", 14);
	TL_LOGFILE_WRITE_STRING_ARRAY(TL_TIME_STRING_FULL_SAFE);
	TL_LOGFILE_WRITE("\r\nStop Time: ", 13);
	TL_TIME_GET();
	TL_TIME_CONVERT_STRING_FULL_SAFE();
	TL_LOGFILE_WRITE_STRING_ARRAY(TL_TIME_STRING_FULL_SAFE);

	TL_LOGFILE_STOP();
	
 struct timeval tv;
 struct tm* ptm;
 char time_string[40];
 long milliseconds;

 /* Obtain the time of day, and convert it to a tm struct. */
 gettimeofday (&tv, NULL);
 ptm = localtime (&tv.tv_sec);
 /* Format the date and time, down to a single second. */
 strftime (time_string, sizeof (time_string), "%Y-%m-%d %H:%M:%S", ptm);
 /* Compute milliseconds from microseconds. */
 milliseconds = tv.tv_usec / 1000;
 /* Print the formatted time, in seconds, followed by a decimal point
   and the milliseconds. */
 printf ("%s.%03ld\n", time_string, milliseconds);


	
    return EXIT_SUCCESS;
}#define TL_HELP_MESSAGE		\
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
 
#include "../include/TL_0_01d.h"

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
	TL_LOGFILE_WRITE(&thisstring, strlen(thisstring));
	TL_LOGFILE_WRITE_STRING_ARRAY(thisstring);
	TL_LOGFILE_WRITE("\r\nStart Time: ", 14);
	TL_LOGFILE_WRITE_STRING_ARRAY(TL_TIME_STRING_FULL_SAFE);
	TL_LOGFILE_WRITE("\r\nStop Time: ", 13);
	TL_TIME_GET();
	TL_TIME_CONVERT_STRING_FULL_SAFE();
	TL_LOGFILE_WRITE_STRING_ARRAY(TL_TIME_STRING_FULL_SAFE);

	TL_LOGFILE_STOP();
	
 struct timeval tv;
 struct tm* ptm;
 char time_string[40];
 long milliseconds;

 /* Obtain the time of day, and convert it to a tm struct. */
 gettimeofday (&tv, NULL);
 ptm = localtime (&tv.tv_sec);
 /* Format the date and time, down to a single second. */
 strftime (time_string, sizeof (time_string), "%Y-%m-%d %H:%M:%S", ptm);
 /* Compute milliseconds from microseconds. */
 milliseconds = tv.tv_usec / 1000;
 /* Print the formatted time, in seconds, followed by a decimal point
   and the milliseconds. */
 printf ("%s.%03ld\n", time_string, milliseconds);


	
    return EXIT_SUCCESS;
}#define TL_HELP_MESSAGE		\
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
 
#include "../include/TL_0_01d.h"

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
	TL_LOGFILE_WRITE(&thisstring, strlen(thisstring));
	TL_LOGFILE_WRITE_STRING_ARRAY(thisstring);
	TL_LOGFILE_WRITE("\r\nStart Time: ", 14);
	TL_LOGFILE_WRITE_STRING_ARRAY(TL_TIME_STRING_FULL_SAFE);
	TL_LOGFILE_WRITE("\r\nStop Time: ", 13);
	TL_TIME_GET();
	TL_TIME_CONVERT_STRING_FULL_SAFE();
	TL_LOGFILE_WRITE_STRING_ARRAY(TL_TIME_STRING_FULL_SAFE);

	TL_LOGFILE_STOP();
	
 struct timeval tv;
 struct tm* ptm;
 char time_string[40];
 long milliseconds;

 /* Obtain the time of day, and convert it to a tm struct. */
 gettimeofday (&tv, NULL);
 ptm = localtime (&tv.tv_sec);
 /* Format the date and time, down to a single second. */
 strftime (time_string, sizeof (time_string), "%Y-%m-%d %H:%M:%S", ptm);
 /* Compute milliseconds from microseconds. */
 milliseconds = tv.tv_usec ;
 /* Print the formatted time, in seconds, followed by a decimal point
   and the milliseconds. */
 printf ("%s.%06ld\n", time_string, milliseconds);


	
    return EXIT_SUCCESS;
}#define TL_HELP_MESSAGE		\
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
 
#include "../include/TL_0_01d.h"

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
	TL_LOGFILE_WRITE(&thisstring, strlen(thisstring));
	TL_LOGFILE_WRITE_STRING_ARRAY(thisstring);
	TL_LOGFILE_WRITE("\r\nStart Time: ", 14);
	TL_LOGFILE_WRITE_STRING_ARRAY(TL_TIME_STRING_FULL_SAFE);
	TL_LOGFILE_WRITE("\r\nStop Time: ", 13);
	TL_TIME_GET();
	TL_TIME_CONVERT_STRING_FULL_SAFE();
	TL_LOGFILE_WRITE_STRING_ARRAY(TL_TIME_STRING_FULL_SAFE);

	TL_LOGFILE_STOP();
	
 struct timeval tv;
 struct tm* ptm;
 char time_string[40];
 long milliseconds;

 /* Obtain the time of day, and convert it to a tm struct. */
 gettimeofday (&tv, NULL);
 ptm = localtime (&tv.tv_sec);
 /* Format the date and time, down to a single second. */
 strftime (time_string, sizeof (time_string), "%Y-%m-%d %H:%M:%S", ptm);
 /* Compute milliseconds from microseconds. */
 milliseconds = tv.tv_usec ;
 /* Print the formatted time, in seconds, followed by a decimal point
   and the milliseconds. */
 printf ("%s.%06ld\n", time_string, milliseconds);


	
    return EXIT_SUCCESS;
}#define TL_HELP_MESSAGE		\
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
 
#include "../include/TL_0_01d.h"

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
	TL_LOGFILE_WRITE(&thisstring, strlen(thisstring));
	TL_LOGFILE_WRITE_STRING_ARRAY(thisstring);
	TL_LOGFILE_WRITE("\r\nStart Time: ", 14);
	TL_LOGFILE_WRITE_STRING_ARRAY(TL_TIME_STRING_FULL_SAFE);
	TL_LOGFILE_WRITE("\r\nStop Time: ", 13);
	TL_TIME_GET();
	TL_TIME_CONVERT_STRING_FULL_SAFE();
	TL_LOGFILE_WRITE_STRING_ARRAY(TL_TIME_STRING_FULL_SAFE);

	TL_LOGFILE_STOP();
	
 struct timeval tv;
 struct tm* ptm;
 char time_string[40];
 long milliseconds;

 /* Obtain the time of day, and convert it to a tm struct. */
 gettimeofday (&tv, NULL);
 ptm = localtime (&tv.tv_sec);
 /* Format the date and time, down to a single second. */
 strftime (time_string, sizeof (time_string), "%Y-%m-%d %H:%M:%S", ptm);
 /* Compute milliseconds from microseconds. */
 milliseconds = tv.tv_usec ;
 /* Print the formatted time, in seconds, followed by a decimal point
   and the milliseconds. */
 printf ("%s.%06ld\n", time_string, milliseconds);


	
    return EXIT_SUCCESS;
}#define TL_HELP_MESSAGE		\
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
 
#include "../include/TL_0_01d.h"

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
	TL_LOGFILE_WRITE(&thisstring, strlen(thisstring));
	TL_LOGFILE_WRITE_STRING_ARRAY(thisstring);
	TL_LOGFILE_WRITE("\r\nStart Time: ", 14);
	TL_LOGFILE_WRITE_STRING_ARRAY(TL_TIME_STRING_FULL_SAFE);
	TL_LOGFILE_WRITE("\r\nStop Time: ", 13);
	TL_TIME_GET();
	TL_TIME_CONVERT_STRING_FULL_SAFE();
	TL_LOGFILE_WRITE_STRING_ARRAY(TL_TIME_STRING_FULL_SAFE);

	TL_LOGFILE_STOP();
	
 struct timeval tv;
 struct tm* ptm;
 char time_string[40];
 long milliseconds;

 /* Obtain the time of day, and convert it to a tm struct. */
 gettimeofday (&tv, NULL);
 ptm = localtime (&tv.tv_sec);
 /* Format the date and time, down to a single second. */
 strftime (time_string, sizeof (time_string), "%Y-%m-%d %H:%M:%S", ptm);
 /* Compute milliseconds from microseconds. */
 milliseconds = tv.tv_usec ;
 /* Print the formatted time, in seconds, followed by a decimal point
   and the milliseconds. */
 printf ("%s.%06ld\n", time_string, milliseconds);


	
    return EXIT_SUCCESS;
}#define TL_HELP_MESSAGE		\
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
 
#include "../include/TL_0_01d.h"

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
	TL_LOGFILE_WRITE(&thisstring, strlen(thisstring));
	TL_LOGFILE_WRITE_STRING_ARRAY(thisstring);
	TL_LOGFILE_WRITE("\r\nStart Time: ", 14);
	TL_LOGFILE_WRITE_STRING_ARRAY(TL_TIME_STRING_FULL_SAFE);
	TL_LOGFILE_WRITE("\r\nStop Time: ", 13);
	TL_TIME_GET();
	TL_TIME_CONVERT_STRING_FULL_SAFE();
	TL_LOGFILE_WRITE_STRING_ARRAY(TL_TIME_STRING_FULL_SAFE);

	TL_LOGFILE_STOP();
	
 struct timeval tv;
 struct tm* ptm;
 char time_string[40];
 long milliseconds;

 /* Obtain the time of day, and convert it to a tm struct. */
 gettimeofday (&tv, NULL);
 ptm = localtime (&tv.tv_sec);
 /* Format the date and time, down to a single second. */
 strftime (time_string, sizeof (time_string), "%Y-%m-%d %H:%M:%S", ptm);
 /* Compute milliseconds from microseconds. */
 milliseconds = tv.tv_usec ;
 /* Print the formatted time, in seconds, followed by a decimal point
   and the milliseconds. */
 printf ("%s.%06ld\n", time_string, milliseconds);


	
    return EXIT_SUCCESS;
}#define TL_HELP_MESSAGE		\
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
 
#include "../include/TL_0_01d.h"

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
	TL_LOGFILE_WRITE(&thisstring, strlen(thisstring));
	TL_LOGFILE_WRITE_STRING_ARRAY(thisstring);
	TL_LOGFILE_WRITE("\r\nStart Time: ", 14);
	TL_LOGFILE_WRITE_STRING_ARRAY(TL_TIME_STRING_FULL_SAFE);
	TL_LOGFILE_WRITE("\r\nStop Time: ", 13);
	TL_TIME_GET();
	TL_TIME_CONVERT_STRING_FULL_SAFE();
	TL_LOGFILE_WRITE_STRING_ARRAY(TL_TIME_STRING_FULL_SAFE);

	TL_LOGFILE_STOP();
	
 struct timeval tv;
 struct tm* ptm;
 char time_string[40];
 long milliseconds;

 /* Obtain the time of day, and convert it to a tm struct. */
 gettimeofday (&tv, NULL);
 ptm = localtime (&tv.tv_sec);
 /* Format the date and time, down to a single second. */
 strftime (time_string, sizeof (time_string), "%Y-%m-%d %H:%M:%S", ptm);
 /* Compute milliseconds from microseconds. */
 milliseconds = tv.tv_usec ;
 /* Print the formatted time, in seconds, followed by a decimal point
   and the milliseconds. */
 printf ("%s.%06ld\n", time_string, milliseconds);


	
    return EXIT_SUCCESS;
}#define TL_HELP_MESSAGE		\
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
 
#include "../include/TL_0_01d.h"

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
	TL_LOGFILE_WRITE(&thisstring, strlen(thisstring));
	TL_LOGFILE_WRITE_STRING_ARRAY(thisstring);
	TL_LOGFILE_WRITE("\r\nStart Time: ", 14);
	TL_LOGFILE_WRITE_STRING_ARRAY(TL_TIME_STRING_FULL_SAFE);
	TL_LOGFILE_WRITE("\r\nStop Time: ", 13);
	TL_TIME_GET();
	TL_TIME_CONVERT_STRING_FULL_SAFE();
	TL_LOGFILE_WRITE_STRING_ARRAY(TL_TIME_STRING_FULL_SAFE);

	TL_LOGFILE_STOP();
	
 struct timeval tv;
 struct tm* ptm;
 char time_string[40];
 long milliseconds;

 /* Obtain the time of day, and convert it to a tm struct. */
 gettimeofday (&tv, NULL);
 ptm = localtime (&tv.tv_sec);
 /* Format the date and time, down to a single second. */
 strftime (time_string, sizeof (time_string), "%Y-%m-%d %H:%M:%S", ptm);
 /* Compute milliseconds from microseconds. */
 milliseconds = tv.tv_usec ;
 /* Print the formatted time, in seconds, followed by a decimal point
   and the milliseconds. */
 printf ("%s.%06ld\n", time_string, milliseconds);


	
    return EXIT_SUCCESS;
}#define TL_HELP_MESSAGE		\
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
 
#include "../include/TL_0_01d.h"

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
	TL_LOGFILE_WRITE(&thisstring, strlen(thisstring));
	TL_LOGFILE_WRITE_STRING_ARRAY(thisstring);
	TL_LOGFILE_WRITE("\r\nStart Time: ", 14);
	TL_LOGFILE_WRITE_STRING_ARRAY(TL_TIME_STRING_FULL_SAFE);
	TL_LOGFILE_WRITE("\r\nStop Time: ", 13);
	TL_TIME_GET();
	TL_TIME_CONVERT_STRING_FULL_SAFE();
	TL_LOGFILE_WRITE_STRING_ARRAY(TL_TIME_STRING_FULL_SAFE);

	TL_LOGFILE_STOP();
	
 struct timeval tv;
 struct tm* ptm;
 char time_string[40];
 long milliseconds;

 /* Obtain the time of day, and convert it to a tm struct. */
 gettimeofday (&tv, NULL);
 ptm = localtime (&tv.tv_sec);
 /* Format the date and time, down to a single second. */
 strftime (time_string, sizeof (time_string), "%Y-%m-%d %H:%M:%S", ptm);
 /* Compute milliseconds from microseconds. */
 milliseconds = tv.tv_usec ;
 /* Print the formatted time, in seconds, followed by a decimal point
   and the milliseconds. */
 printf ("%s.%06ld\n", time_string, milliseconds);


	
    return EXIT_SUCCESS;
}