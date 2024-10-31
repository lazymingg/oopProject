#include "Ellipse.h"

// Default constructor
MyFigure::Ellipse::Ellipse()
{
	root_node = nullptr;
	center = MyPoint::Point();
	strokeColor = fill = Color(0, 0, 0, 0);
	graphic
}

// Parameterized constructor
MyFigure::Ellipse::Ellipse(MyPoint::Point center, INT rx, INT ry, Color strokeColor, INT strokeWidth, Color fill)
{
	this->center = MyPoint::Point(center);

	this->rx = rx;
	this->ry = ry;

	this->strokeColor = strokeColor;
	this->strokeWidth = strokeWidth;
	this->fill = fill;
}

// Copy constructor
MyFigure::Ellipse::Ellipse(const Ellipse& other)
{
	this->center = MyPoint::Point(other.center);

	this->rx = other.rx;
	this->ry = other.ry;

	this->strokeColor = other.strokeColor;
	this->strokeWidth = other.strokeWidth;
	this->fill = other.fill;
}

void MyFigure::Ellipse::drawEllipse(Graphics& graphics)
{
	SolidBrush fillBrush(fill);
	Pen strokePen(strokeColor, strokeWidth);

	graphics.FillEllipse(&fillBrush, center.getX() - rx, center.getY() - ry, rx * 2, ry * 2);
	graphics.DrawEllipse(&strokePen, center.getX() - rx, center.getY() - ry, rx * 2, ry * 2);
}

void MyFigure::Ellipse::draw()
{
	cout << "Draw Ellipse\n";
	drawEllipse()
}