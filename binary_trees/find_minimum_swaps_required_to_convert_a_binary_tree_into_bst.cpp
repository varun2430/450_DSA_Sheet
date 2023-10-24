// Given the array representation of Complete Binary Tree i.e, if index i is the parent,
// index 2*i + 1 is the left child and index 2*i + 2 is the right child. The task is to find
// the minimum number of swap required to convert it into Binary Search Tree.

// Example:
// Input:  arr[] = { 5, 6, 7, 8, 9, 10, 11 }
// Output: 3

#include <bits/stdc++.h>
using namespace std;

// first perform inorder treversal on binary tree
// and store result in vector then use the following
// function to find the minimum number of swaps
// required to sort the vector
int minSwaps(vector<int> &nums)
{
    int n = nums.size();

    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        v.push_back({nums[i], i});
    }

    sort(v.begin(), v.end());

    int swaps = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i].second != i)
        {
            swap(v[i], v[v[i].second]);
            swaps += 1;
            i -= 1;
        }
    }

    return swaps;
}
