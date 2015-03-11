#include <math.h>

#define HEIGHT_MAX 255
#define HEIGHT_MIN 1
#define COORD_MAX 9999999
#define WIDTH_MAX 176
#define WIDTH_MIN 1
#define DEPTH_MAX 176
#define DEPTH_MIN 1
#define LAYER_MAX_SIZE 32768
#define NORTH 1
#define SOUTH -1
#define EAST 1
#define WEST -1
#define NoBaseOffset 0
#define NoCeilingCap 0

#define PI 3.14159265
#define Sqrt_2 1.41421356
#define Sqrt_2_over_2 0.70710678

#define initVars() 								\
	int x=COORD_MAX; 							\
	int y=HEIGHT_MIN-1;							\
	int z=COORD_MAX;							\
	int shapeType=0;							\
	char buildingMaterial[50];					\
	char OutputFileName[200]="MFSG_output.txt";	\
	int consoleORchat=-1;						\
	int Hollow=-1;								\
	int Hollow_wall_width=0;					\
	int shapesTotal=9;							\
	int Width=0;								\
	int Depth=0;								\
	int printshapes=FALSE;						\
	int quiet=FALSE;							\
	char *parsedmaterial = NULL;				\
	char *parsedOutputFileName = NULL;			\
	int OutputToFile = -1;						\
	int Height=0

//	int Direction_NorthSouth;	
//	int Direction_WestEast;		
//	int EdgesOnly=0;
//	int HeightOffsetStart=0;
//	int HeightOffsetStop=0;		
//	int MaxHeight=HEIGHT_MAX;
//	int MinHeight=0;			


int getHollow(int * hollow, int * hollow_wall_width){
	if(*hollow==-1){
		do{
			printf("\n");
			printf("\nWould you like the shape to be hollow 1/0(T/F)?: ");
			scanf("%i",hollow);
		}while(*hollow!=0 && *hollow!=1);
	}
	
	if(*hollow==TRUE){
		if(*hollow_wall_width<=0){

			do{
				printf("\n");
				printf("\nHow wide shall the wall of the hollowed the shape be?: ");
				scanf("%i",hollow_wall_width);
			}while(*hollow_wall_width<1);
		
			//*hollow_wall_width*=2;
		}
		if(*hollow_wall_width>WIDTH_MAX){
			printf("\n[WARNING] Given value, %i, is larger than the typical maximum view distance (%i)!\n",*hollow_wall_width/2,WIDTH_MAX);
		}
	}
	return EXIT_SUCCESS;
}

int setHollowWidth(int shapeType, int Hollow_wall_width, int *x,int *y,int *z, int * Height, int * Depth, int * Width){
	//printf("\n[DEBUGGING] Hollow is true! Hollow Width: %i", Hollow_wall_width);

	if(shapeType==1){ //Square
		//Width
		*Width-=(Hollow_wall_width*2);
		*x+=Hollow_wall_width;
		*y+=Hollow_wall_width;
		*z-=Hollow_wall_width;
	}
	else if(shapeType==2){ //Rectangle
		//Height
		//Depth
		//Width
		*Height-=(Hollow_wall_width*2);
		*Depth-=(Hollow_wall_width*2);
		*Width-=(Hollow_wall_width*2);		
		*x+=Hollow_wall_width;
		*y+=Hollow_wall_width;
		*z-=Hollow_wall_width;
	}
	else if(shapeType==3){ //Triangular Prism
		//Depth
		//Width
		*Depth-=(Hollow_wall_width*2);
		*Width-=(Hollow_wall_width*2);		
	}
	else if(shapeType==4){ //Pyramid
		//Width
		*Width-=(Hollow_wall_width*2);		
		*x+=Hollow_wall_width;
		*y+=Hollow_wall_width;
		*z-=Hollow_wall_width;
	}
	else if(shapeType==5){ //Sphere
		//Width
		*Width-=(Hollow_wall_width*2);		
//		*x+=Hollow_wall_width;
//		*y+=(Hollow_wall_width*2); //<--- should be the only one that changes; but should be the same delta as Width
//		*z-=Hollow_wall_width;
	}
	else if(shapeType==6){ //Cylinder
		//Height
		//Width
		*Height-=(Hollow_wall_width*2);
		*Width-=(Hollow_wall_width*2);		
//		*x+=Hollow_wall_width;
		*y+=Hollow_wall_width;
//		*z-=Hollow_wall_width;
	}
	else if(shapeType==7){ //Diamond
		//Width
		*Width-=(Hollow_wall_width*2);		
		*x+=Hollow_wall_width;
		*y+=Hollow_wall_width;
		*z-=Hollow_wall_width;
	}
	
	return EXIT_SUCCESS;
}
	
