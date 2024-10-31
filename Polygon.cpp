#include "Polygon.h"

using namespace Gdiplus;
using namespace std;
using namespace rapidxml;

MyFigure::Polygon::Polygon(xml_node<>* rootNode, Gdiplus::Graphics& graphics)
    : rootNode(rootNode), graphics(graphics)
{
    // Đặt các thuộc tính từ XML
    xml_attribute<>* attribute = rootNode->first_attribute();
    while (attribute != NULL)
    {
        string name = attribute->name();
        string value = attribute->value();
        if (name == "fill")
        {
			attributes.setFillColor(value);
            attributes.setFill(value);
        }
        else if (name == "stroke")
        {
			attributes.setStrokeColor(value);
            attributes.setStroke(value);
        }
        else if (name == "stroke-width")
            attributes.setStrokeWidth(stof(value));
        else if (name == "opacity")
            attributes.setOpacity(stof(value));
        else if (name == "fill-opacity")
            attributes.setFillOpacity(stof(value));
        else if (name == "stroke-opacity")
            attributes.setStrokeOpacity(stof(value));
        else if (name == "stroke-linecap")
            attributes.setStrokeLinecap(value);
        else if (name == "stroke-linejoin")
            attributes.setStrokeLinejoin(value);
        else if (name == "stroke-dasharray")
            attributes.setStrokeDasharray(value);
        else if (name == "transform")
            attributes.setTransform(value);
        attribute = attribute->next_attribute();
    }

    // Đặt các điểm từ thuộc tính "points"
    string points = rootNode->first_attribute("points")->value();
    stringstream ss(points);
    string point;
    while (getline(ss, point, ' '))
    {
        stringstream ssPoint(point);
        string x, y;
        getline(ssPoint, x, ',');
        getline(ssPoint, y, ',');
        this->points.push_back(MyPoint::Point(stoi(x), stoi(y)));
    }
}

void MyFigure::Polygon::printInfomation()
{
	cout << "polygon" << endl;
	attributes.printAttributes();
	for (int i = 0; i < points.size(); i++)
	{
		points[i].print();
	}
}
void MyFigure::Polygon::draw()
{
	// draw polygon here
	// draw fill polygon first
	if (attributes.getFill() != "none")
	{
		Color fillColor = attributes.getFillColor();
        //ajust opacity
		int opacity = attributes.getFillOpacity() * 255;
		fillColor = Color(opacity, fillColor.GetR(), fillColor.GetG(), fillColor.GetB());
		SolidBrush brush(fillColor);
		//print color

		Point* pointArray = new Point[points.size()];
		for (int i = 0; i < points.size(); i++)
		{
			pointArray[i].X = points[i].getX();
			pointArray[i].Y = points[i].getY();
		}
		graphics.FillPolygon(&brush, pointArray, points.size());
		delete[] pointArray;
	}
	//draw stroke
	if (attributes.getStroke() != "none")
	{
		Color strokeColor = attributes.getStrokeColor();
		//ajust opacity
		int opacity = attributes.getStrokeOpacity() * 255;
		strokeColor = Color(opacity, strokeColor.GetR(), strokeColor.GetG(), strokeColor.GetB());
		Pen pen(strokeColor, attributes.getStrokeWidth());
		//print color
		graphics.SetSmoothingMode(SmoothingMode::SmoothingModeAntiAlias);
		graphics.DrawPolygon(&pen, (Point*)&points[0], points.size());
	}
}