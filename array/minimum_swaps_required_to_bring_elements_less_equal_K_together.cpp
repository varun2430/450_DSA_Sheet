// Given an array arr of n positive integers and a number k. One can apply a swap operation
// on the array any number of times, i.e choose any two index i and j (i < j) and
// swap arr[i] , arr[j] . Find the minimum number of swaps required to bring all the numbers
// less than or equal to k together, i.e. make them a contiguous subarray.

// Example:
// Input:  arr[ ] = {2, 7, 9, 5, 8, 7, 4}   K = 6
// Output:  2

#include<bits/stdc++.h>
using namespace std;

int minSwap(int arr[], int n, int k)
{
    // find the no. of elements <= k
    // which is the window size
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= k)
        {
            count += 1;
        }
    }

    int toSwap = 0;
    for (int i = 0; i < count; i++)
    {
        if (arr[i] > k)
        {
            toSwap += 1;
        }
    }

    // use two pointers to determine the no of elements to be swaped
    // and track the min no. to be swaped
    int left = 0;
    int right = count;

    int minSwap = toSwap;
    while (right < n)
    {
        if (arr[left] > k)
        {
            toSwap -= 1;
        }

        if (arr[right] > k)
        {
            toSwap += 1;
        }

        minSwap = min(minSwap, toSwap);

        left += 1;
        right += 1;
    }

    return minSwap;
}