int getShape(int *Type, int TotalShapes, int Args_Parsed){
	int shape=*Type;
//	printf("\n\n[DEBUGGING] shape:%i Total shapes:%i\n",shape,TotalShapes);
	if(shape<1 || shape>TotalShapes){
		printf("\n");
		printf("\n[1] Square");
		printf("\n[2] Rectangle");
		printf("\n[3] Triangular Prism");
		printf("\n[4] Pyramid");
		printf("\n[5] Sphere");
		printf("\n[6] Cylinder");
		printf("\n[7] Diamond");
		printf("\n[8] Cone");
		printf("\n[9] Doughnut");
		printf("\n");
	}

	if(shape<-1 || shape==0 || shape>TotalShapes){
		if(Args_Parsed==TRUE && shape!=0){
			printf("\n[WARNING] The passed value for shape (%i) is not valid!\n",shape);
		}
		do{
			printf("\n\nWhat Type of shape would you like to create? " );
			scanf("%i",Type);
		}while(0>Type && *Type>TotalShapes);
	}
	
	return EXIT_SUCCESS;
}

int getStartCoords(int *x,int *y,int *z, int Args_Parsed){
	int val_x=*x;
	int val_y=*y;
	int val_z=*z;

	/*
	if(Args_Parsed==TRUE && val_x!=COORD_MAX){
		if(val_x>WIDTH_MAX){
			printf("\n[WARNING] x (%i) is larger than the typical maximum view distance (%i)!\n",val_x,WIDTH_MAX);
		}
	}
	*/
	if(val_x==COORD_MAX){
		printf("\nPlease enter a value for x: ");
		scanf("%i",x);
	}
	
	if(Args_Parsed==TRUE && val_y!=(HEIGHT_MIN-1)){
		if(val_y>HEIGHT_MAX || val_y < HEIGHT_MIN){
			printf("\n[WARNING] y (%i) is out of bounds(%i-%i)!\n",val_y,HEIGHT_MIN,HEIGHT_MAX);
			val_y=(HEIGHT_MIN-1);
		}
	}
	if(val_y==(HEIGHT_MIN-1)){
		printf("\nPlease enter a value for y: ");
		scanf("%i",y);
	}
	/*
	if(Args_Parsed==TRUE && val_z!=COORD_MAX){
		if(val_z>WIDTH_MAX){
			printf("\n[WARNING] z (%i) is larger than the typical maximum view distance (%i)!\n",val_z,WIDTH_MAX);
		}
	}
	*/
	if(val_z==COORD_MAX){
		printf("\nPlease enter a value for z: ");
		scanf("%i",z);
	}
	return EXIT_SUCCESS;
}

int getHeight(char *name,int *Height, int Args_Parsed){
	int val=*Height;
	if(val < HEIGHT_MIN || val > HEIGHT_MAX){
		if(Args_Parsed==TRUE && val!=0){
			printf("\n[WARNING] The passed value for height (%i) is not valid!\n",val);	
		}
		printf("\nWhat is the %s's height: ",name);
		scanf("%i",Height);
	}
	return EXIT_SUCCESS;
}

