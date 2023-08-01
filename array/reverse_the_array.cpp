// Given an array (or string), the task is to reverse the array/string.

// Examples :
// Input  : arr[] = {1, 2, 3}
// Output : arr[] = {3, 2, 1}

#include <bits/stdc++.h>
using namespace std;

void reverse_array(int arr[], int start, int end)
{
    int tmp = 0;
    while (start < end)
    {
        tmp = arr[end];
        arr[end] = arr[start];
        arr[start] = tmp;

        start++;
        end--;
    }
}
