#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>

template<class T>
class Array
{
public:
    Array<T>();
    Array<T>(T a[], int s);
    int get_size(){return _size;}
    int get_capacity(){return CAPACITY;}

private:
    T _array[1000];
    int _size;
    int CAPACITY = 1000;
};

template<class T>
Array<T>::Array(){
    _size=int();
}

template<class T>
Array<T>::Array(T a[], int s){
    _size=s;
    for(int i(0); i<s; i++)
        _array[i]=a[i];
}

template <class T>
bool operator == (Array<T> a, Array<T> b);

template <class T>
std::ostream & operator <<(std::ostream & os, Array<T> source);


#endif // ARRAY_H
