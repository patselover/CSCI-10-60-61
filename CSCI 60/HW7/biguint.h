#ifndef BIGUINT_H
#define BIGUINT_H

#include <cstdlib>
#include <iostream>
#include <string>

// WANT: integers with CAPACITY digits, only non-negative
//
// support:
//    2 constructors: int, string
//    member functions:  [] returns individual digits given position
//                        +=
//                        -=
//                        compare: return +1, 0, -1, depending on
//                        whether this biguint >, ==, < than given biguint
//                        +, - (binary), - (unary), <, <=, ==, !=, >=, >
//                        <<, >>


class biguint
{
public:
    // CONSTANTS & TYPES

    static const std::size_t CAPACITY = 10;

    // CONSTRUCTORS

    // pre: none
    // post: creates a biguint with given integer value (default = 0)
    biguint(int = 0);

    // pre: s contains only decimal digits
    // post: creates a biguint whose value corresponds to given string of digits
    biguint(const std::string &);

    // CONSTANT MEMBER FUNCTIONS

    // pre: pos < CAPACITY
    // post: returns the digit at position pos
    //          0 is the least significant (units) position

    unsigned short operator [](std::size_t pos) const;

    // pre: none
    // post: returns 1 if this biguint > b
    //               0 if this biguint == b
    //              -1 if this biguint < b
    int compare(const biguint & b) const;

    // pre: none
    // post: returns true if this biguint is negative
    bool is_negative() const;

    // pre: none
    // post: returns a string of digits of this biguint
    std::string toStdString() const;

    // pre: none
    // post: single digit multiplication
    biguint multSingle(const int num);

    // pre: none
    // post: shifts all digits over one
    void shift();


    // MODIFICATION MEMBER FUNCTIONS


    // pre: none
    // post: b is added to this biguint; ignore last carry bit if any
    void operator += (const biguint & b);
    void operator -= (const biguint & b);
    void operator *= (const biguint & b);

private:

    unsigned short _data[CAPACITY];

    // INVARIANTS:
    //    _data[i] holds the i^th digit of this biguint or 0 if not used
    //    _data[0] holds the least significant (units) digit
};

// nonmember functions

biguint operator + (const biguint &, const biguint &);
biguint operator - (const biguint &, const biguint &);
biguint operator * (const biguint &, const biguint &);

bool operator < (const biguint &, const biguint &);
bool operator <= (const biguint &, const biguint &);
bool operator != (const biguint &, const biguint &);
bool operator == (const biguint &, const biguint &);
bool operator >= (const biguint &, const biguint &);
bool operator > (const biguint &, const biguint &);

std::ostream & operator << (std::ostream &, const biguint &);
std::istream & operator >> (std::istream &, biguint &);


#endif // BIGUINT_H
