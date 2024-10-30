#ifndef _FIGURE_H_
#define _FIGURE_H_

#include <iostream>
#include <windows.h>
#include <objidl.h>
#include <gdiplus.h>
using namespace Gdiplus;
#pragma comment (lib,"Gdiplus.lib")

class Figure
{

public:
    virtual void draw() = 0;
};

#endif