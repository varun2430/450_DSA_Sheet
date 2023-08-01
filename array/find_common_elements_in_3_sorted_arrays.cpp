// Given three arrays sorted in increasing order. Find the elements that are common in all
// three arrays.

// Example:
// Input:  n1 = 6; A = {1, 5, 10, 20, 40, 80}
//         n2 = 5; B = {6, 7, 20, 80, 100}
//         n3 = 8; C = {3, 4, 15, 20, 30, 70, 80, 120}
// Output: 20 80

#include <bits/stdc++.h>
using namespace std;

// O(n1(log(n2*n3)) and constant space can be implemented using binary search
vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3)
{
    int a = 0, b = 0, c = 0; //  current indices of arrays
    int preva = INT_MIN, prevb = INT_MIN, prevc = INT_MIN;

    vector<int> res;
    while ((a < n1) && (b < n2) && (c < n3))
    {
        if ((A[a] == B[b]) && (B[b] == C[c]))
        {
            res.push_back(A[a]);

            preva = A[a++];
            prevb = B[b++];
            prevc = C[c++];
        }
        else if (A[a] < B[b])
        {
            preva = A[a++];
        }
        else if (B[b] < C[c])
        {
            prevb = B[b++];
        }
        else
        {
            prevc = C[c++];
        }

        while ((A[a] == preva) && (a < n1))
        {
            a++;
        }

        while ((B[b] == prevb) && (b < n2))
        {
            b++;
        }

        while ((C[c] == prevc) && (c < n3))
        {
            c++;
        }
    }

    return res;
}