int getWidth(char *name,int *Width, int Args_Parsed){
	if(*Width < WIDTH_MIN ){
		if(Args_Parsed==TRUE && *Width!=0){
			printf("\n[WARNING] The passed value for width (%i) is not valid and is smaller than the minimum value (%i)!\n",*Width,WIDTH_MIN);	
		}
		printf("\nWhat is the %s's width: ",name);
		scanf("%i",Width);
	}
	if(*Width > WIDTH_MAX){
		printf("[WARNING] The passed value for width (%i) is larger that typical view distance(%i)!\n",*Width,WIDTH_MAX);	
	}	
	return EXIT_SUCCESS;
}

int getDepth(char *name,int *Depth, int Args_Parsed){
	int val=*Depth;
	if(val < HEIGHT_MIN || val > HEIGHT_MAX){
		if(Args_Parsed==TRUE){
			printf("\n[WARNING] The passed value for height (%i) is not valid!\n",val);	
		}	printf("\nWhat is the %s's depth: ",name);
		scanf("%i",Depth);
	}
	return EXIT_SUCCESS;
}

int getbuildingMaterial(char *array){
	printf("\nPlease enter a Material (e.g. minecraft:brick_block:");
	scanf("\n%50[^\n]", array);

	return EXIT_SUCCESS;
}

int getconsoleORchat(int *var){
	if(*var!=0 && *var!=1){
		do{
			printf("\n");
			printf("\nConsole or Chat (0/1)?: ");
			scanf("%i",var);
		}while(*var!=0 && *var!=1);
	}
	return EXIT_SUCCESS;	
}

int getFileTrueORFalse(int *var){
	if(*var!=0 && *var!=1){
		do{
			printf("\n");
			printf("\nWould you like to Print the commands to a file (0/1)?: ");
			scanf("%i",var);
		}while(*var!=0 && *var!=1);
	}
	return EXIT_SUCCESS;	
}

int getFileName(char *array){
	int var=-1;
	if(var!=0 && var!=1){
		do{
			printf("\n");
			printf("\nWould you like to rename the file(0/1)? (Current name: %s) ",array);
			scanf("%i",&var);
		}while(var!=0 && var!=1);
	}
	if(var==1){
		printf("\nPlease enter a new file name:\n");
		scanf("\n%200[^\n]", array);
	}
	return EXIT_SUCCESS;
}

int printBanner(){
	printf("\n\n\nMinecraft Fill Tool Building Generator");
	printf("\n======================================");
	return EXIT_SUCCESS;
}

int createSquare(int consoleORchat, int x, int y, int z, char buildingMaterial[], int Direction_NorthSouth, int Direction_WestEast, int heightStart, int heightStop, int Width){
	//int Width;//, Depth, Height;
	int xStart,yStart,zStart;
	int xStop,yStop,zStop;
	int i;//,j,k;

	xStart=x;
	yStart=y;
	zStart=z;
/*
	do{
		printf("\n\nPlease Enter a Width: ");
		scanf("%i",&Width);
		if((Width*Width)>=LAYER_MAX_SIZE){
			printf("\n[WARNING] The Width of the Cube is out of bounds! Width*Width=%i > 2^15",Width*Width);
		}

		if((Width+y)> HEIGHT_MAX){
			printf("\n[ERROR] The Height of the Cube is out of the map! Forcing Width to be: %i",HEIGHT_MAX-y);
			Width=HEIGHT_MAX-y;
		}

		if(Width>WIDTH_MAX){
			printf("\n[WARNING] Your shape is very long and may not render!");
		}

	}while((Width*Width)>=LAYER_MAX_SIZE);
*/

	//These never change
	xStart=x;
	zStart=z;

	printf("\n\nCopy and paste this into your console/chat:");
	for(i=(0+heightStart);i<(Width-heightStop);i++){
		yStart=i+y;
		xStop=xStart+(Width-1)*Direction_NorthSouth;
		yStop=yStart;
		zStop=zStart-(Width-1)*Direction_WestEast; //f'd up due to coords flipped: http://codeschool.org/3d-transformations-transcript/

		if(consoleORchat==0){
			printf("\nfill %i %i %i %i %i %i %s",xStart,yStart,zStart,xStop,yStop,zStop,buildingMaterial);
		}
		else{
			printf("\n/fill %i %i %i %i %i %i %s",xStart,yStart,zStart,xStop,yStop,zStop,buildingMaterial);
		}
	}
	return EXIT_SUCCESS;
}

