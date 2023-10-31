// You are given two arrays A and B of unique elements of size N. Check if array B is a
// stack permutation of the array A or not.
// Stack permutation means that array B can be created from array A using a stack and stack
// operations.

// Example:
// Input:  N = 3, A = {1,2,3}, B = {2,1,3}
// Output: 1

#include <bits/stdc++.h>
using namespace std;

int isStackPermutation(int N, vector<int> &A, vector<int> &B)
{
    int n = A.size();
    int m = B.size();

    stack<int> st;

    int idx = 0;
    for (int i = 0; i < n; i++)
    {
        st.push(A[i]);

        while ((!st.empty()) && (idx < m) && (st.top() == B[idx]))
        {
            st.pop();
            idx += 1;
        }
    }

    if (idx == m)
    {
        return 1;
    }

    return 0;
}
