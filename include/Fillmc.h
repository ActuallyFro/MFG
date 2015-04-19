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
	char OutputFileName[200]="MFG_output.txt";	\
	int consoleORchat=-1;						\
	int Hollow=-1;								\
	int Hollow_wall_width=0;					\
	int shapesTotal=9;							\
	int Width=0;								\
	int HollowWidth=0;							\
	int Depth=0;								\
	int RotationOrientation=NORTH;				\
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

int setHollowWidth(int shapeType, int Hollow_wall_width, int *x,int *y,int *z, int * Height, int * Depth, int * Width, int Direction){
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
		if(Direction==1){
			*Depth-=(Hollow_wall_width*2);
			*Width-=(Hollow_wall_width*2+2);
			*x+=Hollow_wall_width+1;
			*y+=Hollow_wall_width;
			*z-=Hollow_wall_width;
		}
		else{//case of -1
			*Depth-=(Hollow_wall_width*2);
			*Width-=(Hollow_wall_width*2+2);
			*x+=Hollow_wall_width;
			*y+=Hollow_wall_width;
			*z+=(Hollow_wall_width+1);			
		}
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
		*y+=Hollow_wall_width;
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
		//printf("\n[8] Cone");
		//printf("\n[9] Doughnut");
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
	printf("\nMinecraft Fill Tool Building Generator");
	printf("\n======================================");
	return EXIT_SUCCESS;
}

int createSquare(int consoleORchat, int x, int y, int z, char buildingMaterial[], int Direction_NorthSouth, int Direction_WestEast, int heightStart, int heightStop, int Width, int OutputToFile, char OutputFileName[]){
	int xStart,yStart,zStart;
	int xStop,yStop,zStop;
	int i;
	TL_FILE_IO_INSTALL_NAMED(FILE1);

	//These never change
	xStart=x;
	yStart=y;
	zStart=z;

	if(OutputToFile==TRUE){
		TL_FILE_OPEN_WRITE_MODE_APPEND_NAMED(OutputFileName, 0644,FILE1);
	}
	else{
		printf("\n\nCopy and paste this into your console/chat:");
	}
	
	for(i=(0+heightStart);i<(Width-heightStop);i++){
		yStart=i+y;
		xStop=xStart+(Width-1)*Direction_NorthSouth;
		yStop=yStart;
		zStop=zStart-(Width-1)*Direction_WestEast; //f'd up due to coords flipped: http://codeschool.org/3d-transformations-transcript/

		if(consoleORchat==0){
			if(OutputToFile==TRUE){
				sprintf(BUF_FILE1,"fill %i %i %i %i %i %i %s\r\n",xStart,yStart,zStart,xStop,yStop,zStop,buildingMaterial);
				TL_FILE_WRITE_STRING_ARRAY_NAMED(FILE1,BUF_FILE1);
			}
			else{
				printf("\nfill %i %i %i %i %i %i %s",xStart,yStart,zStart,xStop,yStop,zStop,buildingMaterial);
			}
		}
		else{
			if(OutputToFile==TRUE){
				sprintf(BUF_FILE1,"/fill %i %i %i %i %i %i %s\r\n",xStart,yStart,zStart,xStop,yStop,zStop,buildingMaterial);
				TL_FILE_WRITE_STRING_ARRAY_NAMED(FILE1,BUF_FILE1);
			}
			else{
				printf("\n/fill %i %i %i %i %i %i %s",xStart,yStart,zStart,xStop,yStop,zStop,buildingMaterial);
			}
			
		}
	}
	
	if(OutputToFile==TRUE){
		TL_FILE_CLOSE_NAMED(FILE1);
	}
	
	return EXIT_SUCCESS;
}

