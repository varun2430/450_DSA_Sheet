// Given two n-ary trees. Check if they are mirror images of each other or not. You are also
// given e denoting the number of edges in both trees, and two arrays, A[] and B[]. Each
// array has 2*e space separated values u,v denoting an edge from u to v for the both trees.

// Example:
// Input:  n = 3    e = 2    A[] = {1, 2, 1, 3}    B[] = {1, 3, 1, 2}
// Output: 1

#include <bits/stdc++.h>
using namespace std;

int checkMirrorTree(int n, int e, int A[], int B[])
{
    unordered_map<int, stack<int>> m;

    for (int i = 0; i < 2 * e; i += 2)
    {
        m[A[i]].push(A[i + 1]);
    }

    for (int i = 0; i < 2 * e; i += 2)
    {
        if (m[B[i]].top() != B[i + 1])
        {
            return 0;
        }

        m[B[i]].pop();
    }

    return 1;
}
