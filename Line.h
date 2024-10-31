#ifndef _LINE_H_
#define _LINE_H_

#include <iostream>
#include "Point.h"
#include "Figure.h"
#include "extendLib/rapid_xml/rapidxml.hpp"

using namespace std;
using namespace rapidxml;

class Line : public Figure
{
private:
	xml_node<>* root_node;
    MyPoint::Point p1;
    MyPoint::Point p2;
public:
    Line();
    Line(MyPoint::Point p1, MyPoint::Point p2);
    ~Line();
    void setP1(MyPoint::Point p1);
    void setP2(MyPoint::Point p2);
    MyPoint::Point getP1();
    MyPoint::Point getP2();
    void draw() override;
};

#endif