#include <graphics.h>
#include <math.h>
#include <iostream>
#include <conio.h>
using namespace std;
#define PI 3.14162

float m1 = 10;
float m2 = 10;
float a1 = PI/2;
float a2 = 0;
float r1 = 100;
float r2 = 100;

float a1_v = 0;
float a2_v = 0;
float a1_a;
float a2_a;

float g = 0.5;

void calcAcc() {
    float num1 = -g * (2*m1 + m2) * sin(a1);
    float num2 = -m2 * g * sin(a1 - 2*a2);
    float num3 = -2 * sin(a1 - a2) * m2;
    float num4 = a2_v * a2_v * r2 + a1_v*a1_v*r1*cos(a1-a2);

    float den = r1 * (2*m1 + m2 - m2 * cos(2*a1 - 2*a2));

    a1_a = (num1 + num2 + num3*num4)/den;

    num1 = 2 * sin(a1 - a2);
    num2 = a1_v * a1_v * r1 * (m1 + m2);
    num3 = g * (m1 + m2) * cos(a1);
    num4 = a2_v * a2_v * r2 * m2 * cos(a1 - a2);

    den = r2 * (2*m1 + m2 - m2 * cos(2*a1 - 2*a2));

    a2_a = (num1 * (num2 + num3 + num4))/den;
}

void draw() {
    calcAcc();

    float x1 = r1 * sin(a1);
    float y1 = r1 * cos(a1);
    float x1r = (r1 + m1) * sin(a1);
    float y1r = (r1 + m1) * cos(a1);

    setcolor(BLACK);

    line(300, 50, 300 + x1, 50 + y1);
    circle(300 + x1r, 50 + y1r, m1);
    setfillstyle(SOLID_FILL, BLACK);
    floodfill(300 + x1r, 50 + y1r, BLACK);

    float x2 = x1 + (r2 * sin(a2));
    float y2 = y1 + (r1 * cos(a2));
    float x2r = x1 + (r2 + m1) * sin(a2);
    float y2r = y1 + (r2 + m1) * cos(a2);

    setcolor(BLACK);

    line(300 + x1r, 50 + y1r, 300 + x2, 50 + y2);
    circle(300 + x2r, 50 + y2r, m1);
    setfillstyle(SOLID_FILL, BLACK);
    floodfill(300 + x2r, 50 + y2r, BLACK);

    a1_v += a1_a;
    a2_v += a2_a;

    a1 += a1_v;
    a2 += a2_v;

    delay(10);

    cleardevice();
}

int main() {
    int gd = DETECT, gc, errorcode;
    initgraph(&gd, &gc, NULL);

    while(true) {
        setfillstyle(SOLID_FILL, WHITE);
        floodfill(50, 50, WHITE);
        draw();
    }

    getch();
}
