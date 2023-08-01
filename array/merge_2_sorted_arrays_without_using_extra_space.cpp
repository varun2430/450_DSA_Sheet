// Given two sorted arrays arr1[] and arr2[] of sizes n and m in non-decreasing order.
// Merge them in sorted order without using any extra space. Modify arr1 so that it
// contains the first N elements and modify arr2 so that it contains the last M elements.

// Example:
// Input:  n = 4, arr1[] = [1 3 5 7]
//         m = 5, arr2[] = [0 2 6 8 9]
// Output: arr1[] = [0 1 2 3]
//         arr2[] = [5 6 7 8 9]

#include <bits/stdc++.h>
using namespace std;

void mergeArrays(int arr1[], int n1, int arr2[], int n2)
{
    int itr1 = 0, itr2 = 0, end1 = n1 - 1;
    // place the elements in the right array
    while ((itr1 <= end1) && (itr2 < n2))
    {
        if (arr1[itr1] < arr2[itr2])
        {
            itr1++;
        }
        else
        {
            swap(arr1[end1], arr2[itr2]);
            end1--;
            itr2++;
        }
    }

    // place elements in correct position
    sort(arr1, arr1 + n1);
    sort(arr2, arr2 + n2);
}
