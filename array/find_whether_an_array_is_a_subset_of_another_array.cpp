// Given two arrays: a1[0..n-1] of size n and a2[0..m-1] of size m. Task is to check
// whether a2[] is a subset of a1[] or not. Both the arrays can be sorted or unsorted.

// Example:
// Input:  a1[] = {11, 1, 13, 21, 3, 7}
//         a2[] = {11, 3, 7, 1}
// Output: Yes

#include <bits/stdc++.h>
using namespace std;

// can be done in O(nLog(n) + mLog(m)) and constant space using sorting
bool isSubset(int a1[], int a2[], int n, int m)
{
    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++)
    {
        freq[a1[i]]++;
    }

    for (int i = 0; i < m; i++)
    {
        if (freq[a2[i]] > 0)
        {
            freq[a2[i]]--;
        }
        else
        {
            return false;
        }
    }

    return true;
}
