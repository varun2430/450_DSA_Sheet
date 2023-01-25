#include<iostream>
using namespace std;

int getMinJumps(int arr[], int n)
{
    int jumps=0, low=0, high=0;
    while(high < n-1)
    {
        int farthest = 0;
        for(int i=low ; i <= high ; i++)
        {
            farthest = max(farthest, i + arr[i]);
        }

        low = high+1;
        high = farthest;

        jumps++;
    }

    return jumps;
}

int main()
{
    int arr[] = { 1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9 };
    const int n = sizeof(arr) / sizeof(int);

    cout << getMinJumps(arr, n) << endl;

    return 0;
}
