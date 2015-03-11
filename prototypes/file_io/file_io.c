#define TL_HELP_MESSAGE		\
"\n cp\
\n ===\
\n A Poor excuse of a copy of cp...\
\n\
\n                                                ActuallyFro - Mar 2015		\
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
	TL_TIME_INIT_STRING_USEC_ARRAY();

	TL_TIME_GET();
	TL_TIME_CONVERT_STRING_FULL_SAFE();
	TL_TIME_CONVERT_STRING_USECS();

	TL_DEBUG("\n[DEBUGGING] %s.%s\n",TL_TIME_STRING_FULL_SAFE,TL_TIME_STRING_TIME_USECS);
	
	TL_PARSEARGS_INSTALL();	
	TL_PARSEARGS_START(TL_ENFORCEPARSING_OFF)
	TL_PARSEARGS_STOP;

	TL_FILE_IO_INSTALL();
	
    if(argc < 3){
		TL_QUIT_HELPMSG();
    }
///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~///
/// File IO Example 1 -- an implementation of Copy / cp
/// -----------------
	//1. Open Source File
	TL_FILE_OPEN_READ_MODE_BINARY(argv[1]); 
	
    //2.1 Open Destination File -- New File
	TL_FILE_OPEN_WRITE_MODE_NEW(argv[2], 0644);
	
	//2.2 Open Destination File -- Append File
	//TL_FILE_OPEN_WRITE_MODE_APPEND(argv[2], 0644);

    //3. Copy Read Bytes from source and Write to new file
	TL_FILE_READ_NO_CHECK(); //Set default case
	while(TL_FILE_READ_IN_BYTES > 0){ //This command will read in the file opened with any TL_FILE_OPEN_READ into the default TL_FILE_BUF
		TL_FILE_WRITE_NO_CHECK(); //This command will write the data in the default TL_FILE_BUF to the file opened by TL_FILE_OPEN_WRITE
		if(TL_FILE_WRITE_OUT_BYTES != TL_FILE_READ_IN_BYTES){ //since this 'tool' is copying from one file to the next it's simply needs to check that the read-> write process had the same bytes
			TL_DEBUGF(stderr,"\n[ERROR] The copy process has been aborted! Bytes writen != Bytes read.");
			return EXIT_FAILURE;
		}
		TL_FILE_READ_NO_CHECK();
    }
    //Close files
	TL_FILE_CLOSE();
///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~///

///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~///
/// File IO Example 2 -- examples of creating a log file that is a "named" file
/// -----------------

	//Play with Named File
	TL_FILE_IO_INSTALL_NAMED(FILE1);
	TL_FILE_OPEN_WRITE_MODE_NEW_NAMED("ThisFile.log", 0644,FILE1);
	TL_FILE_WRITE_STRING_ARRAY_NAMED(FILE1,"Sup!?"); 
	TL_FILE_WRITE_STRING_ARRAY_NAMED(FILE1,"\r\nStart Time: ");
	TL_FILE_WRITE_NAMED(FILE1,(char *)&TL_TIME_STRING_FULL_SAFE,strlen(TL_TIME_STRING_FULL_SAFE));
	TL_FILE_WRITE_STRING_ARRAY_NAMED(FILE1,".");
	TL_FILE_WRITE_NAMED(FILE1,(char *)&TL_TIME_STRING_TIME_USECS,strlen(TL_TIME_STRING_TIME_USECS));
	TL_FILE_CLOSE_NAMED(FILE1);
	
	if(TL_DEBUGGING==TRUE){
		TL_FILE_OPEN_READ_MODE_BINARY_NAMED("ThisFile.log",FILE1);
		TL_FILE_READ_NAMED(FILE1);
		TL_DEBUG("\n[DEBUGGING] Contents: %s\n",BUF_FILE1);
		TL_FILE_CLOSE_NAMED(FILE1);
	}
	
///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~///

///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~///
/// File IO Example 3 -- example of using TL's 'Default' Log file that is activated by command line switches
/// -----------------
	TL_LOGFILE_INSTALL();
	TL_LOGFILE_START();
	TL_DEBUG("\n[DEBUGGING] Logfile name: %s\n",TL_LOGFILE);
	
	//Log It!
	char thisstring[20]="Done!";	
	int value=23;
	TL_LOGFILE_WRITE_STRING_ARRAY(thisstring);
	TL_LOGFILE_WRITE_STRING_ARRAY(thisstring);
	TL_LOGFILE_WRITE_STRING_ARRAY(thisstring);
	TL_LOGFILE_WRITE(" W00T! ", 7);
	
	TL_LOGFILE_PRINT("\r\nDirect String Write 1: ");
	TL_LOGFILE_WRITE((char *)&thisstring, strlen(thisstring));
	
	char thisstring2[4];
	thisstring2[0]='1';
	thisstring2[1]='A';
	thisstring2[2]='8';
	thisstring2[3]='F';
	TL_LOGFILE_PRINT("\r\nDirect String Write 2: ");
	TL_LOGFILE_WRITE((char *)&thisstring2, sizeof(thisstring2));

	TL_LOGFILE_PRINT("\r\nBinary Write: ");
	TL_LOGFILE_WRITE((char *)&value, sizeof(value));

	char thisstring3[4];
	thisstring3[0]=0x01;
	thisstring3[1]=0xFE;
	thisstring3[2]=0x6A;
	thisstring3[3]=0x32;
	TL_LOGFILE_PRINT("\r\nBinary Write 2: ");
	TL_LOGFILE_WRITE((char *)&thisstring3, sizeof(thisstring3));

	TL_LOGFILE_PRINT("\r\nStart Time: ");
	TL_LOGFILE_WRITE_STRING_ARRAY(TL_TIME_STRING_FULL_SAFE);
	TL_LOGFILE_PRINT(".");
	TL_LOGFILE_WRITE_STRING_ARRAY(TL_TIME_STRING_TIME_USECS);
	
	TL_TIME_GET();
	TL_TIME_CONVERT_STRING_FULL_SAFE();
	TL_TIME_CONVERT_STRING_USECS();

	TL_LOGFILE_WRITE("\r\nStop Time: ", 13);
	TL_LOGFILE_WRITE_STRING_ARRAY(TL_TIME_STRING_FULL_SAFE);
	TL_LOGFILE_PRINT(".");
	TL_LOGFILE_WRITE_STRING_ARRAY(TL_TIME_STRING_TIME_USECS);

	TL_LOGFILE_STOP();
///~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~///

	
    return EXIT_SUCCESS;
}