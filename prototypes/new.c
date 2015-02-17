/*
 ============================================================================
 Name        : sp_linux_copy.c
 Author      : Marko Martinović
 Description : Copy input file into output file
 ============================================================================
 */
 
#include "../include/TL_0_01d.h"
#define BUF_SIZE 8192
 
int main(int argc, char* argv[]) {
 
    int input_fd, output_fd;
    ssize_t ret_bytesRead_in, ret_bytesRead_out;
    char readInBuffer[BUF_SIZE];
 
    /* Are src and dest file name arguments missing */
    if(argc != 3){
        printf ("Usage: cp file1 file2");
        return 1;
    }
 
    /* Create input file descriptor */
    input_fd = open (argv [1], TL_FILE_FLAGS_OPEN_READ_BINARY);
    if (input_fd == -1) {
            perror ("open");
            return 2;
    }
 
    /* Create output file descriptor */
//    output_fd = open(argv[2], TL_FILE_FLAGS_OPEN_WRITE_NEWFILE, 0644);

//Append Sequence
    output_fd = open(argv[2], TL_FILE_FLAGS_OPEN_WRITE_APPENDFILE, 0644);
	
    if(output_fd == -1){
        //perror("open");
        //return 3;
		fprintf(stdout,"[WARNING] File not found! Creating new File");
		output_fd = open(argv[2], TL_FILE_FLAGS_OPEN_WRITE_NEWFILE, 0644);
	}
//END -- Append Sequence	
 
    /* Copy process */
    while((ret_bytesRead_in = read (input_fd, &readInBuffer, BUF_SIZE)) > 0){
            ret_bytesRead_out = write (output_fd, &readInBuffer, (ssize_t) ret_bytesRead_in);
            if(ret_bytesRead_out != ret_bytesRead_in){
                /* Write error */
                perror("write");
                return 4;
            }
    }
 
    /* Close file descriptors */
    close (input_fd);
    close (output_fd);
 
    return (EXIT_SUCCESS);
}/*
 ============================================================================
 Name        : sp_linux_copy.c
 Author      : Marko Martinović
 Description : Copy input file into output file
 ============================================================================
 */
 
#include "../include/TL_0_01d.h"
#define BUF_SIZE 8192
 
int main(int argc, char* argv[]) {
 
    int input_fd, output_fd;
    ssize_t ret_bytesRead_in, ret_bytesRead_out;
    char readInBuffer[BUF_SIZE];
 
    /* Are src and dest file name arguments missing */
    if(argc != 3){
        printf ("Usage: cp file1 file2");
        return 1;
    }
 
    /* Create input file descriptor */
    input_fd = open (argv [1], TL_FILE_FLAGS_OPEN_READ_BINARY);
    if (input_fd == -1) {
            perror ("open");
            return 2;
    }
 
    /* Create output file descriptor */
//    output_fd = open(argv[2], TL_FILE_FLAGS_OPEN_WRITE_NEWFILE, 0644);

//Append Sequence
    output_fd = open(argv[2], TL_FILE_FLAGS_OPEN_WRITE_APPENDFILE, 0644);
	
    if(output_fd == -1){
        //perror("open");
        //return 3;
		fprintf(stdout,"[WARNING] File not found! Creating new File");
		output_fd = open(argv[2], TL_FILE_FLAGS_OPEN_WRITE_NEWFILE, 0644);
	}
//END -- Append Sequence	
 
    /* Copy process */
    while((ret_bytesRead_in = read (input_fd, &readInBuffer, BUF_SIZE)) > 0){
            ret_bytesRead_out = write (output_fd, &readInBuffer, (ssize_t) ret_bytesRead_in);
            if(ret_bytesRead_out != ret_bytesRead_in){
                /* Write error */
                perror("write");
                return 4;
            }
    }
 
    /* Close file descriptors */
    close (input_fd);
    close (output_fd);
 
    return (EXIT_SUCCESS);
}