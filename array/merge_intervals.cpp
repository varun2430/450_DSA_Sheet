// Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping 
// intervals, and return an array of the non-overlapping intervals that cover all the 
// intervals in the input.

// Example:
// Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]

#include<bits/stdc++.h>
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
