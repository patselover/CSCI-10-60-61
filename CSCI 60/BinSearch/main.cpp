#include <iostream>

using namespace std;
//int Partition(numType *a, int beg, int end);
//void QuickSort(numType *a, int beg, int end);
int binSearch(int a[], int min, int max, int find);
int main()
{
    int a[]={1,2,3,4};
    int i = binSearch(a,0,3,5);
    cout <<i <<endl;
    return 0;
}

int binSearch(int a[], int min, int max, int find){
    int atIndex = -1;
    int mid = max/2;
    if(min == max)
        return atIndex;
    else if(a[mid] == find)
    {
        atIndex = mid;
        return atIndex;
    }
    else
        if(find < a[mid])
        {
            max = mid -1;
            binSearch(a, min, max, find);
        }
        else
        {
            min = mid +1;
            binSearch (a, min, max, find);
        }
    return atIndex;
}




template <class numType>
int Partition(numType *a, int beg, int end)          //Function to Find Pivot Point
{
    int p = beg, loc;
    numType pivot = a[beg];

    for (loc = beg + 1; loc <= end; loc++)
    {
        if (pivot>a[loc])
        {
            a[p] = a[loc];
            a[loc] = a[p + 1];
            a[p + 1] = pivot;

            p = p + 1;
        }
    }
    return p;
}
template <class numType>
void QuickSort(numType *a, int beg, int end)
{
    if (beg<end)
    {
        int p = Partition(a, beg, end);                       //Calling Procedure to Find Pivot

        QuickSort(a, beg, p - 1);                             //Calls Itself (Recursion)
        QuickSort(a, p + 1, end);			              //Calls Itself (Recursion)
    }
}
