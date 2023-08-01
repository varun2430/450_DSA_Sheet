// Given an array of positive integers nums and a positive integer target, return the
// minimal length of a subarray whose sum is greater than or equal to target. If there is
// no such subarray, return 0 instead.

// Example:
// Input:  target = 7, nums = [2,3,1,2,4,3]
// Output: 2

#include <bits/stdc++.h>
using namespace std;

int minSubArrayLen(int target, vector<int> &nums)
{
    const int n = nums.size();
    int min_len = INT_MAX;

    int sum = 0;
    int start = 0;
    for (int end = 0; end < n; end++)
    {
        sum += nums[end];

        while (sum >= target) // reduce the size of window from left to get min_len
        {
            min_len = min(min_len, end - start + 1);

            sum -= nums[start++];
        }
    }

    return (min_len == INT_MAX) ? 0 : min_len;
}
