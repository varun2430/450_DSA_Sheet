// Given a Queue Q containing N elements. The task is to reverse the Queue. Your task is to
// complete the function rev(), that reverses the N elements of the queue.

// Example:
// Input:  4 3 1 10 2 6
// Output: 6 2 10 1 3 4

#include <bits/stdc++.h>
using namespace std;

void reverse(queue<int> &q)
{
    if (q.empty())
    {
        return;
    }

    int x = q.front();
    q.pop();

    reverse(q);

    q.push(x);
}

queue<int> rev(queue<int> q)
{
    reverse(q);

    return q;
}
