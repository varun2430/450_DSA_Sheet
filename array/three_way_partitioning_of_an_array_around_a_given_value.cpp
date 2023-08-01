// Given an array of size n and a range [a, b]. The task is to partition the array around
// the range such that array is divided into three parts.
//      1) All elements smaller than a come first.
//      2) All elements in range a to b come next.
//      3) All elements greater than b appear in the end.
// The individual elements of three sets can appear in any order. You are required to
// return the modified array.

// Example:
// Input:  n = 5
//         A[] = {1, 2, 3, 3, 4}
//         [a, b] = [1, 2]
// Output: 1

#include <bits/stdc++.h>
using namespace std;

void threeWayPartition(vector<int> &array, int a, int b)
{
    int left = 0;
    int right = array.size() - 1;

    for (int i = 0; i <= right; i++)
    {
        if (array[i] < a)
        {
            swap(array[i], array[left]);
            left++;
        }
        else if (array[i] > b)
        {
            swap(array[i], array[right]);
            right--;
            i--;
        }
    }
}
