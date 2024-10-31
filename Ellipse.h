#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "Figure.h"
#include "Point.h"

namespace MyFigure {
	class Ellipse : public Figure
	{
	private:
		xml_node<>* root_node;
		MyPoint::Point center;
		INT rx;
		INT ry;
		Color strokeColor;
		INT strokeWidth;
		Color fill;
		Graphics& graphics;
	public:
		// Default constructor
		Ellipse();

		// Parameterized constructor
		Ellipse(MyPoint::Point center, INT rx, INT ry, Color strokeColor, INT strokeWidth, Color fill);

		// Copy constructor
		Ellipse(const Ellipse& other);

		void drawEllipse(Graphics& graphics);
		void draw() override;
	};
}

#endif