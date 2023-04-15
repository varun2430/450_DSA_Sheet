// Given an array (or string), the task is to reverse the array/string.

// Examples :  
// Input  : arr[] = {1, 2, 3}
// Output : arr[] = {3, 2, 1}

#include<bits/stdc++.h>
using namespace std;

void reverse_array(int arr[], int start, int end)
{
    int tmp=0;
    while(start < end)
    {
        tmp = arr[end];
        arr[end] = arr[start];
        arr[start] = tmp;

        start++;
        end--;
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
    int arr[] = {1, 2, 3, 4, 5, 6};
    const int n = sizeof(arr) / sizeof(arr[0]);

    print_array(arr, n);
    reverse_array(arr, 0, n-1);
    print_array(arr, n);

    return 0;
}
