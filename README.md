MFtG - Minecraft Fill-tool Generator (v1.0)
==========================================
This program is designed to help generate 'simple' geometric shapes
in Minecraft. The output of the program will be the '/fill' commands
needed to render the specified shapes, and can be manually entered in
the chat window in game or bulk pasted into the server's console.

**Simply put: This is a 3D printer for minecraft.**

The tool supports both commandline passing of fields for shapes or it can
executed without fields to run in an interactive, Q&A mode.

                                               ActuallyFro - April 2015	
Commandline Flags
==================
The following are all of the supported commandline flags that can be used
when executing MFG from a shell:

Coordinates
-----------
- -x \<integer>: This sets the X-value starting point for the shape.
- -y \<integer>: This sets the Y-value starting point for the shape.
- -z \<integer>: This sets the Z-value starting point for the shape.

These values can be found by pressing F3 while running Minecraft.


Dimensions
----------
The inputs for the shape's dimensions vary per shape, but ultimately these
settings allow can allow for custom skewing of the many of the shapes.

- --depth (-d) \<integer>: The North/South or 'into the screen' (z-axis)
- --width (-w) \<integer>: This sets the width going West/East (x-axis)
- --height (-h) \<integer>: This will set how tall the shape is (y-axis)


Shapes
------
As of v1.0 there are eight basic shapes that can be selected. These are refered
to by their respective 1 through 8 value as defined in the list below. Also,
the shapes have a 'Start' orientation from where they are measured/placed.

- --shape (-s) \<1-8>: Select a shape from the shape ID's.

### Current Shape List
1. Square (Dimensions: Width; Start: Bottom, SW Corner)
2. Rectangle (Dimensions: Height, Width, Depth; Start: Bottom, SW Corner)
3. Triangular Prism* (Dimensions:Width, Depth; Start: Bottom, SW Corner)
4. Pyramid (Dimensions: Width; Start: Bottom, SW Corner)
5. Sphere (Dimensions: Width; Start: Bottom, Center)
6. Cylinder (Dimensions: Height, Width; Start: Center)
7. Diamond (Dimension: Width; Start: Bottom, SW Corner)
8. Cone (Dimensions: Height, Width; Start: Center)

### X/Z Centering Math
1. Square (Find SW Corner)
2. Rectangle (Find SW Corner)
3. Tri-Prism* (Find SW Corner, Subtract Width/2 from X, Add Depth/2 to Z)
3. Tri-Prism Rotated (Find NW Corner, Subtract Width/2 from Z, Subtract Depth/2 deom X)
4. Pyramid (Find Center: Subtract Width/2 from X, Add Width/2 to Z)
5. Sphere (Not Needed)
6. Cylinder (Not Needed)
7. Diamond (Find Center: Subtract Width/2 from X, Add Width/2 to Z)
8. Cone (Not Needed)

### Y Centering Math
1. Square (Find Center: Subtract Height/2 from y)
2. Rectangle (Find Center: Subtract Height/2 from y)
3. Triangular Prism*  (Find Center: Subtract Height/2 from y)
4. Pyramid  (Find Center: Subtract Width/2 from y)
5. Sphere (Find Center: Subtract Width/2 from y)
6. Cylinder (Find Center: Subtract Height/2 from y)
7. Diamond (Find Center: Subtract Width/2 from Y)
8. Cone (Find Center: Subtract Height/2 from y)

