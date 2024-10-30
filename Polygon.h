#ifndef _POLYGON_H_
#define _POLYGON_H_

#include "Figure.h"
#include <vector>
#include <sstream>
#include "Point.h"

using namespace Gdiplus;
using namespace std;
using namespace rapidxml;

class Polygon : public Figure
{
private:
	xml_node<>* rootNode;
	SVGAttributes attributes;
	vector <MyPoint::Point> points;
public:
	Polygon(xml_node<>* rootNode);
	//to string
	string toString();
	void draw() override;
};

#endif
