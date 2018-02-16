#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <cassert>

template <class T>
class Array{
private:
    T arr[1000];
    static const int capacity = 1000;
    int size;
public:
    //Post:  Initialize to an empty array
    Array<T>();

    //Pre:  s<=1000
    //Post: our array arr is initialized with all the values in a, and size is updated to s.
    Array<T>(T a[], int s);

    //Post:  Returns the size
    int get_size() {return size;}

    //Post:  Returns the capacity
    int get_capacity(){return capacity;}

    //Pre:  n<1000
    //Post:  Returns the nth element of the array.
    T get_at(int n);

    //Pre:  n<1000
    //Post:  the nth element of the array is set to source.
    T set_at(int n, T source);

    //Pre:  source's size is less than 1000
    //Post:  Our array is overwritten with the values in source; its size is updated accordingly.
    //Note:  = can only be overloaded as a member function.
    bool operator =(Array<T> source);

    template <class T2>
    friend std::ostream& operator <<(std::ostream& out, Array<T2> source);
};

//Pre:  T must have a == operator
//Post:  Returns true if a1 and a2 are the same size and have all the same elements in the same order
//and false otherwise.
template <class T>
bool operator==(Array<T> a1, Array<T> a2);

//Pre:  a1 and a2 are the same size.  T must have a + operator
//Post:  Returns an array whose elements are the sums of the corresponding elements from a1 and a2.
//So if the first element of a1 is 4 and the first element of a2 is 9, the first element of the returned
//Array is 13, etc.
template <class T>
Array<T> operator +(Array<T> a1, Array<T> a2);

//Pre:  << must be defined for T
//Post:  Prints out all the elements of source in a nice format.
template <class T>
std::ostream& operator <<(std::ostream& out, Array<T> source);

/*//////////////////////////////////////////IMPLEMENTATION//////////////////////////////////////////*/
template <class T>
Array<T>:: Array(){
    size=0;
}

template <class T>
Array<T>::Array(T a[], int s){
    for(int i(0); i<s; i++)
        arr[i]=a[i];
    size=s;
}

template <class T>
T Array<T>::get_at(int n){
    assert(n<1000);
    return arr[n];
}

template <class T>
T Array<T>::set_at(int n, T source){
    assert(n<1000);
    arr[n]=source;
}

template <class T>
bool Array<T>::operator =(Array<T> source){
    for(int i(0); i<source.size; i++)
        arr[i]=source.arr[i];
    size=source.size;
    return true;
}

template <class T>
bool operator==(Array<T> a1, Array<T> a2){
    if(a1.size != a2.size)
        return false;
    else{
        for(int i(0); i<a1.size; i++){
            if(a1.arr[i] != a2.arr[i])
                return false;
        }
            return true;
    }
}

template <class T>
Array<T> operator +(Array<T> a1, Array<T> a2){
    int rsize;
    int rarr[1000];

    if(a1.get_size()<a2.get_size())
        rsize = a2.get_size();
    else
        rsize = a1.get_size();

    for(int i(0); i<rsize; i++)
        rarr[i]=a1.get_at(i)+a2.get_at(i);
    Array<T> result (rarr,rsize);
    return result;
}

template <class T>
std::ostream& operator <<(std::ostream& out, Array<T> source){
    for(int i(0); i<source.get_size(); i++)
        out<<source.arr[i]<<" ";
    return out;
}

#endif // ARRAY_H




