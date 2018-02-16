#include <iostream>
#include "node.h"
using namespace std;

int main(int argc, char *argv[])
{
    node * a= new node(5, nullptr);
    node * b= new node(7, a);
    node * mean = b->link();
    const node * c = new node (8,a);
    mean = nullptr;
    return 0;
}