int createRectangle(int consoleORchat, int x, int y, int z, char buildingMaterial[], int Direction_NorthSouth, int Direction_WestEast, int heightStart, int heightStop, int Width, int Depth, int Height){
	int xStart,yStart,zStart;
	int xStop,yStop,zStop;
	int i;//,j,k;

	xStart=x;
	yStart=y;
	zStart=z;
/*
	do{
		printf("\n\nPlease Enter a Width: ");
		scanf("%i",&Width);

		printf("\n\nPlease Enter a Depth: ");
		scanf("%i",&Depth);

		printf("\n\nPlease Enter a Height: ");
		scanf("%i",&Height);

		if((Width*Depth)>=LAYER_MAX_SIZE){
			printf("\n[WARNING] Width and Depth are TOO GREAT (Width*Depth= %i >2^15)!",Width*Depth);
		}
		if((Height+y)> HEIGHT_MAX){
			printf("\n[ERROR] The Height of the Rectangle is out of the map! Forcing Height to be: %i",HEIGHT_MAX-y);
			Height=HEIGHT_MAX-y;
		}
		if(Width>WIDTH_MAX || Depth>WIDTH_MAX){
			printf("\n[WARNING] Your shape is very long and may not render!");
		}
	}while((Width*Depth)>=LAYER_MAX_SIZE || Height>HEIGHT_MAX);
*/
		//These Never Change
		xStart=x;
		zStart=z;

		printf("\n\nCopy and paste this into your console/chat:");
		for(i=(0+heightStart);i<(Height-heightStop);i++){
			yStart=i+y;

			xStop=xStart+(Width-1)*Direction_NorthSouth;
			yStop=yStart;
			zStop=zStart-(Depth-1)*Direction_WestEast; //f'd up due to coords flipped: http://codeschool.org/3d-transformations-transcript/

			if(consoleORchat==0){
				printf("\nfill %i %i %i %i %i %i %s",xStart,yStart,zStart,xStop,yStop,zStop,buildingMaterial);
			}
			else{
				printf("\n/fill %i %i %i %i %i %i %s",xStart,yStart,zStart,xStop,yStop,zStop,buildingMaterial);
			}
		}
	return EXIT_SUCCESS;
}


int createPyramid(int consoleORchat, int x, int y, int z, char buildingMaterial[], int Direction_NorthSouth, int Direction_WestEast, int heightStart, int heightStop, int Width){
	//int Width;//, Depth, Height;
	int xStart,yStart,zStart;
	int xStop,yStop,zStop;
	int i;//,j,k;

	xStart=x;
	yStart=y;
	zStart=z;
/*
	do{
		printf("\n\nPlease Enter a Base Width: ");
		scanf("%i",&Width);
		if((Width*Width)>=LAYER_MAX_SIZE){
			printf("\n[WARNING] The Width of the Base is out of bounds! Width*Width=%i > 2^15",Width*Width);
		}

		if((Width+y)> HEIGHT_MAX){
			printf("\n[ERROR] The Height of the Pyramid is out of the map! Forcing Width to be: %i",HEIGHT_MAX-y);
			Width=HEIGHT_MAX-y;
		}

		if(Width>WIDTH_MAX){
			printf("\n[WARNING] Your shape is very long and may not render!");
		}

	}while((Width*Width)>=LAYER_MAX_SIZE);
*/

	printf("\n\nCopy and paste this into your console/chat:");
	for(i=(0+heightStart);i<=(Width-heightStop)/2;i++){
		xStart=x+i*Direction_NorthSouth;
		yStart=i+y;
		zStart=z-i*Direction_WestEast;
		xStop=xStart+(Width-i-i)*Direction_NorthSouth;
		yStop=yStart;
		zStop=zStart-(Width-i-i)*Direction_WestEast; //f'd up due to coords flipped: http://codeschool.org/3d-transformations-transcript/

		if(consoleORchat==0){
			printf("\nfill %i %i %i %i %i %i %s",xStart,yStart,zStart,xStop,yStop,zStop,buildingMaterial);
		}
		else{
			printf("\n/fill %i %i %i %i %i %i %s",xStart,yStart,zStart,xStop,yStop,zStop,buildingMaterial);
		}
	}
	return EXIT_SUCCESS;
}

