#include <iostream>
#include <fstream>
#include "puzzle.h"

using namespace std;


int main()
{

    puzzle p("/Users/PatSelover/Desktop/puzzle.txt", "/Users/PatSelover/Desktop/dict.txt");
    p.solve();



}

