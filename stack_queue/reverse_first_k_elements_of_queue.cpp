// Given an integer K and a queue of integers, we need to reverse the order of the first K
// elements of the queue, leaving the other elements in the same relative order.

// Example:
// Input:  5 3
//         1 2 3 4 5
// Output: 3 2 1 4 5

#include <bits/stdc++.h>
using namespace std;

queue<int> modifyQueue(queue<int> q, int k)
{
    int n = q.size();
    stack<int> st;

    for (int i = 0; i < k; i++)
    {
        st.push(q.front());
        q.pop();
    }

    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }

    for (int i = 0; i < n - k; i++)
    {
        q.push(q.front());
        q.pop();
    }

    return q;
}
