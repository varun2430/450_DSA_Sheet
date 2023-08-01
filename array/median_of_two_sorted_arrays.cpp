// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median
// of the two sorted arrays.
// The overall run time complexity should be O(log (m+n)).

// Example:
// Input: nums1 = [1,3], nums2 = [2]
// Output: 2.00000

#include <bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    // ensures time complexity is O(log(min(n1, n2)))
    if (nums1.size() > nums2.size())
    {
        return findMedianSortedArrays(nums2, nums1);
    }

    int n1 = nums1.size();
    int n2 = nums2.size();

    // required size of the left array
    int reqLeft = (n1 + n2 + 1) / 2;

    int low = 0;
    int high = n1;

    while (low <= high)
    {
        // partitioning the arrays
        int cut1 = low + (high - low) / 2;
        int cut2 = reqLeft - cut1;

        int l1 = (cut1 <= 0) ? INT_MIN : nums1[cut1 - 1];
        int r1 = (cut1 >= n1) ? INT_MAX : nums1[cut1];

        int l2 = (cut2 <= 0) ? INT_MIN : nums2[cut2 - 1];
        int r2 = (cut2 >= n2) ? INT_MAX : nums2[cut2];

        if ((l1 <= r2) && (l2 <= r1))
        {
            if ((n1 + n2) % 2 == 0)
            {
                return (max(l1, l2) + min(r1, r2)) / 2.0;
            }
            else
            {
                return max(l1, l2);
            }
        }
        else if (l1 > r2)
        {
            high = cut1 - 1;
        }
        else
        {
            low = cut1 + 1;
        }
    }

    return -1.0;
}
