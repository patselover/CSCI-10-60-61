#include "square.h"

Square::Square()
{

}

Square::Square(double s): Rectangle(s, s){

}

double Square::get_side(){
    return Rectangle:: get_height();
}