int createRectangle(int consoleORchat, int x, int y, int z, char buildingMaterial[], int Direction_NorthSouth, int Direction_WestEast, int heightStart, int heightStop, int Width, int Depth, int Height, int OutputToFile, char OutputFileName[]){
	int xStart,yStart,zStart;
	int xStop,yStop,zStop;
	int i;

	//These Never Change
	xStart=x;
	yStart=y;
	zStart=z;
	
	TL_FILE_IO_INSTALL_NAMED(FILE1);
	if(OutputToFile==TRUE){
		TL_FILE_OPEN_WRITE_MODE_APPEND_NAMED(OutputFileName, 0644,FILE1);
	}
	else{
		printf("\n\nCopy and paste this into your console/chat:");
	}	

	for(i=(0+heightStart);i<(Height-heightStop);i++){
		yStart=i+y;

		xStop=xStart+(Width-1)*Direction_NorthSouth;
		yStop=yStart;
		zStop=zStart-(Depth-1)*Direction_WestEast; //f'd up due to coords flipped: http://codeschool.org/3d-transformations-transcript/

		if(consoleORchat==0){
			if(OutputToFile==TRUE){
				sprintf(BUF_FILE1,"fill %i %i %i %i %i %i %s\r\n",xStart,yStart,zStart,xStop,yStop,zStop,buildingMaterial);
				TL_FILE_WRITE_STRING_ARRAY_NAMED(FILE1,BUF_FILE1);
			}
			else{
				printf("\nfill %i %i %i %i %i %i %s",xStart,yStart,zStart,xStop,yStop,zStop,buildingMaterial);
			}
		}
		else{
			if(OutputToFile==TRUE){
				sprintf(BUF_FILE1,"/fill %i %i %i %i %i %i %s\r\n",xStart,yStart,zStart,xStop,yStop,zStop,buildingMaterial);
				TL_FILE_WRITE_STRING_ARRAY_NAMED(FILE1,BUF_FILE1);
			}
			else{
				printf("\n/fill %i %i %i %i %i %i %s",xStart,yStart,zStart,xStop,yStop,zStop,buildingMaterial);
			}
		}
	}
	
	if(OutputToFile==TRUE){
		TL_FILE_CLOSE_NAMED(FILE1);
	}
	return EXIT_SUCCESS;
}

int createTriangularPrism(int consoleORchat, int x, int y, int z, char buildingMaterial[], int Direction_NorthSouth, int Direction_WestEast, int heightStart, int heightStop, int Depth, int Width,  int OutputToFile, char OutputFileName[]){
	int xStart,yStart,zStart;
	int xStop,yStop,zStop;
	int i,Height;
	Height=Width/2+1;
	//These Never Change
	
	TL_FILE_IO_INSTALL_NAMED(FILE1);
	if(OutputToFile==TRUE){
		TL_FILE_OPEN_WRITE_MODE_APPEND_NAMED(OutputFileName, 0644,FILE1);
	}
	else{
		printf("\n\nCopy and paste this into your console/chat:");
	}	

	for(i=(0+heightStart);i<(Height-heightStop);i++){

		if(Direction_NorthSouth==1){
			xStart=x+(i*Direction_NorthSouth); //goes east each time
			yStart=i+y;
			zStart=z;
			xStop=x+(Width-i)*Direction_NorthSouth;
			yStop=yStart;
			zStop=zStart-(Depth*Direction_WestEast); //f'd up due to coords flipped: http://codeschool.org/3d-transformations-transcript/
		}
		else{			
			xStart=x; //goes east each time
			yStart=i+y;
			zStart=z-(Width-i)*Direction_NorthSouth;
			xStop=xStart+(Depth*Direction_WestEast);
			yStop=yStart;
			zStop=z-(i*Direction_NorthSouth); //f'd up due to coords flipped: http://codeschool.org/3d-transformations-transcript/
		}
		
		if(consoleORchat==0){
			if(OutputToFile==TRUE){
				sprintf(BUF_FILE1,"fill %i %i %i %i %i %i %s\r\n",xStart,yStart,zStart,xStop,yStop,zStop,buildingMaterial);
				TL_FILE_WRITE_STRING_ARRAY_NAMED(FILE1,BUF_FILE1);
			}
			else{
				printf("\nfill %i %i %i %i %i %i %s",xStart,yStart,zStart,xStop,yStop,zStop,buildingMaterial);
			}
		}
		else{
			if(OutputToFile==TRUE){
				sprintf(BUF_FILE1,"/fill %i %i %i %i %i %i %s\r\n",xStart,yStart,zStart,xStop,yStop,zStop,buildingMaterial);
				TL_FILE_WRITE_STRING_ARRAY_NAMED(FILE1,BUF_FILE1);
			}
			else{
				printf("\n/fill %i %i %i %i %i %i %s",xStart,yStart,zStart,xStop,yStop,zStop,buildingMaterial);
			}
		}
	}
	
	if(OutputToFile==TRUE){
		TL_FILE_CLOSE_NAMED(FILE1);
	}
	return EXIT_SUCCESS;
}


