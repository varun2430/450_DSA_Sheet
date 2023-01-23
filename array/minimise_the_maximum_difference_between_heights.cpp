#include<iostream>
#include<algorithm>
using namespace std;

int getMinDif(int arr[], int n, int k)
{
    sort(arr, arr+n);

    int diff = arr[n-1] - arr[0];
    int tmp_min = arr[0];
    int tmp_max = arr[n-1];

    for(int i=0 ; i < n ; i++)
    {
        if(arr[i] < k)
        {
            continue;
        }

        tmp_min = min(arr[0] + k, arr[i] - k);
        tmp_max = max(arr[n-1] - k, arr[i-1] + k);

        diff = min(diff, tmp_max-tmp_min);
    }

    return diff;
}

int main()
{
    int arr[] = {3, 9, 12, 16, 20};
    const int n = sizeof(arr) / sizeof(arr[0]);

    cout << getMinDif(arr, n, 3) << endl;

    return 0;
}
