#include<iostream>
#include<vector>
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
