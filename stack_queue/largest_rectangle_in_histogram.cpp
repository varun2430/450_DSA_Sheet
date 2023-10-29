// Given an array of integers heights representing the histogram's bar height where the
// width of each bar is 1, return the area of the largest rectangle in the histogram.

// Example:
// Input:  heights = [2,1,5,6,2,3]
// Output: 10

#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();

    stack<int> st;

    int left_smaller[n];
    for (int i = 0; i < n; i++)
    {
        while ((!st.empty()) && (heights[st.top()] >= heights[i]))
        {
            st.pop();
        }

        if (st.empty())
        {
            left_smaller[i] = 0;
        }
        else
        {
            left_smaller[i] = st.top() + 1;
        }

        st.push(i);
    }

    // empty the stack
    while (!st.empty())
    {
        st.pop();
    }

    int right_smaller[n];
    for (int i = n - 1; i >= 0; i--)
    {
        while ((!st.empty()) && (heights[st.top()] >= heights[i]))
        {
            st.pop();
        }

        if (st.empty())
        {
            right_smaller[i] = n - 1;
        }
        else
        {
            right_smaller[i] = st.top() - 1;
        }

        st.push(i);
    }

    int max_area = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        max_area = max(max_area, heights[i] * (right_smaller[i] - left_smaller[i] + 1));
    }

    return max_area;
}

int largestRectangleArea_optimized(vector<int> &heights)
{
    int n = heights.size();

    // always has heights in increasing order
    stack<int> st;

    int max_area = INT_MIN;
    for (int i = 0; i <= n; i++)
    {
        // when we find a height that is less than st's top we calculate the area using the current
        // height as right_smaller and st's top after one pop as left_smaller
        while ((!st.empty()) && ((i == n) || (heights[st.top()] >= heights[i])))
        {
            int height = heights[st.top()];
            st.pop();

            int width;
            if (st.empty())
            {
                width = i;
            }
            else
            {
                width = i - st.top() - 1;
            }

            max_area = max(max_area, height * width);
        }

        st.push(i);
    }

    return max_area;
}