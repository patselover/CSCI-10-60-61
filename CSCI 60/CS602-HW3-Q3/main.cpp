#include <iostream>
#include "array.h"
using namespace std;

int main()
{
    int ar[9]={2,6,2,8,2,0,3,12,9};
    int arr[7]={3,4,5,6,7,8,9};
    Array<int> a (ar, 9);
    Array<int> a1 (arr, 7);
    cout<<"Array a: "<<a<<endl;

    Array<int> b(ar,7);
    cout<<"Array b: "<<b<<endl;

    cout<<"Capacity of Array b: "<<b.get_capacity()<<endl;
    cout<<"Size of Array b: "<<b.get_size()<<endl;
    cout<<"Element 3 of Array b: "<<b.get_at(3)<<endl;
    b.set_at(3,4);
    cout<<"Element 3 of Array b: "<<b.get_at(3)<<endl;
    cout<<b.operator =(a1)<<endl;
    cout<<"Array b: "<<b<<endl;
    b+a;
    cout<<"Array b+a: "<<b+a;
    return 0;
}
