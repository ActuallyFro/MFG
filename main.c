#include <stdio.h>
#include <stdlib.h>

int main(){
	printf("\n\n\nMinecraft Fill Tool Building Generator");
	printf("\n======================================");
	int x,y,z;
	int xStart,yStart,zStart;
	int xStop,yStop,zStop;

	int i,j,k;
	int Length, Width, Height;
	int buildingType=0;
	char buildingMaterial[50];
	int shapesTotal=2;
	int consoleORchat=0;
	
	int MaxHeight=255;
	int MinHeight=0;
	int HeightOffset=0;//Imagine this as a method to skip the rendering of the first X layers
	int HeightStop=0;//Imagine this as a method to stop the rendering at layer X
	int Hollow=0;
	int EdgesOnly=0;
	
	printf("\nPlease enter a Material (e.g. minecraft:brick_block:");
	scanf("%[^\n]", buildingMaterial);
	
	printf("\n");
	printf("\nConsole or Chat (0/1)?: ");
	scanf("%i",&consoleORchat);
	
	printf("\n");
	printf("\n[1] Square");
	printf("\n[2] Rectangle");
	printf("\n[3] Triangular Prism");
	//printf("[4] Pyramid");
	//printf("[5] Sphere");
	//printf("[6] Cylinder");
	//printf("[7] Sphere");
	//printf("[8] Cone");
	//printf("[9] Doughnut");
	
	do{
	printf("\n\nWhat Type of shape would you like to create? " );
	scanf("%i",&buildingType);
	}while(0>buildingType&&buildingType>shapesTotal);
	
	printf("Please enter a starting <x> <y> <z>: ");
	scanf("%i %i %i",&x,&y,&z);
	
	xStart=x;
	yStart=y;
	zStart=z;

	if(buildingType==1){	
		printf("\n\nPlease Enter a Length: ");
		scanf("%i",&Length);
		
		if(Length>180 || Length < 1){
			printf("[WARNING] Size %i is out of bounds (greater than 180 or less than 1) attempting to correct size...");
			Length=Length%180;
		}

		//These never change
		xStart=x;
		zStart=z;
		
		printf("\n\nCopy and paste this into your console/chat:");
		for(i=0;i<Length;i++){
			yStart=i+y;
			xStop=xStart+Length;
			yStop=yStart;
			zStop=zStart-Length; //f'd up due to coords flipped: http://codeschool.org/3d-transformations-transcript/

			if(consoleORchat==0){
				printf("\nfill %i %i %i %i %i %i %s",xStart,yStart,zStart,xStop,yStop,zStop,buildingMaterial);
			}
			else{
				printf("\n/fill %i %i %i %i %i %i %s",xStart,yStart,zStart,xStop,yStop,zStop,buildingMaterial);
			}
		}
	}
	
	//printf("Processing: <%i> <%i> <%i>",x,y,z);
	return EXIT_SUCCESS;
}