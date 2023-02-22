#include<iostream>
#include<stack>
using namespace std;

bool isBalanced(string x)
{
    const int x_len = x.length();
    stack<char> s;

    for (int i = 0; i < x_len; i++)
    {
        if (s.empty())
        {
            s.push(x[i]);
        }
        else if ((s.top() == '(' && x[i] == ')') || (s.top() == '{' && x[i] == '}') || (s.top() == '[' && x[i] == ']'))
        {
            s.pop();
        }
        else
        {
            s.push(x[i]);
        }
    }

    if (s.empty())
    {
        return true;
    }

    return false;
}

int main()
{
    return 0;
}
