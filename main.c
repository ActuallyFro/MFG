#define TL_HELP_MESSAGE		\
"\n Minecraft Fill Tool (v0.1)\
\n ==========================\
\n This program is designed to help generate 'simple' geometric shapes	 \
\n in Minecraft. The output of the program will be the '/fll' commands   \
\n needed to render the specified shapes, and can be manually entered in \
\n the chat window in game or bulk pasted into the server's console. 	 \
\n\
\n The tool supports both commandline passing of fields for shapes or it can \
\n executed without fields to run in an interactive, Q&A mode.\
\n\
\n Example Commandline Excecution:\
\n -------------------------------\
\n %s --shape Cylinder -x 0 -y 100 -z 0 \
\n\t\t\t\t --Height 3 --Width 10\
\n\
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
	char	*Passed_Shape = NULL;
	char	*IP_Input_Port = NULL;
	char	*File_Input = NULL;
	char	*File_Output = NULL;
	initVars();
	
	TL_PARSEARGS_INSTALL();
	
	TL_PARSEARGS_START(argc, argv,TL_ENFORCEPARSING_ON)
		TL_PARSEARGS_ADD_INT("-x",x)
		TL_PARSEARGS_ADD_INT("-y",y)
		TL_PARSEARGS_ADD_INT("-z",z)
		TL_PARSEARGS_ADD_STR("--shape",Passed_Shape)
		TL_PARSEARGS_ADD_STR("-p",IP_Input_Port)
		TL_PARSEARGS_ADD_FLAG("-v", Verbose, 1)
		TL_PARSEARGS_ADD_FLAG("--verbose", Verbose, 1)
	TL_PARSEARGS_STOP

	//		TL_PARSEARGS_ENFORCE_EXCEPTION_ARGC_GREATER_THAN_N(2)

	if(argc>1){
		printf("\nVariables Passed!");
		return EXIT_SUCCESS;
	}
	
	if(Passed_Shape!=NULL){
		printf("\n");
		return EXIT_SUCCESS;
	}

	/*
	if( x!=0 || y!=0 || z!=0 ){
		printf("Passed <x,y,z>: <%i,%i,%i>",x,y,z);
		return EXIT_SUCCESS;
	}
	*/
	
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
