// Given an array of positive and negative numbers. Find if there is a subarray
// (of size at-least one) with 0 sum.

// Example:
// Input:  5
//         4 2 -3 1 6
// Output: Yes

#include <bits/stdc++.h>
using namespace std;

bool subArrayExists(int arr[], int n)
{
    unordered_map<int, int> cumSum;

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];

        if ((sum == 0) || (cumSum.find(sum) != cumSum.end()))
        {
            return true;
        }

        cumSum[sum] = i;
    }

    return false;
}
