#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long findMinDiff(vector<long long> a, long long n, long long m)
{
    sort(a.begin(), a.end());

    long long min_diff = INT_MAX;
    for (int i = 0; i < (n - m + 1); i++)
    {
        min_diff = min(min_diff, a[i + m - 1] - a[i]);
    }

    return min_diff;
}

int main()
{
    vector<long long> choco_pac = {3, 4, 1, 9, 56, 7, 9, 12};
    const int n = choco_pac.size();

    cout << findMinDiff(choco_pac, n , 5) << endl;

    return 0;
}