int createSphere(int consoleORchat, int x, int y, int z, char buildingMaterial[], int Direction_NorthSouth, int Direction_WestEast, int heightStart, int heightStop, int Width){
	//int Width, Depth, Height;
	int xStart,yStart,zStart;
	int xStop,yStop,zStop;
	int i,j;//,k;
	int residue;
//	int offset;

	xStart=x;
	yStart=y;
	zStart=z;
/*
	do{
		printf("\n\nPlease Enter a Sphere Diameter (Width): ");
		scanf("%i",&Width);
		
//		printf("\n\nPlease Enter a Height: ");
//		scanf("%i",&Height);
//		Width++;//Need to account for exception handling of sin/cos predictions

		if((Width*2)>=LAYER_MAX_SIZE){
			printf("\n[WARNING] The Diameter of the Sphere is out of bounds! Radius*2=%i > 2^15",Width*Width);
		}

		if(Height > HEIGHT_MAX){
			printf("\n[ERROR] The Height of the Sphere is out of the map! Forcing Width to be: %i",HEIGHT_MAX-y);
			Height=HEIGHT_MAX-y;
		}

		if(Width*2>WIDTH_MAX){
			printf("\n[WARNING] Your shape is very long and may not render!");
		}

	}while((Width*2)>=LAYER_MAX_SIZE);// || Height>HEIGHT_MAX);
*/
/*
	do{
		printf("\n\nPlease Enter a Width: ");
		scanf("%i",&Width);

		printf("\n\nPlease Enter a Depth: ");
		scanf("%i",&Depth);

		printf("\n\nPlease Enter a Height: ");
		scanf("%i",&Height);

		if((Width*Depth)>=LAYER_MAX_SIZE){
			printf("\n[WARNING] Width and Depth are TOO GREAT (Width*Depth= %i >2^15)!",Width*Depth);
		}
		if((Height+y)> HEIGHT_MAX){
			printf("\n[ERROR] The Height of the Rectangle is out of the map! Forcing Height to be: %i",HEIGHT_MAX-y);
			Height=HEIGHT_MAX-y;
		}
		if(Width>WIDTH_MAX || Depth>WIDTH_MAX){
			printf("\n[WARNING] Your shape is very long and may not render!");
		}
	}while((Width*Depth)>=LAYER_MAX_SIZE || Height>HEIGHT_MAX);
*/
	printf("\n\nCopy and paste this into your console/chat:");
	//for(i=(0+heightStart);i<((Width-heightStop +2-1)/2);i++){ //Round up in C == Add the divisor less one
//	int isEven;
//	isEven=Width%2;
	double Radius;
	Radius=(double)(Width)/2.0;
	double LayerRadius,LayerRadius2;
	//double LayerDiameter;
	//int voxelDiameter;

	int startPosition;
	startPosition=0;

	for(j=(0+heightStart);j<Radius;j++){ //Round up in C == Add the divisor less one
		LayerRadius=Radius*sin(acos((Radius-(double)j-1.0)/(double)Radius));

		for(i=(0+heightStart);i<=(Width-heightStop-startPosition)/2;i++){ //Round up in C == Add the divisor less one
		if(i==0){
			LayerRadius2=LayerRadius;
		}
		else{
			LayerRadius2=LayerRadius*cos(asin((double)i/LayerRadius));
		}
//		LayerDiameter=LayerRadius2*2;
		residue=(int)(LayerRadius2);
		//printf("\n\n\n[DEBUGGING] LayerRadius-i: %f",(LayerRadius-i));
		//		printf("\n\n\n[DEBUGGING] Point[%i]: %f,%f (%i,%i), Degrees: %f",i,LayerRadius2,LayerRadius22,(int)LayerRadius2,(int)LayerRadius22,180.0*(double)i/((double)Width));

		//offset=0;
		if((LayerRadius2-residue)>0.000000 && (LayerRadius2-residue)<1.000000){ // ANY residue rounds up!
			//offset=1;
			//			printf("\n[DEBUGGING] \tResidue(%f - %i): %f present!",LayerRadius2,residue,LayerRadius2-residue);
			LayerRadius2+=1.0;
		}
		//		printf("\n[DEBUGGING] Point[%i]: %f,%f (%i,%i), Degrees: %f",i,LayerRadius2,LayerRadius22,(int)LayerRadius2,(int)LayerRadius22,180.0*(double)i/((double)Width));
		xStart=x-(int)LayerRadius2;
		yStart=y+j; //goes up for 'height' ONLY
		zStart=z+i;//-(int)LayerRadius2;
		xStop=x+(int)LayerRadius2*Direction_NorthSouth;
		yStop=yStart;
		zStop=z+i;//+(int)LayerRadius2*Direction_WestEast; //f'd up due to coords flipped: http://codeschool.org/3d-transformations-transcript/

		if(consoleORchat==0){
			printf("\nfill %i %i %i %i %i %i %s",xStart,yStart,zStart,xStop,yStop,zStop,buildingMaterial);
		}
		else{
			printf("\n/fill %i %i %i %i %i %i %s",xStart,yStart,zStart,xStop,yStop,zStop,buildingMaterial);
		}
		if(i!=0 || Width%2==0){
			zStart=z-i;//-(int)LayerRadius2;	
			zStop=z-i;//+(int)LayerRadius2*Direction_WestEast; //f'd up due to coords flipped: http://codeschool.org/3d-transformations-transcript/
			if(consoleORchat==0){
				printf("\nfill %i %i %i %i %i %i %s",xStart,yStart,zStart,xStop,yStop,zStop,buildingMaterial);
			}
			else{
				printf("\n/fill %i %i %i %i %i %i %s",xStart,yStart,zStart,xStop,yStop,zStop,buildingMaterial);
			}
		}

		}
	}
	return EXIT_SUCCESS;
}