Material
--------
The material can be ANY minecraft ID that is in vanilla minecraft.
(or ID's that are added in mods). Ensure you place any needed colons!

- --material(-m) \<minecraft name id>: any block ID.

### Random ID Listing Website
Use at your own risk: [Cheatsheet](http://minecraft-ids.grahamedgecombe.com/)

Files
-----
The ability to output the fill commands to a file has been added due to the
complexity of the shapes (from poorly optimized area calculations). This allows
for the file to be accessed for a simple copy/paste of the fill commands.

**By default the tool appends a file and __DOES NOT overwrite the file__**

- --no-file (-nf): Triggers that no file is desired and the commands will
                   be printed to the screen.

- --output-default (-O): Output's the commands to 'MFG_output.txt'

- --output-true: Signals the desire to use an output file, but manual
                 entry of the file's name will be needed.

- --output-name (-o) \<string>: This allows for a renaming of the file's name.


Hollowed Shapes
---------------
This command has been added since its conceivable that shapes would be desired
to be hollowed out to help with the creation of structures/buildings. MFG 
will 'shrink' the given inputs by the desired wall width, and automatically
render the commands to fill the shape with air blocks.

- --nothollow (-nhw): Leaves the shape as solid-filled with the original
                      material.

- --hollow (-hw): Signals the desire to automatically generate air blocks, which
                  will hollow out the shape.

- --width-hollow (-wh) <integer>: Specifies the width/thickness of the 
                                  shape's walls.

Target Command Window
---------------------
Given the complexity of some of the shapes it was determined that a server,
console window would be the only realistic means to enter all of the fill
commands. The option allows the leading forward slash to be present, or not,
on the generated commands. 

- --console: Prints commands without the leading '/'.

- --chat: Prints commands with the leading '/' 


Rotation
---------
Rotation is currently only implemented with the Triangular Prism*. 
The default orientation is the 'print' South to North while facing
the end showing the triangle. This will rotate the fill to from West to East.

- --rotate: Turns the shape generation by 90 degrees clockwise.

Protips
--------
- Server.properties: max-tick-time=#00...00 -- this allows for massive lag
- Windows CMD: Alt+Space, E, P -- Pastes the buffer to the command line
- Windows CMD: Alt+Space, E, S, Enter -- Copy the command line to the clipboard
- Always output __shapes with circles__ to FILE!
- Use a server to start a single player world as to use the command line
- When you mess up: find and replace all ID's with 'air' to 'delete' the blocks


Command Line Execution Examples
-------------------------------
### Nether Brick Cone having a diameter of 10, and height of 5 @ <286,3,-277>: 
MFG -m double_stone_slab:6 -s 8 -x 286 -y 3 -z -277 --height 5 --width 10 -nf -nhw --console

### Quartz Cylinder (diameter of 5, height of 50 @ <286,7,-277>) with a file: 
MFG -m minecraft:quartz_block -s 6 -x 286 -y 7 -z -277 -h 50 -w 5 --console -O -nhw

### Brick Diamond  having a width of 10@ <276,14,-267> (center at 286,25,-277): 
MFG -m minecraft:brick_block -s 7 -x 276 -y 14 -z -267 -w 20 -hw -wh 1 --console -nf

### Glowstone 'Rectangle', manually hollowed out (width of 21/19@) <276,24,-267>: 
MFG -m glowstone -s 2 -x 276 -y 24 -z -267 -w 21 -d 21 -h 1 --console -nf -nhw
MFG -m air -s 2 -x 277 -y24 -z -268 -w 19 -d 19 -h 1 --console -nf -nhw

### Glowstone Tri-Prism having a depth of 3@ <281,22,-276>: 
MFG -m glowstone -s 3 -x 281 -y 22 -z -276 -w 10 -d 3 --console -nf -nhw

### Glowstone Tri-Prism having a depth of 1@ <281,22,-277>: 
MFG -m glowstone -s 3 -x 286 -y 22 -z -282 -w 10 -d 1 --console -nf -nhw --rotate

### Lava Sphere having a diameter of 100@ <0,100,0> with a default file: 
MFG -m glass -s 5 -x 286 -y 105 -z -277 -w 100 -hw -wh 1 --console -O
*Just open the file, find an replace 'air' with lava.*

### Diamond Pyramid having a width of 50@ <0,100,0> with a default file: 
MFG -m diamond_block -s 4 -x 261 -y 191 -z -252 -w 50 -nhw --console -O

### Because, Science:
/fill 286 155 -277 286 155 -277 beacon


