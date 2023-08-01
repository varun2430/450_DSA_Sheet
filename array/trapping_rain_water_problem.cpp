// Given an array arr[] of N non-negative integers representing the height of blocks. If
// width of each block is 1, compute how much water can be trapped between the blocks during
// the rainy season.

// Example:
// Input:  N = 6
//         arr[] = {3,0,0,2,0,4}
// Output: 10

#include <bits/stdc++.h>
using namespace std;

// a simple solution can be to calculate the max hight to the left and right of the i(including height of i)
// and using min(max_left_of(i), max_right_of(i)) - height(i) calculate the amount of water i will hold

long long trappingWater(int arr[], int n)
{
    long long res = 0;

    int left = 0;
    int right = n - 1;
    int left_max = 0;
    int right_max = 0;

    while (left <= right)
    {
        if (arr[left] <= arr[right]) // min(max_at_left(i), max_at_right(i)) lies at left
        {
            if (arr[left] >= left_max)
            {
                left_max = arr[left]; // if height at i is greater than or equal to max_at_left just then
            }                         // on water can be added and update max_at_left
            else
            {
                res += left_max - arr[left]; // add to res only when max_at_left is greater than height at i
            }

            left++;
        }
        else // min(max_left_to(i), max_right_to(i)) lies at right
        {
            if (arr[right] >= right_max)
            {
                right_max = arr[right]; // if height at i is greater than or equal to max_at_right just then
            }                           // on water can be added and update max_at_right
            else
            {
                res += right_max - arr[right]; // add to res only when max_at_right is greater than height at i
            }

            right--;
        }
    }

    return res;
}
