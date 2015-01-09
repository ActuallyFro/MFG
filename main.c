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
		createSquare(consoleORchat,x, y, z, buildingMaterial, 0, 0, 0, 0);
	}
	else if(buildingType==2){
		createRectangle(consoleORchat,x, y, z, buildingMaterial, 0, 0, 0, 0);
	}
	printf("\n\n");
	return EXIT_SUCCESS;
}
