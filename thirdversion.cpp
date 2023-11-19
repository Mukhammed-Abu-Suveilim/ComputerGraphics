#include "graphics.h"
#include <cmath>

const double PI = M_PI;

struct Point {
    int x;
    int y;
};

void pifagor(int n, int x0, int y0, int a, double fi, double alpha) {
    if (n == 0) return;

    Point p1 = {x0 + a * cos(fi), y0 - a * sin(fi)};
    Point p2 = {x0 - a * sin(fi), y0 - a * cos(fi)};
    Point p3 = {p1.x - a * sin(fi), p1.y - a * cos(fi)};
    Point p4 = {p3.x - a * sin(alpha) * sin(alpha + fi), p3.y - a * sin(alpha) * cos(alpha + fi)};

    // draw square and triangle
    setcolor(YOUR_COLOR_CODE);
    line(x0, y0, p1.x, p1.y);
    line(x0, y0, p2.x, p2.y);
    line(p1.x, p1.y, p3.x, p3.y);
    line(p2.x, p2.y, p3.x, p3.y);
    line(p2.x, p2.y, p4.x, p4.y);
    line(p3.x, p3.y, p4.x, p4.y);

    delay(100); // Добавление задержки

    // Recursively call the function for the four smaller squares
    pifagor(n-1, p4.x, p4.y, sin(alpha) * a, fi + alpha - PI/2, alpha);
    pifagor(n-1, p2.x, p2.y, cos(alpha) * a, fi + alpha, alpha);
}

int main() {
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
