#ifndef _POINT_H_
#define _POINT_H_

#include <iostream>
using namespace std;
// define my point class

namespace MySize
{
    class Size
    {
    private:
        int width;
        int length;
    public:
        Size();
        Size(int width, int length);
        ~Size();
        void setWidth(int width);
        void setLength(int length);
        int getWidth();
        int getLength();
        void print();
    };
}
#endif