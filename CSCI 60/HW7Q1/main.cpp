#include <iostream>

using namespace std;
void swap(int *a, int *b){
    int *x = a;
    int *y = b;
    a=y;
    b=x;
}
void swap(int * a, int * b){
  /* int * temp= new int;
   * temp=*a;
   *a=* b;
   *b=* temp;*/


    int * x=a;
    int * y=b;
    a=y;
    b=x;


}

int main(){
    int a, b, * x, * y;
    a = 10;
    b = 5;
    x = &a;
    y = &b;

    cout<<"a is: "<<a<<", b is: "<<b<<endl;
    cout<<"*x is: "<<*x<<", *y is: "<<*y<<endl;
    swap(x, y);
    cout<<"a is: "<<a<<", b is: "<<b<<endl;
    cout<<"*x is: "<<*x<<", *y is: "<<*y<<endl;
    return 0;
}


