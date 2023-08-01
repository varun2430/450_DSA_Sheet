// Given two arrays a[] and b[] of size n and m respectively. The task is to find the
// union and intersection between the two arrays.

// Input:  5 3
//         1 2 3 4 5
//         1 2 3
// Output: 1 2 3 4 5
//         1 2 3

#include <bits/stdc++.h>
using namespace std;

void getUnion(int arr1[], int arr2[], int n1, int n2)
{
    int max_num = max(arr1[n1 - 1], arr2[n2 - 1]);
    int m[max_num];
    memset(m, 0, sizeof(m));

    cout << arr1[0] << "  ";
    m[arr1[0]]++;

    for (int i = 1; i < n1; i++)
    {
        if (arr1[i - 1] != arr1[i])
        {
            cout << arr1[i] << "  ";
            m[arr1[i]]++;
        }
    }

    for (int i = 0; i < n2; i++)
    {
        if (m[arr2[i]] == 0)
        {
            cout << arr2[i] << "  ";
            m[arr2[i]]++;
        }
    }
}

void getIntersection(int arr1[], int arr2[], int n1, int n2)
{
    int itr1 = 0, itr2 = 0;
    while (itr1 < n1 && itr2 < n2)
    {
        while ((itr1 > 0) && (arr1[itr1 - 1] == arr1[itr1]))
        {
            itr1++;
        }

        if (arr1[itr1] > arr2[itr2])
        {
            itr2++;
        }
        else if (arr1[itr1] < arr2[itr2])
        {
            itr1++;
        }
        else
        {
            cout << arr1[itr1] << "  ";
            itr1++;
            itr2++;
        }
    }
}
