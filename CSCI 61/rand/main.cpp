// Example program
#include <iostream>
#include <string>
#include <stack>
using namespace std;
void part(int data[], size_t n, size_t& pivot_index);
void quicksort(int data[], size_t n);
bool valid(const string&);
int main()
{
    int data[] ={40,20,10,80,60,50,7,30,100,90,70};
    size_t pivot;
    size_t n = 11;
    quicksort(data,n);
    for(int i =0; i<n; ++i)
        cout<<data[i]<<endl;
    string it ("(())");
    cout<<valid(it);
}

bool valid(const string& s){
    int num = 0;
    for(size_t i = 0; i<s.size(); ++i){
        switch(s[i]){
            case '(': ++num;break;
            case ')': --num; break;
        }
        if(num<0)
            return 0;
    }
    return num == 0;
}

void part(int data[], size_t n, size_t& pivot_index){
    int pivot = data[0];
    size_t tooB = 1;
    size_t tooS = n-1;
    while(tooB < tooS){
        while(data[tooB] < pivot){
            ++tooB;
        }
        while(data[tooS] > pivot){
            --tooS;
        }
        swap(data[tooS],data[tooB]);
    }
    swap(data[0],data[tooS]);
    pivot_index = tooS;
}

void quicksort(int data [], size_t n){
    size_t pivot_index;
    size_t n1;
    size_t n2;
    if(n>1){
        part(data,n,pivot_index);
        n1 = pivot_index;
        n2 = n - n1 - 1;
        quicksort(data, n1);
        quicksort((data + pivot_index + 1), n2);
    }
}