int createPyramid(int consoleORchat, int x, int y, int z, char buildingMaterial[], int Direction_NorthSouth, int Direction_WestEast, int heightStart, int heightStop, int Width, int OutputToFile, char OutputFileName[]){
	int xStart,yStart,zStart;
	int xStop,yStop,zStop;
	int i;

	xStart=x;
	yStart=y;
	zStart=z;
	
	TL_FILE_IO_INSTALL_NAMED(FILE1);
	if(OutputToFile==TRUE){
		TL_FILE_OPEN_WRITE_MODE_APPEND_NAMED(OutputFileName, 0644,FILE1);
	}
	else{
		printf("\n\nCopy and paste this into your console/chat:");
	}

	for(i=(0+heightStart);i<=(Width-heightStop)/2;i++){
		xStart=x+i*Direction_NorthSouth;
		yStart=i+y;
		zStart=z-i*Direction_WestEast;
		xStop=xStart+(Width-i-i)*Direction_NorthSouth;
		yStop=yStart;
		zStop=zStart-(Width-i-i)*Direction_WestEast; //f'd up due to coords flipped: http://codeschool.org/3d-transformations-transcript/

		if(consoleORchat==0){
			if(OutputToFile==TRUE){
				sprintf(BUF_FILE1,"fill %i %i %i %i %i %i %s\r\n",xStart,yStart,zStart,xStop,yStop,zStop,buildingMaterial);
				TL_FILE_WRITE_STRING_ARRAY_NAMED(FILE1,BUF_FILE1);
			}
			else{
				printf("\nfill %i %i %i %i %i %i %s",xStart,yStart,zStart,xStop,yStop,zStop,buildingMaterial);
			}
		}
		else{
			if(OutputToFile==TRUE){
				sprintf(BUF_FILE1,"/fill %i %i %i %i %i %i %s\r\n",xStart,yStart,zStart,xStop,yStop,zStop,buildingMaterial);
				TL_FILE_WRITE_STRING_ARRAY_NAMED(FILE1,BUF_FILE1);
			}
			else{
				printf("\n/fill %i %i %i %i %i %i %s",xStart,yStart,zStart,xStop,yStop,zStop,buildingMaterial);
			}
		}
	}
	
	if(OutputToFile==TRUE){
		TL_FILE_CLOSE_NAMED(FILE1);
	}

	return EXIT_SUCCESS;
}

	
/*
                ____
            ,dP9CGG88@b,
          ,IP""YICCG888@@b,
         dIi   ,IICGG8888@b
        dCIIiciIICCGG8888@@b
________GCCIIIICCCGGG8888@@@__________________
        GGCCCCCCCGGG88888@@@
        GGGGCCCGGGG88888@@@@...
        Y8GGGGGG8888888@@@@P.....
         Y88888888888@@@@@P......
         `Y8888888@@@@@@@P'......
            `@@@@@@@@@P'.......
                """"........
For a voxel sphere --^ a "3D Printing Approach must be taken".

            . -- ~~~ -- .
         .-~              ~-.
       /                     \
      /                       \
+----|  -   -   -   -   -   -  |+
 \   |                         | \
  \--|-------------X-----------|--\          <---- Imagine the plane starts at the bottom and "prints" up
   \  \            |##########/    \
    \  \           |#########/      \        The "X" is in the direct center of the sphere and measures "DOWN" to the edge
     \  `-.        |########'        \
      \     ~- .   |###. -~           \
       +-------------------------------+
	   
	   
Cutting the voxel sphere into two hemispheres would look like this per layer:

 		      ===|===
	       ======|======
	     ========|========
       ==========|==========
       ==========X==========
       ==========|==========
	     ========|========
	       ======|======
 		      ===|===
	   
Imagine stacking of the Towers of Hanoi, so we need to figure out the width if the circle for each layer and "print up"	   
The only thing known in this printing process is that it will go layer by layer (as shown above).
One would assume that we know the height of cos(T), but this is NOT true ... we know R and the delta from r with each layer of printing...

Enter Trig:
             :****
             :       ***
             :             **
             :              + *    Sin(theta T)
             :           +   |  * /                   <---- "Normal" measures of a circle, but is NOT oriented correctly
             :        +      |   /             
             :     +         |<-/ *
             :  + (T)        |    *
             X---------r-----+----*  
              \_____________/
                     |
             	Cos(theta T)	
	
	
        .-> X .. .. .. .. .. .. ..
       /    | +                   *
      |     |(T)+                 *
      |     |	  +               *
Cos(Theta T)|       H=r             *  <-------- Oriented as shown above
      |     A         +        *
      |     |           +      *
       \--->| - - O - - -+  *
            j        \ * * 
            | * * * * \
                       \____ Sin(theta T)

So you have to go from, in this orientation, 270 degrees to 90 degrees, calculate the "sub-radius", generate the circle for that layer, and repeat for the half circle.To be completely technical: only 1/4 length of pi would need to be calculated, and reflected appropriately for the whole circle and sphere... but that makes my brain hurt.

 The sides are in also now in standard form: O(pposite), A(djacent), H(ypotenunse), and j(index).
 Looking at the figure above we can determine H, since it's the radius 'r'.
 Also, we can determine A, since it's H minus the index (A=r-j) since we can seed in the figure above that adding A and j is equal to r
 
Plug an chug and example:
Diameter=9, r=4.5
 		      =O9=|=O9= <--- j=9
	       ====O8=|=O8==== <--- j=8
	     ======O7=|=O7====== <--- j=7
       ========O6=|=O6======== <--- j=6
       ========O5=X=O5======== <--- j=5
       ========O4=|=O4======== <--- j=4
	     ======O3=|=O3====== <--- j=3
	       ====O2=|=O2==== <--- j=2
 		      =O1=|=O1= <--- j=1
Notice that each layer has i changing over time, so we can put that as in the index variable in a for loop, but each layer's O is still unknown!

Note: we only solve for an O# term on one side of the vertical cut or the other to get the radius for that specific layer. Additionally, solving for one side allows us to multiply it by 2 to find the layer's/disk's diameter if needed.

Math time:
CAH --> Cos(theta T) = A/H = (r-j)/r. Since we don't know theta let's ARCCOS the A/H term: theta T = acos((r-j)/r).
Now to find O: SOH ==> sin(theta T)= O/H ==> H*sin(theta T) = O ==> r*sin(acos((r-j)/r)) = O
In code form: SphereRadius=Radius*sin(acos(((double)Radius-(double)j)/(double)Radius));

since this is in a for loop let's try the first case of j=0, for EVERY case of Radius!
SphereRadius=Radius*sin(acos(((Radius-0)/Radius)) = Radius*sin(acos(Radius/Radius) = Radius*sin(acos(1)) = Radius*sin(0) = Radius*0 = 0;
--> this was a loaded statement, since courses should have taught you that arc-sin/cos are hyperbolas!
	   
Now we have the method of determining each layer's radius, so we can now follow a very similar method to fill in the disk. This is the exact method as used in the create cylinder (which determines the slices needed in a circle) for a single layer/one block of height. Thus I'm skipping it!
*/
int createSphere(int consoleORchat, int x, int y, int z, char buildingMaterial[], int Direction_NorthSouth, int Direction_WestEast, int heightStart, int heightStop, int Width, int OutputToFile, char OutputFileName[]){
	int xStart,yStart,zStart;
	int xStop,yStop,zStop;
	int i,j;
	int residue;

	xStart=x;
	yStart=y;
	zStart=z;
	
	TL_FILE_IO_INSTALL_NAMED(FILE1);
	if(OutputToFile==TRUE){
		TL_FILE_OPEN_WRITE_MODE_APPEND_NAMED(OutputFileName, 0644,FILE1);
	}
	else{
		printf("\n\nCopy and paste this into your console/chat:");
	}

	double Radius;
	Radius=(double)(Width)/2.0;
	double SphereRadius,SphereDiskLayerRadius;

	int startPosition;
	startPosition=0;
	
	for(j=(0+heightStart);j<(Width-heightStop-startPosition);j++){ //Run for the diameter since each disk layer deals with the radius; this loop 'prints' from top to bottom.
		SphereRadius=Radius*sin(acos(((double)Radius-(double)j)/(double)Radius));
		//The following should be the same code as the cylinder maker... yet, the sphere radius changes with height the DiskLayer radius will change accordingly:
		for(i=0;i<=SphereRadius;i++){
			
			if(i==0){//This is the MIDDLE row of the circle
				SphereDiskLayerRadius=SphereRadius;
			}
			else{
				/*
				note we DON'T need to subtract the difference of the index to the edge, since it's already be done for the total layer from the previous calculations
				*/
				SphereDiskLayerRadius=SphereRadius*sin(acos((double)i/(double)SphereRadius)); 
			}
			residue=(int)(SphereDiskLayerRadius);

			if((SphereDiskLayerRadius-residue)>0.000000 && (SphereDiskLayerRadius-residue)<1.000000){ // (less than 1 but greater than 0) round up!
				SphereDiskLayerRadius+=1.0;
			}
			xStart=x-(int)SphereDiskLayerRadius;
			yStart=y+j; //goes up for 'j-height' ONLY; Each disk of the Tower of Hanoi/3D printing
			zStart=z+i;//-(int)SphereDiskLayerRadius;
			xStop=x+(int)SphereDiskLayerRadius;//Ignore for now *Direction_NorthSouth;
			yStop=y+j; // The height occurs on the same layer
			zStop=z+i;//+(int)SphereDiskLayerRadius*Direction_WestEast; //f'd up due to coords flipped: http://codeschool.org/3d-transformations-transcript/

			if(consoleORchat==0){
				if(OutputToFile==TRUE){
					sprintf(BUF_FILE1,"fill %i %i %i %i %i %i %s\r\n",xStart,yStart,zStart,xStop,yStop,zStop,buildingMaterial);
					TL_FILE_WRITE_STRING_ARRAY_NAMED(FILE1,BUF_FILE1);
				}
				else{
				printf("\nfill %i %i %i %i %i %i %s",xStart,yStart,zStart,xStop,yStop,zStop,buildingMaterial);
				}
			}
			else{
				if(OutputToFile==TRUE){
					sprintf(BUF_FILE1,"/fill %i %i %i %i %i %i %s\r\n",xStart,yStart,zStart,xStop,yStop,zStop,buildingMaterial);
					TL_FILE_WRITE_STRING_ARRAY_NAMED(FILE1,BUF_FILE1);
				}
				else{
					printf("\n/fill %i %i %i %i %i %i %s",xStart,yStart,zStart,xStop,yStop,zStop,buildingMaterial);
				}
			}
			if(i!=0 || Width%2==0){
				zStart=z-i;
				zStop=z-i;
				if(consoleORchat==0){
					if(OutputToFile==TRUE){
					sprintf(BUF_FILE1,"fill %i %i %i %i %i %i %s\r\n",xStart,yStart,zStart,xStop,yStop,zStop,buildingMaterial);
					TL_FILE_WRITE_STRING_ARRAY_NAMED(FILE1,BUF_FILE1);
					}
					else{					
						printf("\nfill %i %i %i %i %i %i %s",xStart,yStart,zStart,xStop,yStop,zStop,buildingMaterial);
					}
				}
				else{
					if(OutputToFile==TRUE){
						sprintf(BUF_FILE1,"/fill %i %i %i %i %i %i %s\r\n",xStart,yStart,zStart,xStop,yStop,zStop,buildingMaterial);
						TL_FILE_WRITE_STRING_ARRAY_NAMED(FILE1,BUF_FILE1);
					}
					else{
						printf("\n/fill %i %i %i %i %i %i %s",xStart,yStart,zStart,xStop,yStop,zStop,buildingMaterial);
					}
				}
			}
		}
	}
	
	if(OutputToFile==TRUE){
		TL_FILE_CLOSE_NAMED(FILE1);
	}

	return EXIT_SUCCESS;
}


