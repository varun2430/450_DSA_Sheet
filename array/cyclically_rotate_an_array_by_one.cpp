// Given an array, rotate the array by one position in clock-wise direction.

// Example:
// Input:  N = 5    A[] = {1, 2, 3, 4, 5}
// Output: 5 1 2 3 4

#include <bits/stdc++.h>
using namespace std;

void cyclicalRotate(int arr[], int n)
{
    int first = 0, last = n - 1;
    while (first < last)
    {
        swap(arr[first], arr[last]);
        first++;
    }
}

void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << endl;
}
