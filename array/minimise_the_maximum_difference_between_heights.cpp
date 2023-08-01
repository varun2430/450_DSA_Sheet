// Given an array arr[] denoting heights of N towers and a positive integer K.
// For each tower, you must perform exactly one of the following operations exactly once.
// Increase the height of the tower by K
// Decrease the height of the tower by K
// Find out the minimum possible difference between the height of the shortest and tallest
// towers after you have modified each tower.

// Example:
// Input:  K = 2, N = 4
//         Arr[] = {1, 5, 8, 10}
// Output: 5

#include <bits/stdc++.h>
using namespace std;

int getMinDif(int arr[], int n, int k)
{
    sort(arr, arr + n);

    int diff = arr[n - 1] - arr[0];
    int tmp_min = arr[0];
    int tmp_max = arr[n - 1];

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < k)
        {
            continue;
        }

        tmp_min = min(arr[0] + k, arr[i] - k);
        tmp_max = max(arr[n - 1] - k, arr[i - 1] + k);

        diff = min(diff, tmp_max - tmp_min);
    }

    return diff;
}

int main()
{
    int arr[] = {3, 9, 12, 16, 20};
    const int n = sizeof(arr) / sizeof(arr[0]);

    cout << getMinDif(arr, n, 3) << endl;

    return 0;
}