int createDiamond(int consoleORchat, int x, int y, int z, char buildingMaterial[], int Direction_NorthSouth, int Direction_WestEast, int heightStart, int heightStop, int Width){
	//int Width, Depth, Height;
//	int xStart,yStart,zStart;
//	int xStop,yStop,zStop;
	int i;//,j,k;
//	int residue;
//	int offset;

//	xStart=x;
//	yStart=y;
//	zStart=z;

/*
	do{
		printf("\n\nPlease Enter a Sphere Diameter (Width): ");
		scanf("%i",&Width);
		//Width++;//Need to account for exception handling of sin/cos predictions
		if((Width*2)>=LAYER_MAX_SIZE){
			printf("\n[WARNING] The Diameter of the Sphere is out of bounds! Radius*2=%i > 2^15",Width*Width);
		}

		if((Width*2+y)> HEIGHT_MAX){
			printf("\n[ERROR] The Height of the Sphere is out of the map! Forcing Width to be: %i",HEIGHT_MAX-y);
			Width=HEIGHT_MAX-y;
		}

		if(Width*2>WIDTH_MAX){
			printf("\n[WARNING] Your shape is very long and may not render!");
		}

	}while((Width*2)>=LAYER_MAX_SIZE);
*/

//	for(i=0;i<Width;i++){
	i=Width%2;
	if(i==0){i=2;}

	do{
		printf("\n%i",i);	
	}while((i+=2)<Width);	
	do{
		printf("\n%i",i);		
	}while((i-=2)>0);
		
	return EXIT_SUCCESS;
}

