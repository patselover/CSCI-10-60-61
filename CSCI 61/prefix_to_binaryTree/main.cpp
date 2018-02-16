#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <istream>
#include "bintree.h"
using namespace std;

string prefix_to_infix(const string & prefix);
string apply(binTree & node); string a = "";

binTree * prefix_to_binary(const string & prefix){
    istringstream ss(prefix);
    string token;
    stack<string> input, optr;
    binTree * root;
    int count = 0;
    while (ss >> token)
            input.push(token);

    while (!input.empty())
    {
        token = input.top();
        input.pop();
        if (token == "+" || token == "-" || token == "*" ||
                token == "/" || token == "%"){
            if(count >= 2){
                binTree * left = new binTree (optr.top());
                optr.pop();
                binTree * right= new binTree (optr.top());
                optr.pop();
                root = new binTree(token, left, right);
                count = 0;
            }
            else if(count == 1){
                binTree * left = new binTree (optr.top());
                optr.pop();
                root = new binTree(token, left, root);
                count = 0;
            }
            else{
                binTree * right = new binTree(optr.top());
                optr.pop();
                root = new binTree(token, root, right);
                count = 0;
            }
        }
        else{
            optr.push(token);
            ++count;
        }
    }
    int i = 1;
    return root;
}

string prefix_to_infix(const string & prefix)
{
        istringstream ss(prefix);
        string token, left, right, op;
        stack<string> input, s, num, optr;

        while (ss >> token)
                input.push(token);

        while (!input.empty())
        {
            token = input.top();
            input.pop();
            if (token == "+" || token == "-" || token == "*" || token == "/" || token == "%"){
                if(optr.size() >= 2){
                    left = optr.top();
                    optr.pop();
                    right = optr.top();
                    optr.pop();
                    optr.push(left + token + right);
                }
                else if (optr.size() == 1){
                    left = optr.top();
                    optr.pop();
                    string temp = num.top();
                    num.pop();
                    optr.push(temp + token + left);
                }
            }
            else
                optr.push(token);
        }
        return optr.top();
}

string apply(binTree & node){
    if(node.left_link() != nullptr){
        apply(* node.left_link());
    }
    a += node.data();
    if(node.right_link() != nullptr){
        apply(* node.right_link());
    }
    return a;
}

int main()
{
    binTree * root = prefix_to_binary(string("- 4 / - 1 * 3 2 7"));
    preorder(root);
    return 0;
}

