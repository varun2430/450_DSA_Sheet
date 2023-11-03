// You are given a queue Q of N integers of even length, rearrange the elements by
// interleaving the first half of the queue with the second half of the queue.

// Example:
// Input:  N = 4, Q = {2,4,3,1}
// Output: {2,3,4,1}

#include <bits/stdc++.h>
using namespace std;

vector<int> rearrangeQueue(queue<int> &q)
{
    int n = q.size();

    queue<int> tmp;
    for (int i = 0; i < n / 2; i++)
    {
        tmp.push(q.front());
        q.pop();
    }

    while (!tmp.empty())
    {
        q.push(tmp.front());
        tmp.pop();

        q.push(q.front());
        q.pop();
    }

    vector<int> res;
    while (!q.empty())
    {
        res.push_back(q.front());
        q.pop();
    }

    return res;
}
