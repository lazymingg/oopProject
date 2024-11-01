#include "Ellipse.h"

MyFigure::Ellipse::Ellipse(xml_node<>* rootNode, Gdiplus::Graphics& graphics)
    : rootNode(rootNode), graphics(graphics), attributes(rootNode) {
    
    center.setX(stoi(rootNode->first_attribute("cx")->value()));
    center.setY(stoi(rootNode->first_attribute("cy")->value()));
    rx = stoi(rootNode->first_attribute("rx")->value());
    ry = stoi(rootNode->first_attribute("ry")->value());
}

void MyFigure::Ellipse::drawEllipse(Graphics& graphics) {
    SolidBrush fillBrush(attributes.getFillColor());
    Pen strokePen(attributes.getStrokeColor(), attributes.getStrokeWidth());

    graphics.FillEllipse(&fillBrush, center.getX() - rx, center.getY() - ry, rx * 2, ry * 2);
    graphics.DrawEllipse(&strokePen, center.getX() - rx, center.getY() - ry, rx * 2, ry * 2);
}

void MyFigure::Ellipse::draw() {
    std::cout << "Draw Ellipse: center = (" << center.getX() << ", " << center.getY() << "), ";
    std::cout << "rx = " << rx << ", ry = " << ry << "\n\n";
    drawEllipse(graphics);
}
