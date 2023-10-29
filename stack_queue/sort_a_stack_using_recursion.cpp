// Given a stack, the task is to sort it such that the top of the stack has the greatest
// element.

#include <bits/stdc++.h>
using namespace std;

void sort_stack(stack<int> &s)
{
    if (s.empty())
    {
        return;
    }

    int x = s.top();
    s.pop();

    sort_stack(s);

    stack<int> tmp;
    while ((!s.empty()) && (s.top() > x))
    {
        tmp.push(s.top());
        s.pop();
    }

    s.push(x);

    while (!tmp.empty())
    {
        s.push(tmp.top());
        tmp.pop();
    }
}
