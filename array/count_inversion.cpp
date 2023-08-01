// Given an array of integers. Find the Inversion Count in the array.
// Inversion Count: For an array, inversion count indicates how far (or close) the array
// is from being sorted. If array is already sorted then the inversion count is 0. If an
// array is sorted in the reverse order then the inversion count is the maximum.
// Formally, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.

// Example:
// Input:  N = 5, arr[] = {2, 4, 1, 3, 5}
// Output: 3

#include <bits/stdc++.h>
using namespace std;

long long int merge(long long arr[], long long tmp[], int left, int mid, int right)
{
    long long int inversion_count = 0;

    int left_itr = left;
    int right_itr = mid;
    int tmp_itr = left;

    while ((left_itr <= mid - 1) && (right_itr <= right))
    {
        if (arr[left_itr] <= arr[right_itr])
        {
            tmp[tmp_itr++] = arr[left_itr++];
        }
        else
        {
            tmp[tmp_itr++] = arr[right_itr++];
            inversion_count += (mid - left_itr);
        }
    }

    while (left_itr <= mid - 1)
    {
        tmp[tmp_itr++] = arr[left_itr++];
    }

    while (right_itr <= right)
    {
        tmp[tmp_itr++] = arr[right_itr++];
    }

    for (int i = left; i <= right; i++)
    {
        arr[i] = tmp[i];
    }

    return inversion_count;
}

long long int getInversionCount(long long arr[], long long tmp[], int left, int right)
{
    long long int inversion_count = 0;

    int mid = 0;
    if (left < right)
    {
        mid = left + (right - left) / 2;

        inversion_count += getInversionCount(arr, tmp, left, mid);
        inversion_count += getInversionCount(arr, tmp, mid + 1, right);

        inversion_count += merge(arr, tmp, left, mid + 1, right);
    }

    return inversion_count;
}

// Time Complexity: O(n * log n)
// Auxiliary Space: O(n)
long long int inversionCount(long long arr[], long long N)
{
    long long tmp[N];

    long long int inversion_count = getInversionCount(arr, tmp, 0, N - 1);

    return inversion_count;
}
