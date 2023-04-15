// Given an unsorted array Arr of N positive and negative numbers. Your task is to create 
// an array of alternate positive and negative numbers without changing the relative order 
// of positive and negative numbers.
// Note: Array should start with a positive number.

// Example:
// Input: 
// N = 9
// Arr[] = {9, 4, -2, -1, 5, 0, -5, -3, 2}
// Output:
// 9 -2 4 -1 5 -5 0 -3 2

#include <bits/stdc++.h>
using namespace std;

void rightrotate(int arr[], int n, int outofplace, int cur)
{
    char tmp = arr[cur];
    for (int i = cur; i > outofplace; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[outofplace] = tmp;
}

void rearrange(int arr[], int n)
{
    int outofplace = -1;

    for (int index = 0; index < n; index++)
    {
        if (outofplace >= 0)
        {
            if (((arr[index] >= 0) && (arr[outofplace] < 0)) || ((arr[index] < 0) && (arr[outofplace] >= 0)))
            {
                // find out of ordr element and replece with next element with correct sign
                // right rotate in order to maintain order
                rightrotate(arr, n, outofplace, index);

                if (index - outofplace >= 2)
                {
                    outofplace = outofplace + 2;
                }
                else
                {
                    outofplace = -1;
                }
            }
        }

        if (outofplace == -1)
        {
            if (((arr[index] >= 0) && (!(index & 0x01))) || ((arr[index] < 0) && (index & 0x01)))
            {
                outofplace = index;
            }
        }
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << endl;
}

int main()
{

    int arr[] = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8};
    int n = sizeof(arr) / sizeof(arr[0]);

    printArray(arr, n);

    rearrange(arr, n);

    printArray(arr, n);

    return 0;
}
