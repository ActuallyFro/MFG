#define TL_HELP_MESSAGE		\
" Minecraft Fill-tool Generator (v0.1)\
\r\n =====================================\
\r\n This program is designed to help generate 'simple' geometric shapes\
\r\n in Minecraft. The output of the program will be the '/fill' commands\
\r\n needed to render the specified shapes, and can be manually entered in\
\r\n the chat window in game or bulk pasted into the server's console.\
\r\n\
\r\n The tool supports both commandline passing of fields for shapes or it can\
\r\n executed without fields to run in an interactive, Q&A mode.\
\r\n\
\r\n                                                ActuallyFro - April 2015	\
\r\n\
\r\n Example Commandline Excecution:\
\r\n -------------------------------\
\r\n %s --shape 6 -x 0 -y 100 -z 0 --height 3 --width 10\
\r\n\
\r\n\r\n",TL_ProgName

#include "include/TL_0_01f.h"
#include "include/Fillmc.h"

int main(int argc, char **argv){
	TL_TIME_INIT();
	TL_TIME_INIT_STRING_FULL_SAFE_ARRAY();
	TL_TIME_INIT_STRING_USEC_ARRAY();
	TL_TIME_GET();
	TL_TIME_CONVERT_STRING_FULL_SAFE();
	TL_TIME_CONVERT_STRING_USECS();
	
	initVars();

	TL_PARSEARGS_INSTALL();
	
	TL_PARSEARGS_START(TL_ENFORCEPARSING_ON)
		TL_PARSEARGS_ADD_INT("-x",x)
		TL_PARSEARGS_ADD_INT("-y",y)
		TL_PARSEARGS_ADD_INT("-z",z)
		TL_PARSEARGS_ADD_INT("-d",Depth)
		TL_PARSEARGS_ADD_INT("-w",Width)
		TL_PARSEARGS_ADD_INT("-h",Height)
		TL_PARSEARGS_ADD_INT("--depth",Depth)
		TL_PARSEARGS_ADD_INT("--width",Width)
		TL_PARSEARGS_ADD_INT("--height",Height)
		TL_PARSEARGS_ADD_INT("--shape",shapeType)
		TL_PARSEARGS_ADD_INT("-s",shapeType)
		TL_PARSEARGS_ADD_FLAG("--printshapes",printshapes,TRUE)
		TL_PARSEARGS_ADD_STR("--material",parsedmaterial)
		TL_PARSEARGS_ADD_STR("--output-name",parsedOutputFileName)
		TL_PARSEARGS_ADD_STR("-o",parsedOutputFileName)
		TL_PARSEARGS_ADD_FLAG("--output-true", OutputToFile, TRUE)
		TL_PARSEARGS_ADD_FLAG("--no-file", OutputToFile, -999)
		TL_PARSEARGS_ADD_FLAG("-nf", OutputToFile, -999)
		TL_PARSEARGS_ADD_FLAG("-O", OutputToFile, 100)
		TL_PARSEARGS_ADD_FLAG("--output-default", OutputToFile, 100)
		TL_PARSEARGS_ADD_STR("-m",parsedmaterial)
		TL_PARSEARGS_ADD_FLAG("--hollow", Hollow, TRUE)
		TL_PARSEARGS_ADD_FLAG("-hw", Hollow, TRUE)
		TL_PARSEARGS_ADD_FLAG("--nothollow", Hollow, FALSE)
		TL_PARSEARGS_ADD_FLAG("-nhw", Hollow, FALSE)
		TL_PARSEARGS_ADD_INT("--width-hollow", Hollow_wall_width)
		TL_PARSEARGS_ADD_INT("-wh", Hollow_wall_width)
		TL_PARSEARGS_ADD_FLAG("--console", consoleORchat, 0)
		TL_PARSEARGS_ADD_FLAG("--chat", consoleORchat, 1)
		TL_PARSEARGS_ADD_FLAG("--quiet", quiet, TRUE)
		TL_PARSEARGS_ADD_FLAG("-q", quiet, TRUE)
		TL_PARSEARGS_ADD_FLAG("--rotate", RotationOrientation, WEST)
		TL_PARSEARGS_ADD_FLAG("-r", RotationOrientation, WEST)
	TL_PARSEARGS_STOP;

	if(quiet!=TRUE){
		printBanner();
	}
	
	if(printshapes==TRUE){
		shapeType=-1;
		getShape(&shapeType,shapesTotal,TL_PARSEARGS_OCCURED);
		return EXIT_SUCCESS;
	}
			
	if(parsedmaterial != NULL && parsedmaterial[0] != '\0'){
		strcpy(buildingMaterial,parsedmaterial);
	}
	else{
		getbuildingMaterial(buildingMaterial);
	}
	getHollow(&Hollow,&Hollow_wall_width);
	getStartCoords(&x,&y,&z,TL_PARSEARGS_OCCURED);
	getconsoleORchat(&consoleORchat);

	if(parsedOutputFileName != NULL && parsedOutputFileName[0] != '\0'){
		strcpy(OutputFileName,parsedOutputFileName);
		OutputToFile=TRUE;
	}
	else{
		if(OutputToFile!=-999){ //no file workaround
			if(OutputToFile!=100){
				getFileTrueORFalse(&OutputToFile);
				if(OutputToFile==TRUE){
					getFileName(OutputFileName);
				}
			}
			else{OutputToFile=TRUE;}
		}
	}
	
	getShape(&shapeType,shapesTotal,TL_PARSEARGS_OCCURED);

	if(shapeType==1){
		getWidth("Square",&Width,TL_PARSEARGS_OCCURED);
		createSquare(consoleORchat,x, y, z, buildingMaterial, RotationOrientation, EAST, NoBaseOffset, NoCeilingCap, Width, OutputToFile, OutputFileName);
		if(Hollow==TRUE){
			setHollowWidth(shapeType, Hollow_wall_width, &x, &y, &z, &Height, &Depth, &Width,RotationOrientation);
			createSquare(consoleORchat,x, y, z, "air", RotationOrientation, EAST, NoBaseOffset, NoCeilingCap, Width,OutputToFile,OutputFileName);
		}
	}
	else if(shapeType==2){
		getHeight("Rectangle",&Height,TL_PARSEARGS_OCCURED);
		getDepth("Rectangle",&Depth,TL_PARSEARGS_OCCURED);
		getWidth("Rectangle",&Width,TL_PARSEARGS_OCCURED);
		createRectangle(consoleORchat,x, y, z, buildingMaterial, RotationOrientation, EAST, NoBaseOffset, NoCeilingCap, Height, Depth, Width, OutputToFile, OutputFileName);
		if(Hollow==TRUE){
			setHollowWidth(shapeType, Hollow_wall_width, &x, &y, &z, &Height, &Depth, &Width,RotationOrientation);
			createRectangle(consoleORchat,x, y, z, "air", RotationOrientation, EAST, NoBaseOffset, NoCeilingCap, Height, Depth, Width, OutputToFile, OutputFileName);
		}
	}
	else if(shapeType==3){
		getWidth("Triangular Prism",&Width,TL_PARSEARGS_OCCURED);
		getDepth("Triangular Prism",&Depth,TL_PARSEARGS_OCCURED);
		createTriangularPrism(consoleORchat,x, y, z, buildingMaterial, RotationOrientation, EAST, NoBaseOffset, NoCeilingCap, Depth, Width, OutputToFile, OutputFileName);
		if(Hollow==TRUE){
			setHollowWidth(shapeType, Hollow_wall_width, &x, &y, &z, &Height, &Depth, &Width,RotationOrientation);
			createTriangularPrism(consoleORchat,x, y, z, "air", RotationOrientation, EAST, NoBaseOffset, NoCeilingCap, Depth, Width, OutputToFile, OutputFileName);
		}
	}
	else if(shapeType==4){
		getWidth("Pyramid",&Width,TL_PARSEARGS_OCCURED);
		createPyramid(consoleORchat,x, y, z, buildingMaterial, RotationOrientation, EAST, NoBaseOffset, NoCeilingCap, Width, OutputToFile, OutputFileName);
		if(Hollow==TRUE){
			setHollowWidth(shapeType, Hollow_wall_width, &x, &y, &z, &Height, &Depth, &Width,RotationOrientation);
			createPyramid(consoleORchat,x, y, z, "air", RotationOrientation, EAST, NoBaseOffset, NoCeilingCap, Width, OutputToFile, OutputFileName);
		}
	}
	else if(shapeType==5){
		getWidth("Sphere",&Width,TL_PARSEARGS_OCCURED);
		createSphere(consoleORchat,x, y, z, buildingMaterial, RotationOrientation, EAST, NoBaseOffset, NoCeilingCap, Width, OutputToFile, OutputFileName);
		if(Hollow==TRUE){
			setHollowWidth(shapeType, Hollow_wall_width, &x, &y, &z, &Height, &Depth, &Width,RotationOrientation);
			createSphere(consoleORchat,x, y, z, "air", RotationOrientation, EAST, NoBaseOffset, NoCeilingCap, Width, OutputToFile, OutputFileName);
		}
	}
	else if(shapeType==6){
		getHeight("Cylinder",&Height,TL_PARSEARGS_OCCURED);
		getWidth("Cylinder",&Width,TL_PARSEARGS_OCCURED);
		createCylinder(consoleORchat,x, y, z, buildingMaterial, RotationOrientation, EAST, NoBaseOffset, NoCeilingCap, Height, Width, OutputToFile, OutputFileName);
		if(Hollow==TRUE){
			setHollowWidth(shapeType, Hollow_wall_width, &x, &y, &z, &Height, &Depth, &Width,RotationOrientation);
			createCylinder(consoleORchat,x, y, z, "air", RotationOrientation, EAST, NoBaseOffset, NoCeilingCap, Height, Width, OutputToFile, OutputFileName);
		}
	}
	else if(shapeType==7){
		getWidth("Diamond",&Width,TL_PARSEARGS_OCCURED);
		createDiamond(consoleORchat,x, y, z, buildingMaterial, RotationOrientation, EAST, NoBaseOffset, NoCeilingCap, Width, OutputToFile, OutputFileName);
		if(Hollow==TRUE){
			setHollowWidth(shapeType, Hollow_wall_width, &x, &y, &z, &Height, &Depth, &Width,RotationOrientation);
			createDiamond(consoleORchat,x, y, z, "air", RotationOrientation, EAST, NoBaseOffset, NoCeilingCap, Width, OutputToFile, OutputFileName);
		}
	}
	else if(shapeType==8){
		getWidth("Cone",&Width,TL_PARSEARGS_OCCURED);
		getHeight("Cone",&Width,TL_PARSEARGS_OCCURED);
		createCone(consoleORchat,x, y, z, buildingMaterial, RotationOrientation, EAST, NoBaseOffset, NoCeilingCap, Height, Width, OutputToFile, OutputFileName);
		if(Hollow==TRUE){
			setHollowWidth(shapeType, Hollow_wall_width, &x, &y, &z, &Height, &Depth, &Width,RotationOrientation);
			createCone(consoleORchat,x, y, z, "air", RotationOrientation, EAST, NoBaseOffset, NoCeilingCap, Height, Width, OutputToFile, OutputFileName);
		}
	}
	printf("\n\n");
	
	return EXIT_SUCCESS;
}
