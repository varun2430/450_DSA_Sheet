#include<iostream>
#include<stack>
using namespace std;

// can also be done iteratively using additional stack
void insertAtBottom(stack<int> &s, int x)
{
    if (s.empty())
    {
        s.push(x);
        return;
    }
    else
    {
        int prev = s.top();
        s.pop();

        insertAtBottom(s, x);

        s.push(prev);
    }
}
