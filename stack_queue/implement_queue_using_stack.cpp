// Implement a Queue using 2 stacks s1 and s2.
// A Query Q is of 2 Types
// (i)  1 x (a query of this type means  pushing 'x' into the queue)
// (ii) 2   (a query of this type means to pop element from queue and print the poped
//      element)

// Note :- If there is no element return -1 as answer while popping.

// Example:
// Input:  5
//         1 2 1 3 2 1 4 2
// Output: 2 3

#include <bits/stdc++.h>
using namespace std;

class StackQueue
{
private:
    stack<int> s1;
    stack<int> s2;

public:
    void push(int);
    int pop();
};

void StackQueue ::push(int x)
{
    s1.push(x);
}

int StackQueue ::pop()
{
    if ((s1.empty()) && (s2.empty()))
    {
        return -1;
    }

    if ((s2.empty()))
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
    }

    int x = s2.top();
    s2.pop();
    return x;
}
