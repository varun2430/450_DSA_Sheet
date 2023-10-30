// Given a string S consisting only of opening and closing parenthesis 'ie '('  and ')',
// find out the length of the longest valid(well-formed) parentheses substring.
// NOTE: Length of the smallest valid substring ( ) is 2.

// Example:
// Input:  S = "()(())("
// Output: 6

#include <bits/stdc++.h>
using namespace std;

int findMaxLen(string s)
{
    int s_len = s.length();

    stack<int> st;
    st.push(-1);

    int max_len = 0;
    for (int i = 0; i < s_len; i++)
    {
        if (s[i] == '(')
        {
            st.push(i);
        }
        else
        {
            st.pop();

            if (!st.empty())
            {
                max_len = max(max_len, i - st.top());
            }
            else
            {
                // when stack becomes empty push next potential starting index
                st.push(i);
            }
        }
    }
    return max_len;
}
