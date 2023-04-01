#include<bits/stdc++.h>
using namespace std;

int firstPos(int arr[], int n, int x)
{
    int low = 0;
    int high = n - 1;
    int mid = 0;

    int pos = -1;
    while (low <= high)
    {
        mid = low + (high - low) / 2;

        if (arr[mid] == x)
        {
            pos = mid;
            high = mid - 1;
        }
        else if (arr[mid] < x)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return pos;
}

int lastPos(int arr[], int n, int x)
{
    int low = 0;
    int high = n - 1;
    int mid = 0;

    int pos = -1;
    while (low <= high)
    {
        mid = low + (high - low) / 2;

        if (arr[mid] == x)
        {
            pos = mid;
            low = mid + 1;
        }
        else if (arr[mid] < x)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return pos;
}

vector<int> find(int arr[], int n, int x)
{
    vector<int> res;

    res.push_back(firstPos(arr, n, x));
    res.push_back(lastPos(arr, n, x));

    return res;
}