int createDiamond(int consoleORchat, int x, int y, int z, char buildingMaterial[], int Direction_NorthSouth, int Direction_WestEast, int heightStart, int heightStop, int Width, int OutputToFile, char OutputFileName[]){
//example call: MFG.exe -x 0 -y 100 -z 0 --console -m glowstone -nhw -nf -s 7 -w 10

	//int Width, Depth, Height;
	int xStart,yStart,zStart;
	int xStop,yStop,zStop;
	int i;//,j,k;
//	int residue;
//	int offset;

	xStart=x+(Width/2);
	yStart=y;
	zStart=z-(Width/2);

	TL_FILE_IO_INSTALL_NAMED(FILE1);
	if(OutputToFile==TRUE){
		TL_FILE_OPEN_WRITE_MODE_APPEND_NAMED(OutputFileName, 0644,FILE1);
	}
	else{
		printf("\n\nCopy and paste this into your console/chat:");
	}
	
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

	do{//First Half Going Vertical; Increasing Width
		//printf("\n%i <%i,%i,%i> to <%i,%i,%i> ",i,xStart,yStart,zStart,xStart+i-1,yStart,zStart-i+1);
		xStop=xStart+i-1;
		yStop=yStart;
		zStop=zStart-i+1;
		if(consoleORchat==0){
			if(OutputToFile==TRUE){
				sprintf(BUF_FILE1,"fill %i %i %i %i %i %i %s\r\n",xStart,yStart,zStart,xStop,yStop,zStop,buildingMaterial);
				TL_FILE_WRITE_STRING_ARRAY_NAMED(FILE1,BUF_FILE1);
			}
			else{
				printf("\nfill %i %i %i %i %i %i %s",xStart,yStart,zStart,xStop,yStop,zStop,buildingMaterial);
			}
		}
		else{
			if(OutputToFile==TRUE){
				sprintf(BUF_FILE1,"/fill %i %i %i %i %i %i %s\r\n",xStart,yStart,zStart,xStop,yStop,zStop,buildingMaterial);
				TL_FILE_WRITE_STRING_ARRAY_NAMED(FILE1,BUF_FILE1);
			}
			else{
				printf("\n/fill %i %i %i %i %i %i %s",xStart,yStart,zStart,xStop,yStop,zStop,buildingMaterial);
			}
		}
		xStart--;
		yStart++;
		zStart++;		
	}while((i+=2)<Width);

	do{//Second Half Going Vertical; Decreasing Width
		//printf("\n%i <%i,%i,%i> to <%i,%i,%i> ",i,xStart,yStart,zStart,xStart+i-1,yStart,zStart-i+1);
		xStop=xStart+i-1;
		yStop=yStart;
		zStop=zStart-i+1;
		
		if(consoleORchat==0){
			if(OutputToFile==TRUE){
				sprintf(BUF_FILE1,"fill %i %i %i %i %i %i %s\r\n",xStart,yStart,zStart,xStop,yStop,zStop,buildingMaterial);
				TL_FILE_WRITE_STRING_ARRAY_NAMED(FILE1,BUF_FILE1);
			}
			else{
				printf("\nfill %i %i %i %i %i %i %s",xStart,yStart,zStart,xStop,yStop,zStop,buildingMaterial);
			}
		}
		else{
			if(OutputToFile==TRUE){
				sprintf(BUF_FILE1,"/fill %i %i %i %i %i %i %s\r\n",xStart,yStart,zStart,xStop,yStop,zStop,buildingMaterial);
				TL_FILE_WRITE_STRING_ARRAY_NAMED(FILE1,BUF_FILE1);
			}
			else{
				printf("\n/fill %i %i %i %i %i %i %s",xStart,yStart,zStart,xStop,yStop,zStop,buildingMaterial);
			}
		}		
		
		xStart++;
		yStart++;
		zStart--;			
	}while((i-=2)>0);
	
	if(OutputToFile==TRUE){
		TL_FILE_CLOSE_NAMED(FILE1);
	}
	
	return EXIT_SUCCESS;
}

