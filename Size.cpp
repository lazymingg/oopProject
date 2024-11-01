#include "Size.h"

MySize::Size::Size(int width, int length)
{
    this->width = width;
    this->length = length;
}

MySize::Size::~Size()
{
    //Nothing to do here
}

void MySize::Size::setWidth(int width)
{
    this->width = width;
}

void MySize::Size::setLength(int length)
{
    this->width = width;
    this->length = length;
}

int MySize::Size::getWidth()
{
    return this->width = width;
}

int MySize::Size::getLength()
{
   return this->length = length;
}

void MySize::Size::print()
{
    cout << "Size: (" << width << ", " << length << ")" << endl;
}