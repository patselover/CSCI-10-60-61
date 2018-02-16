#include <iostream>
#include <string>
#include <sstream>
#include <stack>

using namespace std;

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
                    optr.push("(" + left + " " + token + " " + right + ")");
                }
                else if (optr.size() == 1){
                    left = optr.top();
                    optr.pop();
                    string temp = num.top();
                    num.pop();
                    optr.push("(" + temp + " " + token + " " + left + ")");
                }
            }
            else
                optr.push(token);
        }
        return optr.top();
}

string infix_to_prefix(const string & prefix)
{
    istringstream ss(prefix);
    string token, left, right, op;
    stack<string> input, num, out, optr;

    while (ss >> token)
        input.push(token);
    while (!input.empty()){
        token = input.top();
        input.pop();
        if(token == ")"){
            while(input.top() != "("){
                left = input.top();
                input.pop();
                op = input.top();
                input.pop();
                if(!out.empty()){
                    right = out.top();
                    out.pop();
                }
                else{
                    right = input.top();
                    input.pop();
                }
                num.push(op + " " + right + " " + left);
            }
            input.pop();
        }
        else if(token == "/" || token == "*" || token == "+" || token == "-"){
            optr.push(token);
        }
        else
            num.push(token);
    }
    while(optr.size() > 1){
        op = optr.top();
        optr.pop();
        if((op == "/" || op == "*") ){
            left = num.top();
            num.pop();
            right = num.top();
            num.pop();
            out.push(op + " " + left + " " + right );
        }
        else if((op == "+" || op == "-") && optr.top() != "/" && optr.top() != "*") {
            left = num.top();
            num.pop();
            right = num.top();
            num.pop();
            out.push(optr.top() + " " + left + " " + right );
            optr.pop();
        }
        else{
            left = num.top();
            num.pop();
            out.push(op + " " + left);
        }
    }
    if (num.size() > 1){
        left = num.top();
        num.pop();
        right = num.top();
        num.pop();
        out.push(optr.top() + " " + left + " " + right );
        optr.pop();
    }
    else {
        left = num.top();
        num.pop();
        out.push(optr.top() + " " + left);
        optr.pop();
    }
    while(out.size() != 1){
        string left = out.top();
        out.pop();
        string right = out.top();
        out.pop();
        out.push(left + " " + right);
    }
    return out.top();
}
int main()
{
    cout << prefix_to_infix(string("+ / + 1 5 - + 5 7 9 * * 3 3 / + 8 6 * 1 2")) << endl;
        return 0;
}
