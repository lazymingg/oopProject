#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_

#include "Figure.h"
#include "Point.h"

using namespace Gdiplus;
using namespace std;
using namespace rapidxml;
namespace MyFigure
{
	class Rectangle : public Figure
	{
	private:
		xml_node<>* rootNode;
		SVGAttributes attributes;// no default constructor must be initilized
		MyPoint::Point point;
		int height;
		int width;
		Graphics &graphics;
	public:
		//intialyze list 
		Rectangle(xml_node<>* rootNode, Gdiplus::Graphics& graphics);
		//to string
		void printInfomation();
		void draw() override;
	};
}

#endif
