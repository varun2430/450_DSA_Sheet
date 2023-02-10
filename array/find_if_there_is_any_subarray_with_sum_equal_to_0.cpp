#include <iostream>
#include <unordered_map>
using namespace std;

bool subArrayExists(int arr[], int n)
{
    unordered_map<int, int> cumSum;

    int sum = 0;
    for (int i=0; i < n; i++)
    {
        sum += arr[i];

        if ((sum == 0) || (cumSum.find(sum) != cumSum.end()))
        {
            return true;
        }

        cumSum[sum] = i;
    }

    return false;
}

int main()
{
    int arr[] = {1, 4, -2, -2, 5, -4, 3};
    const int n = sizeof(arr) / sizeof(arr[0]);

    cout << subArrayExists(arr, n) << endl;

    return 0;
}
