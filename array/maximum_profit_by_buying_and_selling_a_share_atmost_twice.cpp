// You are given an array prices where prices[i] is the price of a given stock on the ith
// day.
// Find the maximum profit you can achieve. You may complete at most two transactions.
// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell
//       the stock before you buy again).

// Example:
// Input: prices = [3,3,5,0,0,3,1,4]
// Output: 6

#include <bits/stdc++.h>
using namespace std;

// can be further improved using tabulation
// also a O(N) and constant time solution exists using four variables
int solve(int curr, int buy, int count, vector<int> &prices, const int &n, vector<vector<vector<int>>> &dp)
{
    if ((curr == n) || (count == 0))
    {
        return 0;
    }

    if (buy == 1)
    {
        dp[curr][buy][count] = max(-prices[curr] + solve(curr + 1, 0, count, prices, n, dp),
                                   0 + solve(curr + 1, buy, count, prices, n, dp));
        return dp[curr][buy][count];
    }
    else
    {
        dp[curr][buy][count] = max(prices[curr] + solve(curr + 1, 1, count - 1, prices, n, dp),
                                   0 + solve(curr + 1, buy, count, prices, n, dp));
        return dp[curr][buy][count];
    }
}

int maxProfit(vector<int> &prices)
{
    const int n = prices.size();

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));

    return solve(0, 1, 2, prices, n, dp);
}
