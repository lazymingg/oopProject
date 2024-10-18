#ifndef _FIGURE_H_
#define _FIGURE_H_


class Figure
{
    
    public:
        Figure();
        ~Figure();
        virtual void draw() = 0;
};

#endif