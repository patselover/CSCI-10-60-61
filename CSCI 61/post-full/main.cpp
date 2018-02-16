// Example program
#include <iostream>
#include <string>
#include <stack>
#include <sstream>

using namespace std;
string postfix_to_full(const string & postfix);
int main()
{
    string a= "3 4 + 5 *";
    cout<<postfix_to_full(a);
}

string postfix_to_full(const string & postfix){
    stringstream ss(postfix);
    string ans,left,right;
    stack<string> c;
    while(ss>>ans){
        if(ans=="+" || ans=="-" || ans=="*" || ans=="/"){
            right = c.top();
            c.pop();
            left = c.top();
            c.pop();
            c.push("("+left+" "+ans+" "+right+")");
        }
        else
            c.push(ans);
    }
    return c.top();
}
