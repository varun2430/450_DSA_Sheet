#include <iostream>
#include <unordered_map>
using namespace std;

// can be modified to get paires
// Time Complexity: O(n)
// Auxiliary Space: O(n)
int getPairsCount(int arr[], int n, int k)
{
    unordered_map<int, int> freq;
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (freq.find(k - arr[i]) != freq.end())
        {
            count += freq[k - arr[i]];
        }

        freq[arr[i]]++;
    }

    return count;
}

int main()
{
    int arr[] = { 1, 5, 7, -1, 5 };
    const int n = sizeof(arr) / sizeof(arr[0]);

    cout << getPairsCount(arr, n, 6) << endl;

    return 0;
}
