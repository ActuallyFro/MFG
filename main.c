#define TL_HELP_MESSAGE		\
"\n Minecraft Fill Shape Generator (v0.1)\
\n =====================================\
\n This program is designed to help generate 'simple' geometric shapes\
\n in Minecraft. The output of the program will be the '/fill' commands\
\n needed to render the specified shapes, and can be manually entered in\
\n the chat window in game or bulk pasted into the server's console.\
\n\
\n The tool supports both commandline passing of fields for shapes or it can\
\n executed without fields to run in an interactive, Q&A mode.\
\n\
\n                                                ActuallyFro - Feb 2015		\
\n\
\n Example Commandline Excecution:\
\n -------------------------------\
\n %s --shape 6 -x 0 -y 100 -z 0 --height 3 --width 10\
\n\
\n\n",TL_ProgName

#include "include/TL_0_01d.h"
#include "include/Fillmc.h"


int main(int argc, char **argv){
	TL_TIME_INIT();
	TL_TIME_INIT_STRING_FULL_SAFE_ARRAY();
	TL_TIME_INIT_STRING_USEC_ARRAY();
	TL_TIME_GET();
	TL_TIME_CONVERT_STRING_FULL_SAFE();
	TL_TIME_CONVERT_STRING_USECS();
	
//	int	Rotate=0;
//	int	MODE=0;

	initVars();
/*
	char *OutputFileName = "MFSG_output.txt";
	int OutputToFile = FALSE;					
*/
	TL_PARSEARGS_INSTALL();
	
	TL_PARSEARGS_START(TL_ENFORCEPARSING_ON)
		TL_PARSEARGS_ADD_INT("-x",x)
		TL_PARSEARGS_ADD_INT("-y",y)
		TL_PARSEARGS_ADD_INT("-z",z)
		TL_PARSEARGS_ADD_INT("-h",Height)
		TL_PARSEARGS_ADD_INT("-w",Width)
		TL_PARSEARGS_ADD_INT("--height",Height)
		TL_PARSEARGS_ADD_INT("--width",Width)
		TL_PARSEARGS_ADD_INT("--shape",shapeType)
		TL_PARSEARGS_ADD_INT("-s",shapeType)
		TL_PARSEARGS_ADD_FLAG("--printshapes",printshapes,TRUE)
		TL_PARSEARGS_ADD_STR("--material",parsedmaterial)
		TL_PARSEARGS_ADD_STR("--output-name",parsedOutputFileName)
		TL_PARSEARGS_ADD_STR("-o",parsedOutputFileName)
		TL_PARSEARGS_ADD_FLAG("--output-true", OutputToFile, TRUE)
		TL_PARSEARGS_ADD_FLAG("-O", OutputToFile, TRUE)
		TL_PARSEARGS_ADD_STR("-m",parsedmaterial)
		TL_PARSEARGS_ADD_FLAG("--hollow", Hollow, TRUE)
		TL_PARSEARGS_ADD_FLAG("-hw", Hollow, TRUE)
		TL_PARSEARGS_ADD_FLAG("--nothollow", Hollow, FALSE)
		TL_PARSEARGS_ADD_FLAG("-nhw", Hollow, FALSE)
		TL_PARSEARGS_ADD_FLAG("--console", consoleORchat, 0)
		TL_PARSEARGS_ADD_FLAG("--chat", consoleORchat, 1)
		TL_PARSEARGS_ADD_FLAG("--quiet", quiet, TRUE)
	TL_PARSEARGS_STOP;
//		TL_PARSEARGS_ADD_FLAG("--rotate", Rotate, 1)
//		TL_PARSEARGS_ADD_FLAG("-r", Rotate, 1)
//		TL_PARSEARGS_ENFORCE_EXCEPTION_ARGC_GREATER_THAN_N(2)
//		TL_PARSEARGS_ADD_INT("-dy1",HeightOffsetStart)
//		TL_PARSEARGS_ADD_INT("-dy2",HeightOffsetStop)

	if(parsedOutputFileName != NULL && parsedOutputFileName[0] != '\0'){
		strcpy(OutputFileName,parsedOutputFileName);
		OutputToFile=TRUE;
	}
	else{
		getFileTrueORFalse(&OutputToFile);
		getFileName(OutputFileName);
	}
	
	if(printshapes==TRUE){
		shapeType=-1;
		getShape(&shapeType,shapesTotal,TL_PARSEARGS_OCCURED);
		return EXIT_SUCCESS;
	}
		
	if(quiet!=TRUE){
		printBanner();
	}
	
	if(parsedmaterial != NULL && parsedmaterial[0] != '\0'){
		strcpy(buildingMaterial,parsedmaterial);
	}
	else{
		getbuildingMaterial(buildingMaterial);
	}
	getconsoleORchat(&consoleORchat);
	getShape(&shapeType,shapesTotal,TL_PARSEARGS_OCCURED);
	getHollow(&Hollow,&Hollow_wall_width);
	getStartCoords(&x,&y,&z,TL_PARSEARGS_OCCURED);

	if(shapeType==1){
		getWidth("Square",&Width,TL_PARSEARGS_OCCURED);
		createSquare(consoleORchat,x, y, z, buildingMaterial, NORTH, EAST, NoBaseOffset, NoCeilingCap, Width);
		if(Hollow==TRUE){
			setHollowWidth(shapeType, Hollow_wall_width, &x, &y, &z, &Height, &Depth, &Width);
			createSquare(consoleORchat,x, y, z, "air", NORTH, EAST, NoBaseOffset, NoCeilingCap, Width);
		}
	}
	else if(shapeType==2){
		getHeight("Rectangle",&Height,TL_PARSEARGS_OCCURED);
		getDepth("Rectangle",&Depth,TL_PARSEARGS_OCCURED);
		getWidth("Rectangle",&Width,TL_PARSEARGS_OCCURED);
		createRectangle(consoleORchat,x, y, z, buildingMaterial, NORTH, EAST, NoBaseOffset, NoCeilingCap, Height, Depth, Width);
		if(Hollow==TRUE){
			setHollowWidth(shapeType, Hollow_wall_width, &x, &y, &z, &Height, &Depth, &Width);
			createRectangle(consoleORchat,x, y, z, "air", NORTH, EAST, NoBaseOffset, NoCeilingCap, Height, Depth, Width);
		}
	}
	//else if(shapeType==3){
	//	getDepth("Rectangle",&Depth,TL_PARSEARGS_OCCURED);
	//	getWidth("Rectangle",&Width,TL_PARSEARGS_OCCURED);
	//	createTriangularPrism(consoleORchat,x, y, z, buildingMaterial, NORTH, EAST, NoBaseOffset, NoCeilingCap, Height, Width);
	//}
	else if(shapeType==4){
		getWidth("Pyramid",&Width,TL_PARSEARGS_OCCURED);
		createPyramid(consoleORchat,x, y, z, buildingMaterial, NORTH, EAST, NoBaseOffset, NoCeilingCap, Width);
		if(Hollow==TRUE){
			setHollowWidth(shapeType, Hollow_wall_width, &x, &y, &z, &Height, &Depth, &Width);
			createPyramid(consoleORchat,x, y, z, "air", NORTH, EAST, NoBaseOffset, NoCeilingCap, Width);
		}
	}
	else if(shapeType==5){
//		getHeight("Sphere",&Height);
		getWidth("Sphere",&Width,TL_PARSEARGS_OCCURED);
		createSphere(consoleORchat,x, y, z, buildingMaterial, NORTH, EAST, NoBaseOffset, NoCeilingCap, Width);
		if(Hollow==TRUE){
			setHollowWidth(shapeType, Hollow_wall_width, &x, &y, &z, &Height, &Depth, &Width);
			createSphere(consoleORchat,x, y, z, "air", NORTH, EAST, NoBaseOffset, NoCeilingCap, Width);
		}
	}
	else if(shapeType==6){
		getHeight("Cylinder",&Height,TL_PARSEARGS_OCCURED);
		getWidth("Cylinder",&Width,TL_PARSEARGS_OCCURED);
		createCylinder(consoleORchat,x, y, z, buildingMaterial, NORTH, EAST, NoBaseOffset, NoCeilingCap, Height, Width);
		if(Hollow==TRUE){
			setHollowWidth(shapeType, Hollow_wall_width, &x, &y, &z, &Height, &Depth, &Width);
			createCylinder(consoleORchat,x, y, z, "air", NORTH, EAST, NoBaseOffset, NoCeilingCap, Height, Width);
		}
	}
	else if(shapeType==7){
		getWidth("Diamond",&Width,TL_PARSEARGS_OCCURED);
		createDiamond(consoleORchat,x, y, z, buildingMaterial, NORTH, EAST, NoBaseOffset, NoCeilingCap, Width);
		if(Hollow==TRUE){
			setHollowWidth(shapeType, Hollow_wall_width, &x, &y, &z, &Height, &Depth, &Width);
			createDiamond(consoleORchat,x, y, z, "air", NORTH, EAST, NoBaseOffset, NoCeilingCap, Width);
		}
	}
	printf("\n\n");
	
	//Play with Named File
	if(OutputToFile==TRUE){
		TL_FILE_IO_INSTALL_NAMED(FILE1);
		TL_FILE_OPEN_WRITE_MODE_APPEND_NAMED(OutputFileName, 0644,FILE1);
		TL_FILE_WRITE_STRING_ARRAY_NAMED(FILE1,"Sup!?"); 
		TL_FILE_WRITE_STRING_ARRAY_NAMED(FILE1,"\r\nStart Time: ");
		TL_FILE_WRITE_NAMED(FILE1,(char *)&TL_TIME_STRING_FULL_SAFE,strlen(TL_TIME_STRING_FULL_SAFE));
		TL_FILE_WRITE_STRING_ARRAY_NAMED(FILE1,".");
		TL_FILE_WRITE_NAMED(FILE1,(char *)&TL_TIME_STRING_TIME_USECS,strlen(TL_TIME_STRING_TIME_USECS));
		TL_TIME_GET();
		TL_TIME_CONVERT_STRING_FULL_SAFE();
		TL_TIME_CONVERT_STRING_USECS();
		TL_FILE_WRITE_STRING_ARRAY_NAMED(FILE1,"\r\nEnd Time: ");
		TL_FILE_WRITE_NAMED(FILE1,(char *)&TL_TIME_STRING_FULL_SAFE,strlen(TL_TIME_STRING_FULL_SAFE));
		TL_FILE_WRITE_STRING_ARRAY_NAMED(FILE1,".");
		TL_FILE_WRITE_NAMED(FILE1,(char *)&TL_TIME_STRING_TIME_USECS,strlen(TL_TIME_STRING_TIME_USECS));
		TL_FILE_CLOSE_NAMED(FILE1);
	}
	return EXIT_SUCCESS;
}
