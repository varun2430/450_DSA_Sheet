// Given an array Arr[] of N integers. Find the contiguous sub-array(containing at least
// one number) which has the maximum sum and return its sum.

// Example:
// Input:  N = 5
//         Arr[] = {1,2,3,-2,5}
// Output: 9

#include <bits/stdc++.h>
using namespace std;

int maxSubArraySum(int arr[], int n)
{
    int max_sum = INT_MIN, cur_sum = 0;
    for (int i = 0; i < n; i++)
    {
        cur_sum += arr[i];

        if (cur_sum > max_sum)
        {
            max_sum = cur_sum;
        }

        if (cur_sum < 0)
        {
            cur_sum = 0;
        }
    }

    return max_sum;
}
