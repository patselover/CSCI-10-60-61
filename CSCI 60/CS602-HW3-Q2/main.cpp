#include <iostream>
#include "Rational.h"
using namespace std;

int main()
{
    Rational r(1,2);

    Rational j(3,4);
    cout<<"Rational r: "<<r<<endl;
    cout<<"Rational j: "<<j<<endl;
    
    cout<<"Rational j+r: "<<j+r<<endl;
    
    cout<<"Rational j numerator: "<<j.get_num()<<endl;

    cout<<"Rational j denominator: "<<j.get_den()<<endl;
    j.set_den(3);
    cout<<"Rational j denominator set to 3"<<endl;
    cout<<j.get_den()<<endl;
    return 0;
}
