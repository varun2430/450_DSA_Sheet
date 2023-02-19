#include<iostream>
#include<vector>
using namespace std;

int minSubArrayLen(int target, vector<int> &nums)
{
    const int n = nums.size();
    int min_len = INT_MAX;

    int sum = 0;
    int start = 0;
    for (int end = 0; end < n; end++)
    {
        sum += nums[end];

        while (sum >= target)       // reduce the size of window from left to get min_len
        {
            min_len = min(min_len, end - start + 1);

            sum -= nums[start++];
        }
    }

    return (min_len == INT_MAX) ? 0 : min_len;
}

int main()
{
    vector<int> v = {2,3,1,2,4,3};

    cout << minSubArrayLen(7, v) << endl;

    return 0;
}
