// You are given an array prices where prices[i] is the price of a given stock on the ith day.
// You want to maximize your profit by choosing a single day to buy one stock and choosing a 
// different day in the future to sell that stock.
// Return the maximum profit you can achieve from this transaction. If you cannot achieve any 
// profit, return 0.

// Example:
// Input: prices = [7,1,5,3,6,4]
// Output: 5

#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices)
{
    const int n = prices.size();
    
    int buy=prices[0], max_profit=0;
    for(int i=1 ; i < n ; i++)
    {
        max_profit = max(max_profit, prices[i]-buy);

        buy = min(buy, prices[i]);
    }

    return max_profit;
}

int main()
{
    vector<int> prices = {7,1,5,3,6,4};

    cout << maxProfit(prices) << endl;

    return 0;
}
