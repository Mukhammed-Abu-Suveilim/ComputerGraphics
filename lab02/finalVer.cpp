#include <iostream>
#include <cmath>
#include "graphics.h"

const double PI = 3.14159265;

void drawCircle(int xc, int yc, int x, int y, int c) 
{
	putpixel(xc+y, yc+x, c); //1 
    putpixel(xc+x, yc+y, c); //2
    putpixel(xc-x, yc+y, c); //3
    putpixel(xc-y, yc+x, c); //4
    putpixel(xc-y, yc-x, c); //5
    putpixel(xc-x, yc-y, c); //6
    putpixel(xc+x, yc-y, c); //7
    putpixel(xc+y, yc-x, c); //8
} 

void mycirc(int xc, int yc, int r, int c) 
{ 
    int x = 0, y = r; 
    int p = 3 - 2 * r; 
    drawCircle(xc, yc, x, y, c); 
    while (y >= x) 
    { 
        // for each pixel we will 
        // draw all eight pixels 
          
        x++; 
  
        // check for decision parameter 
        // and correspondingly  
        // update d, x, y 
        if (p < 0) 
        {   
            p = p + 4 * x + 6;
			drawCircle(xc, yc, x, y, c);  
        } 
        else
		{
			y--;
            p = p + 4 * (x - y) + 10; 
        	drawCircle(xc, yc, x, y, c); 
        	delay(50);
		} 
    } 
} 

void myline(int x1, int y1, int x2, int y2, int c) 
{
    // calculate dx and dy
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    
    // calculate decision parameter
    int p = 2 * dy - dx;
    
    // determine which direction to step in
    int stepx = (x1 < x2) ? 1 : -1;
    int stepy = (y1 < y2) ? 1 : -1;
    
    // initialize current position
    int x = x1;
    int y = y1;
    
    // draw the line
    while (x != x2 || y != y2) 
	{
        // if d1 < d2
        if (p < 0) 
		{
            // case 1: p < 0, move to the right and update p
            p += 2 * dy;
            x += stepx;
        } else if (p >= 0 && p < dx) //if p > dx we would need to move more than one pixel in x-direction
		{
            // case 2: 0 <= p < dx, move diagonally
            p += 2 * dy - 2 * dx;
            x += stepx;
            y += stepy;
        } else 
		{
            // case 3: p >= dx, move up/down (vertical line)
            p += -2 * dx;
            y += stepy;
        }
        
        // draw pixel at current position
        putpixel(x, y, c);
    }
}


void pifagor(int n, int x0, int y0, int a, double fi, double alpha, int c)
{
	if (n == 0) return;
	//coordiantes for square
	int x1 = x0 + (a * cos(fi));
	int y1 = y0 - (a * sin(fi));
	int x2 = x0 - (a * sin(fi));
	int y2 = y0 - (a * cos(fi));
	int x3 = x1 - (a * sin(fi));
	int y3 = y1 - (a * cos(fi));
	int x4 = x3 - (a * sin(alpha) * sin(alpha + fi));
	int y4 = y3 - (a * sin(alpha) * cos(alpha + fi));
	
	//draw sqaure and triangle
	myline(x0,y0,x1,y1,c);
	myline(x0,y0,x2,y2,c);
	myline(x1,y1,x3,y3,c);
	myline(x2,y2,x3,y3,c);
	myline(x2,y2,x4,y4,c);
	myline(x3,y3,x4,y4,c);
	
	pifagor(n-1, x4, y4, sin(alpha) * a, fi + alpha - PI/2, alpha, c);
	pifagor(n-1, x2, y2, cos(alpha) * a, fi + alpha, alpha, c);
	
}
int main() 
{

    // initialize graphics window
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    
    // Initial parameters
    int depth = 5;
    int x0 = 600, y0 = 600;
    int a = 100;
    double fi = 0; // Angle of the base square
    double alpha = PI/ 6; // Angle of the triangle on top
    int xc = 1000, yc = 400, r = 100, c = YELLOW; 

	// Draw the fractal
    pifagor(depth, x0, y0, a, fi, alpha, c);

    mycirc(xc,yc,r, c);
    myline(100, 200, 400, 500, 6);
    getch();
    closegraph();
    return 0;
}