int createCylinder(int consoleORchat, int x, int y, int z, char buildingMaterial[], int Direction_NorthSouth, int Direction_WestEast, int heightStart, int heightStop, int Height, int Width){
	int xStart,yStart,zStart;
	int xStop,yStop,zStop;
	int i,j;//,k;
	int residue;
	//int offset;

	xStart=x;
	yStart=y;
	zStart=z;


	double Radius;
	Radius=(double)(Width)/2.0;
	double LayerRadius;//,LayerRadius2;
//	double LayerDiameter;
//	int voxelDiameter;

	int startPosition;
	startPosition=0;

	for(j=(0+heightStart);j<Height;j++){ //Round up in C == Add the divisor less one
		for(i=(0+heightStart);i<=(Width-heightStop-startPosition)/2;i++){ //Round up in C == Add the divisor less one
		if(i==0){
			LayerRadius=Radius;
			//LayerRadius2=1;
		}
		else{
			LayerRadius=Radius*cos(asin((double)i/Radius));
			//LayerRadius2=Radius*sin(PI*(double)i/(double)Width);
		}
		//LayerDiameter=LayerRadius*2;
		residue=(int)(LayerRadius);
		//printf("\n\n\n[DEBUGGING] Radius-i: %f",(Radius-i));
		//		printf("\n\n\n[DEBUGGING] Point[%i]: %f,%f (%i,%i), Degrees: %f",i,LayerRadius,LayerRadius2,(int)LayerRadius,(int)LayerRadius2,180.0*(double)i/((double)Width));

//		offset=0;
		if((LayerRadius-residue)>0.000000 && (LayerRadius-residue)<1.000000){ // ANY residue rounds up!
//			offset=1;
			//			printf("\n[DEBUGGING] \tResidue(%f - %i): %f present!",LayerRadius,residue,LayerRadius-residue);
			LayerRadius+=1.0;
		}
		//		printf("\n[DEBUGGING] Point[%i]: %f,%f (%i,%i), Degrees: %f",i,LayerRadius,LayerRadius2,(int)LayerRadius,(int)LayerRadius2,180.0*(double)i/((double)Width));
		xStart=x+i;
		yStart=y+j; //goes up for 'height' ONLY
		zStart=z-((int)LayerRadius-1)*Direction_NorthSouth;//-(int)LayerRadius;

		xStop=x+i;
		yStop=yStart;
		zStop=z+((int)LayerRadius-1)*Direction_NorthSouth;//+(int)LayerRadius*Direction_WestEast; //f'd up due to coords flipped: http://codeschool.org/3d-transformations-transcript/

		if(consoleORchat==0){
			printf("\nfill %i %i %i %i %i %i %s",xStart,yStart,zStart,xStop,yStop,zStop,buildingMaterial);
		}
		else{
			printf("\n/fill %i %i %i %i %i %i %s",xStart,yStart,zStart,xStop,yStop,zStop,buildingMaterial);
		}
		if(Width%2==0){//if EVEN Width 
			//printf("\n\n[DEBUGGING] EVEN WIDTH!\n");
			xStart=x-i-1; //-(int)LayerRadius;	
			xStop=x-i-1;  //+(int)LayerRadius*Direction_WestEast; //f'd up due to coords flipped: http://codeschool.org/3d-transformations-transcript/
			if(consoleORchat==0){
				printf("\nfill %i %i %i %i %i %i %s",xStart,yStart,zStart,xStop,yStop,zStop,buildingMaterial);
			}
			else{
				printf("\n/fill %i %i %i %i %i %i %s",xStart,yStart,zStart,xStop,yStop,zStop,buildingMaterial);
			}
		}
		else{ //if ODD Width 
			if(i!=0){
			//	printf("\n\n[DEBUGGING] ODD WIDTH!\n");
				xStart=x-i;//-(int)LayerRadius;	
				xStop=x-i;//+(int)LayerRadius*Direction_WestEast; //f'd up due to coords flipped: http://codeschool.org/3d-transformations-transcript/
				if(consoleORchat==0){
					printf("\nfill %i %i %i %i %i %i %s",xStart,yStart,zStart,xStop,yStop,zStop,buildingMaterial);
				}
				else{
					printf("\n/fill %i %i %i %i %i %i %s",xStart,yStart,zStart,xStop,yStop,zStop,buildingMaterial);
				}				
			}
		}

		}
	}
	return EXIT_SUCCESS;
}
//
// 
//
// 
//
// 
//
// 
//
// 
//
// 
//
// 
//
// 
//
// 
//
// 
//
