#include "rectangle.h"

Rectangle::Rectangle()
{
    _height=_width=0;
}
Rectangle::Rectangle(double hi, double wi){
    _height=hi;
    _width=wi;
}

void Rectangle:: grow(double n){
    _height+=n;
    _width+=n;
}

double Rectangle:: area(){
    return _height*_width;
}

Rectangle Rectangle:: boundingBox(Rectangle r){

}

double Rectangle:: get_width(){
    return _width;
}

double Rectangle:: get_height(){
    return _height;
}
