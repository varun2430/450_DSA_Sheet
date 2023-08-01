// Given an unsorted array arr[] of size N having both negative and positive integers.
// The task is place all negative element at the end of array without changing the
// order of positive element and negative element.

// Example:
// Input:  N = 8
//         arr[] = {1, -1, 3, 2, -7, -5, 11, 6 }

#include <bits/stdc++.h>
using namespace std;

// can be implemented in constant space using modified insersion sort

// Time Complexity : O(n)
// Auxiliary space : O(n)
void moveNegative(int arr[], int n)
{
    vector<int> v;

    int itr = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            v.push_back(arr[i]);
        }

        if (arr[i] >= 0)
        {
            arr[itr] = arr[i];
            itr++;
        }
    }

    int k = 0;
    while (itr < n)
    {
        arr[itr] = v[k];
        itr++;
        k++;
    }
}
