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
	TL_FILE_OPEN_WRITE_MODE_NEW(argv[2], 0644);

	//2.2 Open Destination File -- Append File
	//TL_FILE_OPEN_WRITE_MODE_APPEND(TL_CP_FILE_DEST, 0644);
 
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

    return EXIT_SUCCESS;
}