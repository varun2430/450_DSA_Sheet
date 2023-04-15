// Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order.

// Example:
// Input: 
// N = 5
// arr[]= {0 2 1 2 0}
// Output:
// 0 0 1 2 2

#include<bits/stdc++.h>
using namespace std;

void print_array(int arr[], int n);

void noAlgoSort(int arr[], int n)
{
    int low = 0;
    int cur = 0;
    int high = n-1;
 
    while (cur <= high) {

        if(arr[cur] == 0)
        {
            swap(arr[low], arr[cur]);
            low++;
            cur++;
        }
        else if(arr[cur] == 1)
        {
            cur++;
        }
        else if(arr[cur] == 2)
        {
            swap(arr[cur], arr[high]);
            high--;
        }
    }
}

void print_array(int arr[], int n)
{
    for(int i=0 ; i < n ; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << endl;
}

int main()
{
    int arr[] = { 0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1 };
    const int n = sizeof(arr) / sizeof(arr[0]);

    print_array(arr, n);
    noAlgoSort(arr, n);
    print_array(arr, n);

    return 0;
}
