#include <stdio.h>
#include <stdlib.h>
#include "Fillmc.h"

int main(){
	initVars();

	printBanner();
	getbuildingMaterial(buildingMaterial);

	getconsoleORchat(&consoleORchat);

	printShapes();
	getShape(&buildingType,shapesTotal);

	getStartCoords(&x,&y,&z);

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
		createCylinder(consoleORchat,x, y, z, buildingMaterial, NORTH, EAST, NoBaseOffset, NoCeilingCap);
	}
	else if(buildingType==7){
		createDiamond(consoleORchat,x, y, z, buildingMaterial, NORTH, EAST, NoBaseOffset, NoCeilingCap);
	}
	printf("\n\n");
	return EXIT_SUCCESS;
}
