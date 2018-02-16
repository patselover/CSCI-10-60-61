#ifndef Rational_H
#define Rational_H
#include <iostream>

class Rational
{
public:
    Rational();
    Rational(int n, int d);

    int Gcd1( const int & N, const int & M );
    int Gcd( const int & M, const int & N );
    void FixSigns(); // Ensures Denom > 0
    void Reduce();  // Ensures lowest form

    int get_num() const;
    int get_den() const;

    void set_num(int ni);
    void set_den(int di);

private:
    int _denom, _numer;


};

Rational operator +(Rational a, Rational b);
Rational operator *(Rational a, Rational b);
bool operator <(Rational a, Rational b);
bool operator >(Rational a, Rational b);
bool operator ==(Rational a, Rational b);
std::ostream& operator <<(std::ostream & out, Rational a);

#endif // Rational_H
