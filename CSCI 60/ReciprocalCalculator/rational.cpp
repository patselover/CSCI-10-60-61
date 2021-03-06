#include "Rational.h"
#include <cassert>
Rational::Rational()
{
    _numer = 0;
    _denom = 1;
}

Rational::Rational(int n, int d){
    assert(d!=0);
    _numer=n;
    _denom=d;
    Reduce();
}

Rational Rational::Reciprocal(){
    Rational out(get_den(),get_num());
    return out;
}

int Rational::get_num() const{
    return _numer;
}

int Rational::get_den() const{
    return _denom;
}

void Rational::set_num(int ni){
    _numer=ni;
}

void Rational::set_den(int di){
    _denom=di;
}

void Rational::FixSigns( )//always a positive demonminator.
{
    if( _denom < 0 )
    {
        _denom = -_denom;
        _numer = -_numer;
    }
}

int Rational :: Gcd1( const int & d, const int & n )
{
    if( d % n == 0 )
        return n;
    else
        return Gcd1( n, d % n );
}

int Rational:: Gcd( const int & n, const int & d )
{
    if( n > 0 )
        return Gcd1( d, n );
    else
        return Gcd1( d, -n );
}

void Rational::Reduce()
{
    int D = 1;

    if( _denom != 0 && _numer != 0 )
        D = Gcd( _numer, _denom );

    if( D > 1 )
    {
        _numer /= D;
        _denom /= D;
    }
}

Rational operator +(Rational a, Rational b){
    Rational result((a.get_num()*b.get_den())+(a.get_den()*b.get_num()),(a.get_den()*b.get_den()));
    result.Reduce();
    result.FixSigns();
    return result;
}

Rational operator *(Rational a, Rational b){
    Rational result((a.get_num()*b.get_num()), (a.get_den()*b.get_den()));
    result.Reduce();
    result.FixSigns();
    return result;
}

bool operator <(Rational a, Rational b){
    if(a.get_den()!=b.get_den() && a.get_num()!=b.get_num()){
        if(a.get_den()<b.get_den())
               if(a.get_den()<b.get_den())
                   return true;
    }
   return false;
}

bool operator >(Rational a, Rational b){
    if(a.get_den()!=b.get_den() && a.get_num()!=b.get_num()){
        if(a.get_den()>b.get_den())
               if(a.get_den()>b.get_den())
                   return true;
    }
   return false;
}

bool operator ==(Rational a, Rational b){
    if(a.get_den() == b.get_den() && a.get_num()==b.get_num())
        return true;
    else
        return false;
}

std::ostream& operator <<(std::ostream & out, Rational a){
    out<<a.get_num()<<"/"<<a.get_den();
    return out;
}
