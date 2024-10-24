#ifndef _LINE_H_
#define _LINE_H_

#include <iostream>
#include "Point.h"
#include "Figure.h"
using namespace std;

class Line : public Figure
{
private:
    Point p1;
    Point p2;
public:
    Line();
    Line(Point p1, Point p2);
    ~Line();
    void setP1(Point p1);
    void setP2(Point p2);
    Point getP1();
    Point getP2();
    void draw() override;
};
#endif