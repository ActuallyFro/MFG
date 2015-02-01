#define TL_HELP_MESSAGE		\
"\n Minecraft Fill Tool (v0.1)\
\n ==========================\
\n To Receive a File:\
\n ------------------\
\n %s [--output <\"Name\">]\
\n\
\n  --output: Override the default output file name (ncp.out)\
\n Release Notes:\
\n --------------\
\n  By default this program will run in listening mode, and will wait for a\
\n  client to send a file. The default output file is ncp.out, and can be \
\n  overriden by the --output argument.\
\n\
\n  No attempts at security nor reliability have been made with respect to the\
\n  development of this software.\
\n\n                                                  ActuallyFro - Feb 2015\
\n\n",TL_ProgName

#include "TL_0_01c.h"
#include "Fillmc.h"


int main(int argc, char **argv){
	int	Verbose=0;
	int	MODE=0;
	char	IP_Dest[50]="127.0.0.1";
	char	IP_Port_Str[10];
	int		IP_Port=1337;
	char	OutputFile[500]="ncp.out";
	//Parse Args Vars
	char	*IP_Input_Dest = NULL;
	char	*IP_Input_Port = NULL;
	char	*File_Input = NULL;
	char	*File_Output = NULL;

	TL_PARSEARGS_INSTALL();
	TL_PARSEARGS_START(argc, argv,TL_ENFORCEPARSING_ON)
		TL_PARSEARGS_ADD_STR("--input",File_Input)
		TL_PARSEARGS_ADD_STR("--output",File_Output)
		TL_PARSEARGS_ADD_STR("--ip",IP_Input_Dest)
		TL_PARSEARGS_ADD_STR("--port",IP_Input_Port)
		TL_PARSEARGS_ADD_STR("-p",IP_Input_Port)
		TL_PARSEARGS_ADD_FLAG("-v", Verbose, 1)
		TL_PARSEARGS_ADD_FLAG("--verbose", Verbose, 1)
		TL_PARSEARGS_ENFORCE_EXCEPTION_ARGC_EQUALS_N(3)
	TL_PARSEARGS_STOP
	
	initVars();

	printBanner();
	getbuildingMaterial(buildingMaterial);

	getconsoleORchat(&consoleORchat);

	printShapes();
	getShape(&buildingType,shapesTotal);

	getStartCoords(&x,&y,&z);
/*
	getHeight(&Height);
	getWidth(&Width);
	getDepth(&Depth);
*/

/*
	do{
		printf("\n\nPlease Enter a Sphere Diameter (Width): ");
		scanf("%i",&Width);
		
		printf("\n\nPlease Enter a Height: ");
		scanf("%i",&Height);

		if(Height > HEIGHT_MAX){
			printf("\n[ERROR] The Height of the Sphere is out of the map! Forcing Width to be: %i",HEIGHT_MAX-y);
			Height=HEIGHT_MAX-y;
		}
	}while((Width*2)>=LAYER_MAX_SIZE || Height>HEIGHT_MAX);

	printf("\n\nCopy and paste this into your console/chat:");
*/	
	if(buildingType==1){
		createSquare(consoleORchat,x, y, z, buildingMaterial, NORTH, EAST, NoBaseOffset, NoCeilingCap);
	}
	else if(buildingType==2){
		createRectangle(consoleORchat,x, y, z, buildingMaterial, NORTH, EAST, NoBaseOffset, NoCeilingCap);
	}
	//else if(buildingType==3){
	//	createTriangularPrism(consoleORchat,x, y, z, buildingMaterial, NORTH, EAST, NoBaseOffset, NoCeilingCap);
	//}
	else if(buildingType==4){
		createPyramid(consoleORchat,x, y, z, buildingMaterial, NORTH, EAST, NoBaseOffset, NoCeilingCap);
	}
	else if(buildingType==5){
		createSphere(consoleORchat,x, y, z, buildingMaterial, NORTH, EAST, NoBaseOffset, NoCeilingCap);
	}
	else if(buildingType==6){
		getHeight("Cylinder",&Height);
		getWidth("Cylinder",&Width);
		createCylinder(consoleORchat,x, y, z, buildingMaterial, NORTH, EAST, NoBaseOffset, NoCeilingCap, Height, Width);
	}
	else if(buildingType==7){
		createDiamond(consoleORchat,x, y, z, buildingMaterial, NORTH, EAST, NoBaseOffset, NoCeilingCap);
	}
	printf("\n\n");
	return EXIT_SUCCESS;
}
