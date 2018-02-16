#include "biguint.h"

#include <cassert>
#include <sstream>

biguint::biguint(int n){
    for(std::size_t i = 0; i<CAPACITY; i++){
        if(n==0)
            _data[i] = 0;
        else{
            _data[i] = n%10;
            n=n/10;
        }
    }
}

biguint::biguint (const std::string & s){
     for (int i = 0; i < CAPACITY; ++i)
         _data[i] = 0;

     if (s.size() == 0)
         return;

     char c = s[0];
     int j(0);
     for (int i = s.size()-1; j < CAPACITY && i >= 0; --i)
     {
         assert(isdigit(s[i]));
         _data[j] = s[i] - '0';
         ++j;
     }
}

unsigned short biguint::operator [](std::size_t pos) const{
     assert(pos < CAPACITY);
     return _data[pos];
}

int biguint::compare(const biguint & b) const{
     for(std::size_t i =CAPACITY-1; i>=0; --i){
         if(_data[i]>b._data[i])
             return 1;
         else if (_data[i]<b._data[i])
             return -1;

     }
     return 0;
}

void biguint::operator += (const biguint & b){
     int carry = 0;
     int next = 0;
     for(std::size_t i=0; i<CAPACITY; ++i){
         next = carry+_data[i]+b._data[i];
         _data[i]=next%10;
        carry=next/10;
     }
}

void biguint::operator -= (const biguint & b){
    int borrow = 0;
    int next = 0;
    for(std::size_t i=0; i<CAPACITY; ++i){
        if(_data[i]<b._data[i]){
            borrow = 10;
            _data[i+1]=_data[i+1]-1;
        }
        next= (_data[i]+borrow)-b._data[i];
        _data[i]=next;
        borrow = 0;
    }
}

void biguint::operator *= (const biguint & b){
    biguint res;
    for(std::size_t i = 0; i<CAPACITY; ++i){
        if(i==0){
            biguint temp = multSingle(b[i]);
            res+=temp;
        }
        else{
            biguint temp = multSingle(b[i]);
            temp.shift();
            res+=temp;
        }
    }
    for(std::size_t j = 0; j<CAPACITY; ++j){
        _data[j]=res[j];
    }

}

biguint biguint::multSingle(const int num){
    int carry = 0;
    biguint res;
    for(std::size_t i=0; i<CAPACITY; ++i){
        int next = _data[i]*num+carry;
        res._data[i]=next%10;
        carry=next/10;
    }
    return res;
}

void biguint::shift(){
    assert(_data[CAPACITY-1]==0);
    biguint right;
    right._data[0]=0;
    for(std::size_t i=0; i<CAPACITY-1; ++i){
        right._data[i+1]=_data[i];
    }
    for(std::size_t j = 0; j<CAPACITY; ++j){
        _data[j]=right[j];
    }
}

std::string biguint::toStdString() const
{
     std::stringstream ss;
     ss << *this;
     return ss.str();
}//We haven't talked about stringstreams; just ignore this, I was being lazy.

std::ostream & operator << (std::ostream & os, const biguint & b){
     for (int i = biguint::CAPACITY - 1; i >= 0; --i)
         if(b[i]>0){
            for(int j = i; j>=0; --j){
                os << b[j];
            }
            return os;
         }
}

std::istream & operator >> (std::istream & is, biguint & b){
     std::string s;
     is >> s;
     b = biguint(s);
     return is;
}

biguint operator + (const biguint & a, const biguint & b){
    biguint res;
    res+=a;
    res+=b;
    return res;
}

biguint operator - (const biguint & a, const biguint & b){
    biguint res;
    res+=a;
    res-=b;
    return res;
}

biguint operator * (const biguint & a, const biguint & b){
    biguint res;
    res +=a;
    res *=b;
    return res;
}

bool operator <(const biguint& a, const biguint& b){
     return (a.compare(b)==-1);
}

bool operator <= (const biguint & b1, const biguint & b2){
     return (b1.compare(b2) <= 0);
}

bool operator == (const biguint & b1, const biguint & b2){
     return (b1.compare(b2) == 0);
}

bool operator != (const biguint & b1, const biguint & b2){
     return (b1.compare(b2) != 0);
}

//You do > and >=
bool operator >(const biguint & b1, const biguint & b2){
    return(b1.compare(b2)==1);
}

bool operator >=(const biguint & b1, const biguint & b2){
    return(b1.compare(b2) >= 0);
}

