// Given an array of N integers, and an integer K, find the number of pairs of elements 
// in the array whose sum is equal to K.

// Example:
// Input:
// N = 4, K = 6
// arr[] = {1, 5, 7, 1}
// Output: 2

#include <bits/stdc++.h>
using namespace std;

// can be modified to get paires
// Time Complexity: O(n)
// Auxiliary Space: O(n)
int getPairsCount(int arr[], int n, int k)
{
    unordered_map<int, int> freq;
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (freq.find(k - arr[i]) != freq.end())
        {
            count += freq[k - arr[i]];
        }

        freq[arr[i]]++;
    }

    return count;
}

int main()
{
    int arr[] = { 1, 5, 7, -1, 5 };
    const int n = sizeof(arr) / sizeof(arr[0]);

    cout << getPairsCount(arr, n, 6) << endl;

    return 0;
}
