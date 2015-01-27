#include <math.h>

#define HEIGHT_MAX 255
#define VIEW_MAX 176
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
#define initVars() 			\
	int x,y,z;			\
	int buildingType=0;		\
	char buildingMaterial[50];	\
	int consoleORchat=0;		\
	int MaxHeight=HEIGHT_MAX;	\
	int MinHeight=0;		\
	int HeightOffset=0;		\
	int HeightStop=0;		\
	int Hollow=0;			\
	int EdgesOnly=0;		\
	int Direction_NorthSouth;	\
	int Direction_WestEast;		\
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
	printf("\n[7] Diamond");
	printf("\n[8] Cone");
	printf("\n[9] Doughnut");

	return EXIT_SUCCESS;
}

int createSquare(int consoleORchat, int x, int y, int z, char buildingMaterial[], int Direction_NorthSouth, int Direction_WestEast, int heightStart, int heightStop){
	int Width, Depth, Height;
	int xStart,yStart,zStart;
	int xStop,yStop,zStop;
	int i,j,k;

	xStart=x;
	yStart=y;
	zStart=z;

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

		if(Width>VIEW_MAX){
			printf("\n[WARNING] Your shape is very long and may not render!");
		}

	}while((Width*Width)>=LAYER_MAX_SIZE);

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

int createRectangle(int consoleORchat, int x, int y, int z, char buildingMaterial[], int Direction_NorthSouth, int Direction_WestEast, int heightStart, int heightStop){
	int Width, Depth, Height;
	int xStart,yStart,zStart;
	int xStop,yStop,zStop;
	int i,j,k;

	xStart=x;
	yStart=y;
	zStart=z;

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
		if(Width>VIEW_MAX || Depth>VIEW_MAX){
			printf("\n[WARNING] Your shape is very long and may not render!");
		}
	}while((Width*Depth)>=LAYER_MAX_SIZE || Height>HEIGHT_MAX);

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


int createPyramid(int consoleORchat, int x, int y, int z, char buildingMaterial[], int Direction_NorthSouth, int Direction_WestEast, int heightStart, int heightStop){
	int Width, Depth, Height;
	int xStart,yStart,zStart;
	int xStop,yStop,zStop;
	int i,j,k;

	xStart=x;
	yStart=y;
	zStart=z;

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

		if(Width>VIEW_MAX){
			printf("\n[WARNING] Your shape is very long and may not render!");
		}

	}while((Width*Width)>=LAYER_MAX_SIZE);


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



//Sphere:
// 
// Go Layer by layer from outside top + bottom to center
// Fill 0 to pi/4 + mirror and p/2 to p/4 VIA trans pose
// e.g. if radius is 10: and x,y,z are 0,0,0
//    the first fill is: fill -10 10 0 10 10 0 <blah> fill 0 10 -10 0 10 10 <blah> ... this makes an X
//    the second fill is: fill -9 100 1 9 100 1 <blah>, fill 1 100 -9 1 100 9 <blah>, fill -9 100 -1 9 100 -1 <blah>, fill -1 100 -9 -1 100 9 <blah>

//  |     --------+
//  |               \
//  |                 \
//  |                    \
//  |                      [X,Y] = r cos(theta) , r sine (theta)
//  |                         |
//  |                          \
//  |                            |
//  |                             \
//  |                               |
//  |                                \
//  |                                  |
//  + ----------------------------------------  
//
// //* sin example */
// #include <stdio.h>      /* printf */

// int main ()
// {
  // param = 30.0;
  // result = sin (param*PI/180);
  // printf ("The sine of %f degrees is %f.\n", param, result );
  // return 0;
