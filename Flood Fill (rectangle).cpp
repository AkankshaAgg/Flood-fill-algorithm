// program to fill polygon using floodfill 
// algorithm 
#include <graphics.h> 
#include <stdio.h> 

// flood fill algorithm 
void flood(int x, int y, int newCol, int oldCol) 
{ 
	// check current pixel is old color or not 
	if (getpixel(x, y) == oldCol) { 

		// put new pixel with new color 
		putpixel(x, y, newCol); 

		// recursive call for bottom pixel fill 
		flood(x + 1, y, newCol, oldCol); 

		// recursive call for top pixel fill 
		flood(x - 1, y, newCol, oldCol); 

		// recursive call for right pixel fill 
		flood(x, y + 1, newCol, oldCol); 

		// recursive call for left pixel fill 
		flood(x, y - 1, newCol, oldCol); 
	} 
} 

int main() 
{ 
	int gd, gm = DETECT; 

	// initializing the graph using initgraph
	initgraph(&gd, &gm, ""); 

	// coordinates of rectangle
	int top, left, bottom, right; 

	top = left = 50; 
	bottom = right = 300; 

	// rectangle for print rectangle 
	rectangle(left, top, right, bottom); 

	// starting cordinate from where filling will start
	int x = 51; 
	int y = 51; 

	int oldcolor = 0; 
	int newcolor = 12; 

	// call for fill rectangle 
	flood(x, y, newcolor, oldcolor); 
	getch(); 

	return 0; 
} 

