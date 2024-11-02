#ifndef _TEXT_H_
#define _TEXT_H_

#include "Figure.h"
#include "Point.h"

using namespace Gdiplus;
using namespace std;
using namespace rapidxml;
namespace MyFigure
{
	class Text : public Figure
	{
	private:
		xml_node<>* rootNode;
		SVGAttributes attributes;// no default constructor must be initilized
		MyPoint::Point point;
		int font;
		Graphics &graphics;
	public:
		//intialyze list 
		Text(xml_node<>* rootNode, Gdiplus::Graphics& graphics);
		//to string
		void printInfomation();
		void draw() override;
	};
}

#endif
