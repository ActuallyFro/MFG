#define TL_HELP_MESSAGE		\
"\n u sec timer\
\n ===========\
\n A program that shows time strings having microsecond resolution...\
\n\
\n                                                ActuallyFro - Feb 2015		\
\n\
\n Example Commandline Excecution:\
\n -------------------------------\
\n %s \
\n\
\n\n",TL_ProgName
#include <sys/time.h>
#include "../../include/TL_0_01d.h"

int main(int argc, char **argv) {
	int i;
	TL_TIME_INIT();
	TL_TIME_INIT_STRING_FULL_SAFE_ARRAY();
	TL_TIME_INIT_STRING_USEC_ARRAY();

	TL_TIME_GET();
	TL_TIME_CONVERT_STRING_FULL_SAFE();
	TL_TIME_CONVERT_STRING_USECS();
	printf("%s.%s",TL_TIME_STRING_FULL_SAFE,TL_TIME_STRING_TIME_USECS);

	//Kill time
	for(i=0;i<1000000000;){
		i+=1;
	}
	
	TL_TIME_GET();
	TL_TIME_CONVERT_STRING_FULL_SAFE();
	TL_TIME_CONVERT_STRING_USECS();
	
	printf("\n%s.%s",TL_TIME_STRING_FULL_SAFE,TL_TIME_STRING_TIME_USECS);
	
    return EXIT_SUCCESS;
}