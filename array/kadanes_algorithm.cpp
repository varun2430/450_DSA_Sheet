#include<iostream>
using namespace std;

int maxSubArraySum(int arr[], int n)
{
    int max_sum=INT_MIN, cur_sum=0;
    for(int i=0 ; i < n ; i++)
    {
        cur_sum += arr[i];

        if(cur_sum > max_sum)
        {
            max_sum = cur_sum;
        }

        if(cur_sum < 0)
        {
            cur_sum = 0;
        }
    }

    return max_sum;
}

int main()
{
    int arr[] = {1,2,3,-2,5};
    const int n = sizeof(arr) / sizeof(arr[0]);

    cout << maxSubArraySum(arr, n) << endl;

    return 0;
}
