#include<iostream>
#include<stack>
using namespace std;

int prec(char c)
{
    if(c == '^')
    {
        return 3;
    }
    else if( (c == '/') || (c == '*') )
    {
        return 2;
    }
    else if( (c == '+') || (c == '-') )
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

string infixToPostfix(string exp)
{
    string res;
    stack<char> opt;

    for(char& c : exp)
    {
        if(isalnum(c))
        {
            res += c;
        }
        else if(c == '(')
        {
            opt.push(c);
        }
        else if(c == ')')
        {
            while(opt.top() != '(')
            {
                res += opt.top();
                opt.pop();
            }
            opt.pop();
        }
        else
        {
            // if operator at top has >= prec then add to res
            while( (!opt.empty()) && (prec(c) <= prec(opt.top())) )
            {
                res += opt.top();
                opt.pop();
            }
            opt.push(c);
        }
    }

    while(!opt.empty())
    {
        res += opt.top();
        opt.pop();
    }

    return res;
}

int main()
{
    string exp = "a+b*(c^d-e)^(f+g*h)-i";

    cout << infixToPostfix(exp) << endl;

    return 0;
}
