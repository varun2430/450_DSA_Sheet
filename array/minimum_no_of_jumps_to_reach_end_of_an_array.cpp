// Given an array of N integers arr[] where each element represents the maximum length of the jump
// that can be made forward from that element. This means if arr[i] = x, then we can jump any
// distance y such that y ≤ x.
// Find the minimum number of jumps to reach the end of the array (starting from the first element).
// If an element is 0, then you cannot move through that element.

// Example:
// Input:  N = 11
//         arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9}
// Output: 3

#include <bits/stdc++.h>
using namespace std;

int getMinJumps(int arr[], int n)
{
    int jumps = 0, low = 0, high = 0;
    while (high < n - 1)
    {
        int farthest = 0;
        for (int i = low; i <= high; i++)
        {
            farthest = max(farthest, i + arr[i]);
        }

        low = high + 1;
        high = farthest;

        jumps++;
    }

    return jumps;
}
