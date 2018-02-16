#include <iostream>

int rowSize = 10;
int colSize = 10;
void hoop(char twoCharArr[10][10]);
void hoop2(char** arr);

using namespace std;

int main()
{
    cout << "Hello Two Dimensional Arrays!" << endl;

    unsigned int ascii = 0x30;

    char twoIntArr[10][10]; //static allocation

    for(int row = 0; row < 10; row++)
        for(int col = 0; col < 10; col++)
        {
            twoIntArr[row][col] = ascii;
            ascii++;
        }

    hoop(twoIntArr);//an array is passed by reference.  This passes the base addr of the array.

    //now a dynamically allocated 2D array
    char** arr2;
    arr2 = new char*[rowSize];//allocate rowsize many pointers to chars as the rows. note char* in new.
    for(int i = 0; i < rowSize; i++)
        arr2[i] = new char[colSize];  //allocate the collumns at each row.

    cout << endl << endl;

    ascii = 0x30;

    for(int row = 0; row < rowSize; row++)
        for(int col = 0; col < colSize; col++)
        {
            arr2[row][col] = ascii;
            ascii++;
        }

    hoop2(arr2);

    return 0;
}

void
hoop(char twoCharArr[10][10])
{
    for(int row = 0; row < 10; row++)
    {
        for(int col = 0; col < 10; col++)
            cout << twoCharArr[row][col] << " ";
        cout << endl;
    }
}

void
hoop2(char** arr)
{
    for(int row = 0; row < 10; row++)
        {
            for(int col = 0; col < 10; col++)
                cout << arr[row][col] << " ";
            cout << endl;
        }
}
