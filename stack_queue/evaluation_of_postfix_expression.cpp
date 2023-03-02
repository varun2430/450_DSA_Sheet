#include<iostream>
#include<stack>
using namespace std;

int evaluatePostfix(string exp)
{
    stack<int> s;

    for (char &c : exp)
    {
        if (isdigit(c))
        {
            s.push(c - '0');
        }
        else
        {
            int num2 = s.top();
            s.pop();
            int num1 = s.top();
            s.pop();

            switch (c)
            {
            case '/':
                s.push(num1 / num2);
                break;
            case '*':
                s.push(num1 * num2);
                break;
            case '+':
                s.push(num1 + num2);
                break;
            case '-':
                s.push(num1 - num2);
                break;
            }
        }
    }

    return s.top();
}

int main()
{
    string exp = "123+*8-";

    cout << evaluatePostfix(exp) << endl;
    
    return 0;
}
