#include<bits/stdc++.h>
using namespace std;

bool findPair(int arr[], int size, int n)
{
    sort(arr, arr + size);

    int i = 0;
    int j = 1;

    while (i < size && j < size)
    {
        if (i != j && (arr[j] - arr[i] == n || arr[i] - arr[j] == n))
        {
            return true;
        }
        else if (arr[j] - arr[i] < n)
            j++;
        else
            i++;
    }

    return false;
}
