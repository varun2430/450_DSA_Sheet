#include<iostream>
#include<algorithm>
using namespace std;

void mergeArrays(int arr1[], int n1, int arr2[], int n2)
{
    int itr1=0, itr2=0, end1=n1-1;
    // place the elements in the right array
    while((itr1 <= end1) && (itr2 < n2))
    {
        if(arr1[itr1] < arr2[itr2])
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
    sort(arr1, arr1+n1);
    sort(arr2, arr2+n2);
}

void printArray(int arr[], int n)
{
    for(int i=0 ; i < n ; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << endl;
}

int main()
{
    int arr1[] = { 1, 5, 9, 10, 15, 20 };
    const int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int arr2[] = { 2, 3, 8, 13 };
    const int n2 = sizeof(arr2) / sizeof(arr2[0]);

    mergeArrays(arr1, n1, arr2, n2);

    printArray(arr1, n1);
    printArray(arr2, n2);

    return 0;
}
