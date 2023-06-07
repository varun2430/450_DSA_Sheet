#include<bits/stdc++.h>
using namespace std;

// also can be solved using mathematical formulas and
// xor property in o(N) time and O(1) space
vector<int> findTwoElement(vector<int> arr, int n)
{
    // stores repeating and missing nums
    vector<int> res(2);

    for (int i = 0; i < n; i++)
    {
        if (arr[abs(arr[i]) - 1] > 0)
        {
            arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
        }
        else
        {
            res[0] = abs(arr[i]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            res[1] = (i + 1);
        }
    }

    return res;
}
