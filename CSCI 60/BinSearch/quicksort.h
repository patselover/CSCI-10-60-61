#ifndef QUICKSORT_H
#define QUICKSORT_H


class QuickSort
{
public:
    QuickSort();
};

#endif // QUICKSORT_H

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
