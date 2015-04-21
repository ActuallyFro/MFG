#define TL_HELP_MESSAGE		\
"MFtG - Minecraft Fill-tool Generator (v1.0)\
\r\n==========================================\
\r\nThis program is designed to help generate 'simple' geometric shapes\
\r\nin Minecraft. The output of the program will be the '/fill' commands\
\r\nneeded to render the specified shapes, and can be manually entered in\
\r\nthe chat window in game or bulk pasted into the server's console.\
\r\n\
\r\n**Simply put: This is a 3D printer for minecraft.**\
\r\n\
\r\nThe tool supports both commandline passing of fields for shapes or it can\
\r\nexecuted without fields to run in an interactive, Q&A mode.\
\r\n\
\r\n                                               ActuallyFro - April 2015	\
\r\nCommandline Flags\
\r\n==================\
\r\nThe following are all of the supported commandline flags that can be used\
\r\nwhen executing MFG from a shell:\
\r\n\
\r\nCoordinates\
\r\n-----------\
\r\n- -x \\<integer>: This sets the X-value starting point for the shape.\
\r\n- -y \\<integer>: This sets the Y-value starting point for the shape.\
\r\n- -z \\<integer>: This sets the Z-value starting point for the shape.\
\r\n\
\r\nThese values can be found by pressing F3 while running Minecraft.\
\r\n\
\r\n\
\r\nDimensions\
\r\n----------\
\r\nThe inputs for the shape's dimensions vary per shape, but ultimately these\
\r\nsettings allow can allow for custom skewing of the many of the shapes.\
\r\n\
\r\n- --depth (-d) \\<integer>: The North/South or 'into the screen' (z-axis)\
\r\n- --width (-w) \\<integer>: This sets the width going West/East (x-axis)\
\r\n- --height (-h) \\<integer>: This will set how tall the shape is (y-axis)\
\r\n\
\r\n\
\r\nShapes\
\r\n------\
\r\nAs of v1.0 there are eight basic shapes that can be selected. These are refered\
\r\nto by their respective 1 through 8 value as defined in the list below. Also,\
\r\nthe shapes have a 'Start' orientation from where they are measured/placed.\
\r\n\
\r\n- --shape (-s) \\<1-8>: Select a shape from the shape ID's.\
\r\n\
\r\n###Current Shape List\
\r\n1. Square (Dimensions: Width; Start: Bottom, SW Corner)\
\r\n2. Rectangle (Dimensions: Height, Width, Depth; Start: Bottom, SW Corner)\
\r\n3. Triangular Prism* (Dimensions:Width, Depth; Start: Bottom, SW Corner)\
\r\n4. Pyramid (Dimensions: Width; Start: Bottom, SW Corner)\
\r\n5. Sphere (Dimensions: Width; Start: Bottom, Center)\
\r\n6. Cylinder (Dimensions: Height, Width; Start: Center)\
\r\n7. Diamond (Dimension: Width; Start: Bottom, SW Corner)\
\r\n8. Cone (Dimensions: Height, Width; Start: Center)\
\r\n\
\r\n###X/Z Centering Math\
\r\n1. Square (Find SW Corner)\
\r\n2. Rectangle (Find SW Corner)\
\r\n3. Triangular Prism* (Find SW Corner, Subtract Width/2 from X, Add Depth/2 to Z)\
\r\n3. Triangular Prism Rotated (Find NW Corner, Subtract Width/2 from Z, Subtract Depth/2 to X)\
\r\n4. Pyramid (Find Desired Center: Subtract Width/2 from X, Add Width/2 to Z)\
\r\n5. Sphere (Not Needed)\
\r\n6. Cylinder (Not Needed)\
\r\n7. Diamond (Find Desired Center: Subtract Width/2 from X, Add Width/2 to Z)\
\r\n8. Cone (Not Needed)\
\r\n\
\r\n###Y Centering Math\
\r\n1. Square (Find Center: Subtract Height/2 from y)\
\r\n2. Rectangle (Find Center: Subtract Height/2 from y)\
\r\n3. Triangular Prism*  (Find Center: Subtract Height/2 from y)\
\r\n4. Pyramid  (Find Center: Subtract Width/2 from y)\
\r\n5. Sphere (Find Center: Subtract Width/2 from y)\
\r\n6. Cylinder (Find Center: Subtract Height/2 from y)\
\r\n7. Diamond (Find Center: Subtract Width/2 from Y)\
\r\n8. Cone (Find Center: Subtract Height/2 from y)\
\r\n\
\r\nMaterial\
\r\n--------\
\r\nThe material can be ANY minecraft ID that is in vanilla minecraft.\
\r\n(or ID's that are added in mods). Ensure you place any needed colons!\
\r\n\
\r\n- --material(-m) \\<minecraft name id>: any block ID.\
\r\n\
\r\n###Random ID Listing Website\
\r\nUse at your own risk: [Cheatsheet](http://minecraft-ids.grahamedgecombe.com/)\
\r\n\
\r\nFiles\
\r\n-----\
\r\nThe ability to output the fill commands to a fille has been added due to the\
\r\ncomplexity of the shapes (from poorly optimized area calculations). This allows\
\r\nfor the file to be accessed for a simple copy/paste of the fill commands.\
\r\n\
\r\n**By default the tool appends a file and __DOES NOT overwrite the file__**\
\r\n\
\r\n- --no-file (-nf): Triggers that no file is desired and the commands will\
\r\n                   be printed to the screen.\
\r\n\
\r\n- --output-default (-O): Output's the commands to 'MFG_output.txt'\
\r\n\
\r\n- --output-true: Signals the desire to use an output file, but manual\
\r\n                 entry of the file's name will be needed.\
\r\n\
\r\n- --output-name (-o) \\<string>: This allows for a renaming of the file's name.\
\r\n\
\r\n\
\r\nHollowed Shapes\
\r\n---------------\
\r\nThis command has been added since its conceivable that shapes would be desired\
\r\nto be hollowed out to help with the creation of structures/buildings. MFG \
\r\nwill 'shrink' the given inputs by the desired wall width, and automatically\
\r\nrender the commands to fill the shape with air blocks.\
\r\n\
\r\n- --nothollow (-nhw): Leaves the shape as solid-filled with the original\
\r\n                      material.\
\r\n\
\r\n- --hollow (-hw): Signals the desire to automatically generate air blocks, which\
\r\n                  will hollow out the shape.\
\r\n\
\r\n- --width-hollow (-wh) <integer>: Specifies the width/thickness of the \
\r\n                                  shape's walls.\
\r\n\
\r\nTarget Command Window\
\r\n---------------------\
\r\nGiven the complexity of some of the shapes it was determined that a server,\
\r\nconsole window would be the only realistic means to enter all of the fill\
\r\ncommands. The option allows the leading forward slash to be present, or not,\
\r\non the generated commands. \
\r\n\
\r\n- --console: Prints commands without the leading '/'.\
\r\n\
\r\n- --chat: Prints commands with the leading '/' \
\r\n\
\r\n\
\r\nRotation*\
\r\n---------\
\r\nRotation is currently only implemented with the Triangular Prism*. \
\r\nThe default orientation is the 'print' South to North while facing\
\r\nthe end showing the triangle. This will rotate the fill to from West to East.\
\r\n\
\r\n- --rotate: Turns the shape generation by 90 degrees clockwise.\
\r\n\
\r\nCommand Line Execution Examples\
\r\n-------------------------------\
\r\n###Mossy Stone Cone having a diameter of 10, and height of 5 @ <286,3,-277>: \
\r\nMFG -m minecraft:mossy_cobblestone -s 8 -x 286 -y 3 -z -277 --height 5 --width 10 -nf -nhw --console\
\r\n\
\r\n###Quartz Cylinder (diameter of 5, height of 50 @ <286,7,-277>) with a file: \
\r\nMFG -m minecraft:quartz_block -s 6 -x 286 -y 7 -z -277 -h 50 -w 5 --console -O -nhw\
\r\n\
\r\n###Brick Diamond  having a width of 10@ <276,14,-267> (center at 286,25,-277): \
\r\nMFG -m minecraft:brick_block -s 7 -x 276 -y 14 -z -267 -w 20 -hw -wh 1 --console -nf\
\r\n\
\r\n###Glowstone 'Rectangle', manually hollowed out (width of 21/19@) <276,24,-267>: \
\r\nMFG -m glowstone -s 2 -x 276 -y 24 -z -267 -w 21 -d 21 -h 1 --console -nf -nhw\
\r\nMFG -m air -s 2 -x 277 -y24 -z -268 -w 19 -d 19 -h 1 --console -nf -nhw\
\r\n\
\r\n###Glowstone Tri-Prism having a width of 1@ <281,22,-276>: \
\r\nMFG -m glowstone -s 3 -x 281 -y 22 -z -276 -w 10 -d 3 --console -nf -nhw\
\r\n\
\r\n###Glowstone Tri-Prism having a width of 1@ <281,22,-277>: \
\r\nMFG -m glowstone -s 3 -x 286 -y 22 -z -282 -w 10 -d 1 --console -nf -nhw --rotate\
\r\n\
\r\n###Nether Brick Cone having a diameter of 10, and height of 3 @ <0,100,0>: \
\r\nMFG -m double_stone_slab:6 -s 6 -x 0 -y 100 -z 0 -h 3 -w 10 -nf -nhw --console\
\r\n\
\r\n###Lava Sphere having a diameter of 100@ <0,100,0> with a default file: \
\r\nMFG -m glass -s 5 -x 286 -y 105 -z -277 -w 100 -hw -wh 1 --console -O\
\r\n*Just open the file, find an replace 'air' with lava.*\
\r\n\
\r\n###Diamond Pyramid having a width of 50@ <0,100,0> with a default file: \
\r\nMFG -m diamond_block -s 4 -x 211 -y 130 -z -202 -w 50 -hw -wh 1 --console -O\
\r\n\
\r\n\r\n"



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
			setHollowWidth(shapeType, Hollow_wall_width, &x, &y, &z, &Height, &Depth, &Width, RotationOrientation);
			createSquare(consoleORchat,x, y, z, "air", RotationOrientation, EAST, NoBaseOffset, NoCeilingCap, Width,OutputToFile,OutputFileName);
		}
	}
	else if(shapeType==2){
		getHeight("Rectangle",&Height,TL_PARSEARGS_OCCURED);
		getDepth("Rectangle",&Depth,TL_PARSEARGS_OCCURED);
		getWidth("Rectangle",&Width,TL_PARSEARGS_OCCURED);
		createRectangle(consoleORchat,x, y, z, buildingMaterial, RotationOrientation, EAST, NoBaseOffset, NoCeilingCap, Height, Depth, Width,  OutputToFile, OutputFileName);
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
			setHollowWidth(shapeType, Hollow_wall_width, &x, &y, &z, &Height, &Depth, &Width, RotationOrientation);
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
		getHeight("Cone",&Width,TL_PARSEARGS_OCCURED);
		getWidth("Cone",&Width,TL_PARSEARGS_OCCURED);
		createCone(consoleORchat,x, y, z, buildingMaterial, RotationOrientation, EAST, NoBaseOffset, NoCeilingCap, Height, Width, OutputToFile, OutputFileName);
		if(Hollow==TRUE){
			setHollowWidth(shapeType, Hollow_wall_width, &x, &y, &z, &Height, &Depth, &Width,RotationOrientation);
			createCone(consoleORchat,x, y, z, "air", RotationOrientation, EAST, NoBaseOffset, NoCeilingCap, Height, Width, OutputToFile, OutputFileName);
		}
	}
	printf("\n\n");
	
	return EXIT_SUCCESS;
}
