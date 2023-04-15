// Given an array Arr[] of N integers. Find the contiguous sub-array(containing 
// at least one number) which has the maximum sum and return its sum.

// Example:
// Input:
// N = 5
// Arr[] = {1,2,3,-2,5}
// Output:
// 9

#include<bits/stdc++.h>
using namespace std;

int largestSubarray(int arr[], int n)
{
    int cur_max = 0;      // max sum of subarray at current index
    int prev_max = INT_MIN;     // max sum of subarray at found so far

    for(int i=0 ; i < n ; i++)
    {
        cur_max = cur_max + arr[i];

        if(cur_max > prev_max)
        {
            prev_max = cur_max;
        }

        if(cur_max < 0)
        {
            cur_max = 0;
        }
    }

    return prev_max;
}

int main()
{
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    const int n = sizeof(arr) / sizeof(arr[0]);

    cout << largestSubarray(arr, n) << endl;

    return 0;
}