int createCylinder(int consoleORchat, int x, int y, int z, char buildingMaterial[], int Direction_NorthSouth, int Direction_WestEast, int heightStart, int heightStop, int Height, int Width, int OutputToFile, char OutputFileName[]){
	int xStart,yStart,zStart;
	int xStop,yStop,zStop;
	int i,j;//,k;
	int residue;
	//int offset;

	xStart=x;
	yStart=y;
	zStart=z;

	TL_FILE_IO_INSTALL_NAMED(FILE1);
	if(OutputToFile==TRUE){
		TL_FILE_OPEN_WRITE_MODE_APPEND_NAMED(OutputFileName, 0644,FILE1);
	}
	else{
		printf("\n\nCopy and paste this into your console/chat:");
	}
	
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
			if(OutputToFile==TRUE){
				sprintf(BUF_FILE1,"fill %i %i %i %i %i %i %s\r\n",xStart,yStart,zStart,xStop,yStop,zStop,buildingMaterial);
				TL_FILE_WRITE_STRING_ARRAY_NAMED(FILE1,BUF_FILE1);
			}
			else{
				printf("\nfill %i %i %i %i %i %i %s",xStart,yStart,zStart,xStop,yStop,zStop,buildingMaterial);
			}
		}
		else{
			if(OutputToFile==TRUE){
				sprintf(BUF_FILE1,"/fill %i %i %i %i %i %i %s\r\n",xStart,yStart,zStart,xStop,yStop,zStop,buildingMaterial);
				TL_FILE_WRITE_STRING_ARRAY_NAMED(FILE1,BUF_FILE1);
			}
			else{
				printf("\n/fill %i %i %i %i %i %i %s",xStart,yStart,zStart,xStop,yStop,zStop,buildingMaterial);
			}
		}
		if(Width%2==0){//if EVEN Width 
			//printf("\n\n[DEBUGGING] EVEN WIDTH!\n");
			xStart=x-i-1; //-(int)LayerRadius;	
			xStop=x-i-1;  //+(int)LayerRadius*Direction_WestEast; //f'd up due to coords flipped: http://codeschool.org/3d-transformations-transcript/
			if(consoleORchat==0){
				if(OutputToFile==TRUE){
					sprintf(BUF_FILE1,"fill %i %i %i %i %i %i %s\r\n",xStart,yStart,zStart,xStop,yStop,zStop,buildingMaterial);
					TL_FILE_WRITE_STRING_ARRAY_NAMED(FILE1,BUF_FILE1);
				}
				else{
					printf("\nfill %i %i %i %i %i %i %s",xStart,yStart,zStart,xStop,yStop,zStop,buildingMaterial);
				}
			}
			else{
				if(OutputToFile==TRUE){
					sprintf(BUF_FILE1,"/fill %i %i %i %i %i %i %s\r\n",xStart,yStart,zStart,xStop,yStop,zStop,buildingMaterial);
					TL_FILE_WRITE_STRING_ARRAY_NAMED(FILE1,BUF_FILE1);
				}
				else{
					printf("\n/fill %i %i %i %i %i %i %s",xStart,yStart,zStart,xStop,yStop,zStop,buildingMaterial);
				}
			}
		}
		else{ //if ODD Width 
			if(i!=0){
			//	printf("\n\n[DEBUGGING] ODD WIDTH!\n");
				xStart=x-i;//-(int)LayerRadius;	
				xStop=x-i;//+(int)LayerRadius*Direction_WestEast; //f'd up due to coords flipped: http://codeschool.org/3d-transformations-transcript/
				if(consoleORchat==0){
					if(OutputToFile==TRUE){
						sprintf(BUF_FILE1,"fill %i %i %i %i %i %i %s\r\n",xStart,yStart,zStart,xStop,yStop,zStop,buildingMaterial);
						TL_FILE_WRITE_STRING_ARRAY_NAMED(FILE1,BUF_FILE1);
					}
					else{
						printf("\nfill %i %i %i %i %i %i %s",xStart,yStart,zStart,xStop,yStop,zStop,buildingMaterial);
					}
				}
				else{
					if(OutputToFile==TRUE){
						sprintf(BUF_FILE1,"/fill %i %i %i %i %i %i %s\r\n",xStart,yStart,zStart,xStop,yStop,zStop,buildingMaterial);				
						TL_FILE_WRITE_STRING_ARRAY_NAMED(FILE1,BUF_FILE1);
					}
					else{
						printf("\n/fill %i %i %i %i %i %i %s",xStart,yStart,zStart,xStop,yStop,zStop,buildingMaterial);
					}
				}				
			}
		}

		}
	}
	
	if(OutputToFile==TRUE){
		TL_FILE_CLOSE_NAMED(FILE1);
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
