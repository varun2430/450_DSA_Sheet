// Given an array A of size N of integers. Your task is to find the minimum and maximum
// elements in the array.

// Example
// Input:  N = 6
//         A[] = {3, 2, 1, 56, 10000, 167}
// Output: min = 1, max =  10000

#include <bits/stdc++.h>
using namespace std;

void getMinMax(int arr[], int n)
{
    if (n == 1)
    {
        cout << "max: " << arr[0] << endl;
        cout << "min: " << arr[0] << endl;
    }

    int max = 0, min = 0;
    if (arr[0] > arr[1])
    {
        max = arr[0];
        min = arr[1];
    }
    else
    {
        max = arr[1];
        min = arr[0];
    }

    for (int i = 2; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }

        if (arr[i] < min)
        {
            min = arr[i];
        }
    }

    cout << "max: " << max << endl;
    cout << "min: " << min << endl;
}
