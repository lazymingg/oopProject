#ifndef _FIGURE_H_
#define _FIGURE_H_

#include "Figure.h"
#include "extendLib/rapid_xml/rapidxml.hpp"
#include "SVGAttributes.h"
#include <windows.h>
#include <gdiplus.h>
using namespace Gdiplus;
#pragma comment (lib,"Gdiplus.lib")

using namespace std;
using namespace rapidxml;


class Figure
{

public:
    virtual void draw() = 0;
};

#endif