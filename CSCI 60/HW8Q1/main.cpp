#include <iostream>
using namespace std;

int main()
{
        int *pa = new int[5]; //creates a new pointer "pa" with 5 spots of memory (pointer array) @ some spot in memory
        int *pm = pa+2; //creates a new pointer "pm" pointing to  the 3rd spot of the "pa" 'pointer array'
        *(pm-1) = *(pm+1) = 1; //Sets the contents of the second and fourth spot in the "pa" 'pointer array' to 1
        *pa = 3; //sets the contents of the first spot in "pa" to 3
        *pm = *pa+1; //sets the contents of the "pm" pointer to the conents of the first spot in "pa" (3) plus 1 (4)
        pa[4] = 5; //sets the contents of fifth spot of pa to 5

        for (int i = 0; i < 5; ++i) //for loop that goes through the "pa" 'pointer array'
                cout << pa[i] << " "; //prints out the contents of the "pa" 'pointer array'
        cout << endl; //endline after the printed 'pointer array'

        delete [] pa; //deletes the pointer "pa" to free the spot in memory

        return 0;
}
