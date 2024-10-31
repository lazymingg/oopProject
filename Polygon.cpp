#include "Polygon.h"

using namespace Gdiplus;
using namespace std;
using namespace rapidxml;

MyFigure::Polygon::Polygon(xml_node<>* rootNode)
{
	this->rootNode = rootNode;
	// Set attributes
	xml_attribute<>* attribute = rootNode->first_attribute();
	while (attribute != NULL)
	{
		string name = attribute->name();
		string value = attribute->value();
		if (name == "fill")
		{
			attributes.setFill(value);
		}
		else if (name == "stroke")
		{
			attributes.setStroke(value);
		}
		else if (name == "stroke-width")
		{
			attributes.setStrokeWidth(stof(value));
		}
		else if (name == "opacity")
		{
			attributes.setOpacity(stof(value));
		}
		else if (name == "fill-opacity")
		{
			attributes.setFillOpacity(stof(value));
		}
		else if (name == "stroke-opacity")
		{
			attributes.setStrokeOpacity(stof(value));
		}
		else if (name == "stroke-linecap")
		{
			attributes.setStrokeLinecap(value);
		}
		else if (name == "stroke-linejoin")
		{
			attributes.setStrokeLinejoin(value);
		}
		else if (name == "stroke-dasharray")
		{
			attributes.setStrokeDasharray(value);
		}
		else if (name == "transform")
		{
			attributes.setTransform(value);
		}
		attribute = attribute->next_attribute();
	}
	// Set points
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
	cout << "Drawing a polygon" << endl;
}