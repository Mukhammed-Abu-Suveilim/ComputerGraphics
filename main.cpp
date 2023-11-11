#include <graphics.h>
#include <cmath>

const double PI = 3.14159265;

void pifagor(int n, int x0, int y0, int a, double fi, double alpha) {
    if (n == 0) return;

    // Вычисление координат вершин "домика"
    int x1 = x0 + static_cast<int>(a * cos(fi));
    int y1 = y0 - static_cast<int>(a * sin(fi));
    int x2 = x1 + static_cast<int>(a * cos(alpha + fi));
    int y2 = y1 - static_cast<int>(a * sin(alpha + fi));

    // Рисование "домика"
    line(x0, y0, x1, y1);
    line(x1, y1, x2, y2);

    // Рекурсивные вызовы для двух "домиков" на скатах крыши
    pifagor(n - 1, x1, y1, static_cast<int>(a / 2), fi + alpha, alpha);
    pifagor(n - 1, x2, y2, static_cast<int>(a / 2), fi - alpha, alpha);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    // Начальные параметры: глубина рекурсии, координаты точки привязки, длина, угол наклона и угол крыши
    int depth = 5;
    int x0 = 300, y0 = 400;
    int length = 100;
    double angle = PI / 4; // Угол наклона основания "домика"
    double roofAngle = PI / 4; // Угол крыши

    pifagor(depth, x0, y0, length, angle, roofAngle);

    getch();
    closegraph();

    return 0;
}
