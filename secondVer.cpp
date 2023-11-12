#include <graphics.h>
#include <cmath>

const double PI = 3.14159265;

void pifagor(int n, int x0, int y0, int a, double fi, double alpha) {
    if (n == 0) return;

    // Calculate coordinates of square vertices
    int x1 = x0 + static_cast<int>(a * cos(fi));
    int y1 = y0 - static_cast<int>(a * sin(fi));
    int x2 = x1 + static_cast<int>(a * cos(alpha + fi));
    int y2 = y1 - static_cast<int>(a * sin(alpha + fi));
    int x3 = x0 + static_cast<int>(a * cos(alpha));
    int y3 = y0 - static_cast<int>(a * sin(alpha));

    // Draw the square
    line(x0, y0, x1, y1);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x0, y0);

    // Calculate coordinates of the top of the triangle
    int x4 = x1 + static_cast<int>((a / 2) * cos(alpha + fi - PI / 2));
    int y4 = y1 - static_cast<int>((a / 2) * sin(alpha + fi - PI / 2));

    // Draw the triangle on top
    line(x1, y1, x4, y4);
    line(x4, y4, x2, y2);

    // Recursively call the function for the four smaller squares
    pifagor(n - 1, x1, y1, a / 2, fi + alpha, alpha);
    pifagor(n - 1, x2, y2, a / 2, fi - alpha, alpha);
    pifagor(n - 1, x3, y3, a / 2, alpha, alpha);
    pifagor(n - 1, x4, y4, a / 2, fi + alpha - PI / 2, alpha);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    // Initial parameters
    int depth = 3;
    int x0 = 300, y0 = 400;
    int length = 200;
    double angle = PI / 4; // Angle of the base square
    double roofAngle = PI / 4; // Angle of the triangle on top

    pifagor(depth, x0, y0, length, angle, roofAngle);

    getch();
    closegraph();

    return 0;
}
