#include "../include/Line.h"

Line::Line()
{
    //nothing to do here
}
Line::Line(Point p1, Point p2)
{
    this->p1 = p1;
    this->p2 = p2;
}
Line::~Line()
{
    //nothing to do here
}
void Line::setP1(Point p1)
{
    this->p1 = p1;
}
void Line::setP2(Point p2)
{
    this->p2 = p2;
}
Point Line::getP1()
{
    return p1;
}
Point Line::getP2()
{
    return p2;
}
void Line::draw()
{
    cout << "Draw Line from ";
    p1.print();
    cout << " to ";
    p2.print();
    cout << endl;
}
