// Given a collection of Intervals, the task is to merge all of the overlapping Intervals.

// Example:
// Input:  intervals = {{1,3},{2,4},{6,8},{9,10}}
// Output: {{1, 4}, {6, 8}, {9, 10}}

#include <bits/stdc++.h>
using namespace std;

bool compare(vector<int> &a, vector<int> &b)
{
    return (a[0] < b[0]);
}

vector<vector<int>> overlappedInterval(vector<vector<int>> &intervals)
{
    int n = intervals.size();

    sort(intervals.begin(), intervals.end(), compare);

    stack<vector<int>> st;
    st.push(intervals[0]);

    for (int i = 1; i < n; i++)
    {
        vector<int> curr = intervals[i];
        vector<int> &top = st.top();

        if (top[1] >= curr[0])
        {
            top[1] = max(top[1], curr[1]);
        }
        else
        {
            st.push(curr);
        }
    }

    vector<vector<int>> merged_intervals;
    while (!st.empty())
    {
        merged_intervals.insert(merged_intervals.begin(), st.top());
        st.pop();
    }

    return merged_intervals;
}
