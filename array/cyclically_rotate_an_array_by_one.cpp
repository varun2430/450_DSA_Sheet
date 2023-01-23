#include<iostream>
using namespace std;

void cyclicalRotate(int arr[], int n)
{
    int first=0, last=n-1;
    while(first < last)
    {
        swap(arr[first], arr[last]);
        first++;
    }
}

void printArr(int arr[], int n)
{
    for(int i=0 ; i < n ; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    const int n = sizeof(arr) / sizeof(arr[0]);

    printArr(arr, n);
    cyclicalRotate(arr, n);
    printArr(arr, n);
    return 0;
}
