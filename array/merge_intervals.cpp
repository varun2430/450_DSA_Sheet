#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals)
{
    const int n = intervals.size();
    if(n == 1)
    {
        return intervals;
    }

    sort(intervals.begin(), intervals.end());

    vector<vector<int>> res;
    res.push_back(intervals[0]);
    for(int i=1 ; i < n ; i++)
    {
        if(res.back()[1] >= intervals[i][0])
        {
            res.back()[1] = max(res.back()[1], intervals[i][1]);
        }
        else
        {
            res.push_back(intervals[i]);
        }
    }

    return res;
}

int main()
{
    vector<vector<int>> intervals = {{1,3}, {2,6}, {8,10}, {15,18}};
    vector<vector<int>> res = merge(intervals);

    return 0;
}
