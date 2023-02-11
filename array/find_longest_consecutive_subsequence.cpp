#include<iostream>
#include<unordered_set>
using namespace std;

int findLongestConseqSubseq(int arr[], int N)
{
    int res = 0;

    unordered_set<int> s;
    for (int i = 0; i < N; i++)
    {
        s.insert(arr[i]);
    }

    for (int i = 0; i < N; i++)
    {
        int count = 0;
        
        // if arr[i] is the first number of the sequence then
        // arr[i]-1 should not exist in arr
        if (s.find(arr[i] - 1) == s.end())
        {
            int num_to_find = arr[i];

            while (s.find(num_to_find) != s.end())
            {
                count++;
                num_to_find++;
            }
        }

        res = max(res, count);
    }

    return res;
}

int main()
{
    int arr[] = { 1, 9, 3, 10, 4, 20, 2 };
    const int n = sizeof arr / sizeof arr[0];

    cout << findLongestConseqSubseq(arr, n) << endl;

    return 0;
}
