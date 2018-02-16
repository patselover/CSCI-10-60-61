#ifndef SQUARE_H
#define SQUARE_H
#include "rectangle.h"

class Square: public Rectangle
{
public:
    Square();
    Square(double s);
    double get_side();

private:
    double _side;

};

#endif // SQUARE_H
