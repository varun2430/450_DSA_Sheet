// Given an array Arr[] that contains N integers (may be positive, negative or zero). 
// Find the product of the maximum product subarray.

// Example:
// Input:
// N = 5
// Arr[] = {6, -3, -10, 0, 2}
// Output: 180

#include<bits/stdc++.h>
using namespace std;

long long maxProduct(vector<int>& arr)
{
    const int n = arr.size();

    long long max_ending_here = arr[0];
    long long min_ending_here = arr[0];
    long long max_so_far = arr[0];

    for (int i = 1; i < n; i++)
    {
        long long cur_max = max((long long)arr[i], max(max_ending_here * arr[i], min_ending_here * arr[i]));

        min_ending_here = min((long long)arr[i], min(max_ending_here * arr[i], min_ending_here * arr[i]));

        max_ending_here = cur_max;

        max_so_far = max(max_so_far, max_ending_here);
    }

    return max_so_far;
}

int main()
{
    vector<int> arr = { 1, -2, -3, 0, 7, -8, -2 };

    cout << maxProduct(arr) << endl;

    return 0;
}
