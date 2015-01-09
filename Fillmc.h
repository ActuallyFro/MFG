#define initVars() 			\
	int x,y,z;			\
	int buildingType=0;		\
	char buildingMaterial[50];	\
	int consoleORchat=0;		\
	int MaxHeight=255;		\
	int MinHeight=0;		\
	int HeightOffset=0;		\
	int HeightStop=0;		\
	int Hollow=0;			\
	int EdgesOnly=0;		\
	int shapesTotal=9

int getShape(int *Type, int TotalShapes){
        do{
                printf("\n\nWhat Type of shape would you like to create? " );
                scanf("%i",Type);
        }while(0>Type && *Type>TotalShapes);
        return EXIT_SUCCESS;
}

int getStartCoords(int *x,int *y,int *z){
	printf("Please enter a starting <x> <y> <z>: ");
	scanf("%i %i %i",x,y,z);
	return EXIT_SUCCESS;
}

int getbuildingMaterial(char *array){
	printf("\nPlease enter a Material (e.g. minecraft:brick_block:");
	scanf("%50[^\n]", array);

	return EXIT_SUCCESS;
}

int getconsoleORchat(int *var){
        printf("\n");
        printf("\nConsole or Chat (0/1)?: ");
        scanf("%i",var);
}

int printBanner(){
	printf("\n\n\nMinecraft Fill Tool Building Generator");
	printf("\n======================================");
	return EXIT_SUCCESS;
}

int printShapes(){
	printf("\n");
	printf("\n[1] Square");
	printf("\n[2] Rectangle");
	printf("\n[3] Triangular Prism");
	printf("\n[4] Pyramid");
	printf("\n[5] Sphere");
	printf("\n[6] Cylinder");
	printf("\n[7] Sphere");
	printf("\n[8] Cone");
	printf("\n[9] Doughnut");

	return EXIT_SUCCESS;
}

int createSquare(int consoleORchat, int x, int y, int z, char buildingMaterial[], int direction, int rotation, int pointStart, int pointStop){
	int Length, Width, Height;
	int xStart,yStart,zStart;
	int xStop,yStop,zStop;
	int i,j,k;

	xStart=x;
	yStart=y;
	zStart=z;

	printf("\n\nPlease Enter a Length: ");
		scanf("%i",&Length);

		if(Length>180 || Length < 1){
			printf("[WARNING] Size %i is out of bounds (greater than 180 or less than 1) attempting to correct size...",Length);
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
	return EXIT_SUCCESS;
}

int createRectangle(int consoleORchat, int x, int y, int z, char buildingMaterial[], int direction, int rotation, int pointStart, int pointStop){
	int Length, Width, Height;
	int xStart,yStart,zStart;
	int xStop,yStop,zStop;
	int i,j,k;

	xStart=x;
	yStart=y;
	zStart=z;

	printf("\n\nPlease Enter a Length: ");
		scanf("%i",&Length);

		if(Length>180 || Length < 1){
			printf("[WARNING] Size %i is out of bounds (greater than 180 or less than 1) attempting to correct size...",Length);
			Length=Length%180;
		}

	printf("\n\nPlease Enter a Width: ");
		scanf("%i",&Width);

		if(Width>180 || Width < 1){
			printf("[WARNING] Size %i is out of bounds (greater than 180 or less than 1) attempting to correct size...",Width);
			Width=Width%180;
		}

	printf("\n\nPlease Enter a Height: ");
		scanf("%i",&Height);

		if(Height>180 || Height < 1){
			printf("[WARNING] Size %i is out of bounds (greater than 180 or less than 1) attempting to correct size...",Height);
			Height=Height%180;
		}

		//These Never Change
		xStart=x;
		zStart=z;

		printf("\n\nCopy and paste this into your console/chat:");
		for(i=0;i<Height;i++){
			yStart=i+y;

			xStop=xStart+Length;
			yStop=yStart+i;
			zStop=zStart-Width; //f'd up due to coords flipped: http://codeschool.org/3d-transformations-transcript/

			if(consoleORchat==0){
				printf("\nfill %i %i %i %i %i %i %s",xStart,yStart,zStart,xStop,yStop,zStop,buildingMaterial);
			}
			else{
				printf("\n/fill %i %i %i %i %i %i %s",xStart,yStart,zStart,xStop,yStop,zStop,buildingMaterial);
			}
		}
	return EXIT_SUCCESS;
}
