#ifndef _POINT_H_
#define _POINT_H_

#include <iostream>
using namespace std;

class Point
{
    private:
        double x;
        double y;
    public:
        Point();
        Point(double x, double y);
        ~Point();
        void setX(double x);
        void setY(double y);
        double getX();
        double getY();
        void print();
};
#endif