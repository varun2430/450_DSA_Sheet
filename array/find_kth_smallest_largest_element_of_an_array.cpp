// Given an array arr[] and an integer K where K is smaller than size of array, the task
// is to find the Kth smallest element in the given array. It is given that all array
// elements are distinct.

// Example:
// Input:  N = 6, K = 3
//         arr[] = 7 10 4 3 20 15
// Output: 7

#include <bits/stdc++.h>
using namespace std;

// using sort
// Time Complexity: O(N log N)
// Auxiliary Space: O(1)
int getKthSmallestSort(int arr[], int n, int k)
{
    sort(arr, arr + n);
    return arr[k - 1];
}

// using set
// Time Complexity:  O(N*log N)
// Auxiliary Space: O(N)
int getKthSmallestSet(int arr[], int n, int k)
{
    set<int> s(arr, arr + n);

    set<int>::iterator itr = s.begin();
    advance(itr, k - 1);
    return *itr;
}