#include "graphics.h"
#include <cmath>

const double PI = 3.14159265;



void pifagor(int n, int x0, int y0, int a, double fi, double alpha) 
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
	line(x0,y0,x1,y1);
	line(x0,y0,x2,y2);
	line(x1,y1,x3,y3);
	line(x2,y2,x3,y3);	
	line(x2,y2,x4,y4);
	line(x3,y3,x4,y4);	


    // Recursively call the function for the four smaller squares
    pifagor(n-1, x4, y4, sin(alpha) * a, fi + alpha - PI/2, alpha);
    pifagor(n-1, x2, y2, cos(alpha) * a, fi + alpha, alpha);
	//pifagor(n - 1, x1, y1, a / 2, fi + alpha, alpha);
    //pifagor(n - 1, x2, y2, a / 2, fi - alpha, alpha);
    //pifagor(n - 1, x4, y4, a / 2, alpha, fi);
}

int main() 
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Initial parameters
    int depth = 10;
    int x0 = 600, y0 = 600;
    int a = 100;
    double fi = 0; // Angle of the base square
    double alpha = PI/ 6; // Angle of the triangle on top


	// Draw the fractal
    pifagor(depth, x0, y0, a, fi, alpha);

    getch();
    closegraph();

    return 0;
}

