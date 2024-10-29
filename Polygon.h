#ifndef _POLYGON_H_
#define _POLYGON_H_

#include <iostream>
#include <vector>

//#include "Point.h"
#include "Figure.h"
#include "extendLib/rapid_xml/rapidxml.hpp"
#include <windows.h>
#include <gdiplus.h>
using namespace Gdiplus;
#pragma comment (lib,"Gdiplus.lib")

using namespace std;
using namespace rapidxml;

class Polygon : public Figure
{
private:
	xml_node<>* rootNode;
	vector <Point> points;
public:
	Polygon(xml_node<>* rootNode);
	void draw() override;
};

#endif
