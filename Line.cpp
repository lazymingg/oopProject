#include "Line.h"


Line::Line()
{
	//intialize the points to (0,0)
	p1 = MyPoint::Point();
	p2 = MyPoint::Point();
	root_node = nullptr;
}
Line::Line(MyPoint::Point p1, MyPoint::Point p2)
{
    this->p1 = p1;
    this->p2 = p2;
	root_node = nullptr;
}
Line::~Line()
{
    //nothing to do here
}
void Line::setP1(MyPoint::Point p1)
{
    this->p1 = p1;
}
void Line::setP2(MyPoint::Point p2)
{
    this->p2 = p2;
}
MyPoint::Point Line::getP1()
{
    return p1;
}
MyPoint::Point Line::getP2()
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
