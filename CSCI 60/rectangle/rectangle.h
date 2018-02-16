#ifndef RECTANGLE_H
#define RECTANGLE_H


class Rectangle
{
public:
    Rectangle();
    Rectangle(double hi, double wi);
    void grow(double n);
    double area();
    Rectangle boundingBox(Rectangle r);
    double get_width();
    double get_height();

private:
    double _height, _width;
};

#endif // RECTANGLE_H