// } 
// go 0-45 or 0 tp pi/4 ---> mirrors both horizon + vert.
// 1= cos(theta)^2 + sine (theta)^2
// 
// 
//
int createSphere(int consoleORchat, int x, int y, int z, char buildingMaterial[], int Direction_NorthSouth, int Direction_WestEast, int heightStart, int heightStop){
	int Width, Depth, Height;
	int xStart,yStart,zStart;
	int xStop,yStop,zStop;
	int i,j,k;
	int residue;
	int offset;

	xStart=x;
	yStart=y;
	zStart=z;

	do{
		printf("\n\nPlease Enter a Sphere Diameter (Width): ");
		scanf("%i",&Width);
//		Width++;//Need to account for exception handling of sin/cos predictions
		if((Width*2)>=LAYER_MAX_SIZE){
			printf("\n[WARNING] The Diameter of the Sphere is out of bounds! Radius*2=%i > 2^15",Width*Width);
		}

		if((Width*2+y)> HEIGHT_MAX){
			printf("\n[ERROR] The Height of the Sphere is out of the map! Forcing Width to be: %i",HEIGHT_MAX-y);
			Width=HEIGHT_MAX-y;
		}

		if(Width*2>VIEW_MAX){
			printf("\n[WARNING] Your shape is very long and may not render!");
		}

	}while((Width*2)>=LAYER_MAX_SIZE);

	printf("\n\nCopy and paste this into your console/chat:");
	//for(i=(0+heightStart);i<((Width-heightStop +2-1)/2);i++){ //Round up in C == Add the divisor less one
//	int isEven;
//	isEven=Width%2;
	double Radius;
	Radius=(double)(Width)/2.0;
	double LayerRadius,LayerRadius2;
	double LayerDiameter;
	int voxelDiameter;
	//double param, result;
	printf("\n[DEBUGGING] Radius: %f, Diameter:%i\n",Radius,Width);
	int startPosition;
	startPosition=0;
/*
	if(Width%2==0){
		printf("\n[DEBUGGING] The diameter is even! -- skipping middle row!"); //bug? seems backwards
		startPosition++;
	}
*/
	for(i=(0+heightStart);i<=(Width-heightStop-startPosition)/2;i++){ //Round up in C == Add the divisor less one
		LayerRadius=Radius*cos(PI*(double)i/(double)Width);
		LayerRadius2=Radius*sin(PI*(double)i/(double)Width);
		LayerDiameter=LayerRadius*2;
		residue=(int)(LayerRadius);
		//printf("\n\n[DEBUGGING] Layer, non-residue Diameter: %i; LayerDiameter: %f",(int)LayerDiameter, LayerDiameter);
		
		
	printf("\n\n\n[DEBUGGING] Point[%i]: %f,%f (%i,%i), Degrees: %f",i,LayerRadius,LayerRadius2,(int)LayerRadius,(int)LayerRadius2,180.0*(double)i/((double)Width));
//		printf("\n[DEBUGGING] Point[%i]: %f,%f (%i,%i), Degrees: %f",i,LayerRadius2,LayerRadius,(int)LayerRadius2,(int)LayerRadius,180.0*(double)i/((double)Width));
		//if((LayerDiameter-residue)>0.000000 && (LayerDiameter-residue)<Sqrt_2_over_2){
		if((LayerRadius-residue)>0.000000 && (LayerRadius-residue)<1.000000){
			offset=1;
			printf("\n[DEBUGGING] \tResidue(%f - %i): %f present!",LayerRadius,residue,LayerRadius-residue);
			LayerRadius+=1.0;
		}
		else{
			offset=0;
			printf("\n[DEBUGGING] \tNo residue!");
		}
		/*
		voxelDiameter=LayerDiameter+offset;
		printf("\n\tvoxelDiameter: %i",voxelDiameter);
				
		if(LayerRadius==0){
			if(i%Width==0){
				LayerRadius=1;
			}
		}
		*/

//		printf("\n[DEBUGGING] LayerRadius[%i]: %f (%i), Degrees: %f",i,LayerRadius,(int)LayerRadius+offset,180.0*(double)i/((double)Width));
		printf("\n[DEBUGGING] Point[%i]: %f,%f (%i,%i), Degrees: %f",i,LayerRadius,LayerRadius2,(int)LayerRadius,(int)LayerRadius2,180.0*(double)i/((double)Width));
//		printf("\n[DEBUGGING] Point[%i]: %f,%f (%i,%i), Degrees: %f",i,LayerRadius2,LayerRadius,(int)LayerRadius2,(int)LayerRadius,180.0*(double)i/((double)Width));
		//printf("\n[DEBUGGING] Checking residue ... Integer portion:%i, residue portion: %f",residue,LayerRadius-residue);

	/*
	float Point;
	int Value;
	Point=Radius*sin(PI*((float)i+1.0)/((float)Width));
	Value=(int)(Point*((Point-1.0)/(Point))); 
	printf("\n\n[DEBUGGING] Point[%i]: %f, Value: %f",i,Point,Value);
	*/
		yStart=i+y;
		xStart=x;
		zStart=z;
//		printf("\nTest Point[%i]: <%i,%i,%i>",i,xStart,yStart,zStart);
		//if(i!=((Width-heightStop +2-1)/2)){
//		if(isEven==0){
//			printf(" has mirror...");
//		}

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


int createDiamond(int consoleORchat, int x, int y, int z, char buildingMaterial[], int Direction_NorthSouth, int Direction_WestEast, int heightStart, int heightStop){
		int Width, Depth, Height;
	int xStart,yStart,zStart;
	int xStop,yStop,zStop;
	int i,j,k;
	int residue;
	int offset;

	xStart=x;
	yStart=y;
	zStart=z;

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

		if(Width*2>VIEW_MAX){
			printf("\n[WARNING] Your shape is very long and may not render!");
		}

	}while((Width*2)>=LAYER_MAX_SIZE);

//	for(i=0;i<Width;i++){
	j=Width%2;
	if(j==0){j=2;}

	do{
		printf("\n%i",j);	
	}while((j+=2)<Width);	
	do{
		printf("\n%i",j);		
	}while((j-=2)>0);
		
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
