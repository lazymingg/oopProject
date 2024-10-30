#include "SVGAttributes.h"

// Constructor
SVGAttributes::SVGAttributes()
    : fill("none"), stroke("none"), strokeWidth(1.0f), opacity(1.0f),
    fillOpacity(1.0f), strokeOpacity(1.0f),
    strokeLinecap("butt"), strokeLinejoin("miter"),
    strokeDasharray(""), transform("") {}

// Getters and setters
void SVGAttributes::setFill(const std::string& color) { fill = color; }
std::string SVGAttributes::getFill() const { return fill; }

void SVGAttributes::setStroke(const std::string& color) { stroke = color; }
std::string SVGAttributes::getStroke() const { return stroke; }

void SVGAttributes::setStrokeWidth(float width) { strokeWidth = width; }
float SVGAttributes::getStrokeWidth() const { return strokeWidth; }

void SVGAttributes::setOpacity(float value) { opacity = value; }
float SVGAttributes::getOpacity() const { return opacity; }

void SVGAttributes::setFillOpacity(float value) { fillOpacity = value; }
float SVGAttributes::getFillOpacity() const { return fillOpacity; }

void SVGAttributes::setStrokeOpacity(float value) { strokeOpacity = value; }
float SVGAttributes::getStrokeOpacity() const { return strokeOpacity; }

void SVGAttributes::setStrokeLinecap(const std::string& cap) { strokeLinecap = cap; }
std::string SVGAttributes::getStrokeLinecap() const { return strokeLinecap; }

void SVGAttributes::setStrokeLinejoin(const std::string& join) { strokeLinejoin = join; }
std::string SVGAttributes::getStrokeLinejoin() const { return strokeLinejoin; }

void SVGAttributes::setStrokeDasharray(const std::string& dash) { strokeDasharray = dash; }
std::string SVGAttributes::getStrokeDasharray() const { return strokeDasharray; }

void SVGAttributes::setTransform(const std::string& trans) { transform = trans; }
std::string SVGAttributes::getTransform() const { return transform; }

// Print attributes
void SVGAttributes::printAttributes() const {
    std::cout << "Fill: " << fill << "\n"
        << "Stroke: " << stroke << "\n"
        << "Stroke Width: " << strokeWidth << "\n"
        << "Opacity: " << opacity << "\n"
        << "Fill Opacity: " << fillOpacity << "\n"
        << "Stroke Opacity: " << strokeOpacity << "\n"
        << "Stroke Linecap: " << strokeLinecap << "\n"
        << "Stroke Linejoin: " << strokeLinejoin << "\n"
        << "Stroke Dasharray: " << strokeDasharray << "\n"
        << "Transform: " << transform << "\n";
}
