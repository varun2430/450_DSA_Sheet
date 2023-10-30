// Given a string of balanced expression, find if it contains a redundant parenthesis or
// not. A set of parenthesis are redundant if the same sub-expression is surrounded by
// unnecessary or multiple brackets. Print Yes if redundant, else No.
// Note: Expression may contain + , - , *, and / operators. Given expression is valid and
// there are no white spaces present.

// Example:
// Input:  exp = ((a+b))
// Output: Yes

#include <bits/stdc++.h>
using namespace std;

int checkRedundancy(string s)
{
    stack<char> st;

    for (char &c : s)
    {
        if (c == ')')
        {
            char top = st.top();
            st.pop();

            // if immediate pop has ( redundant brackets found
            bool redundant = true;

            // pop the stack untill we find (
            while ((!st.empty()) && (top != '('))
            {
                // if there is any operator in between then the current bracket is valid
                if ((top == '+') || (top == '-') || (top == '*') || (top == '/'))
                {
                    redundant = false;
                }

                top = st.top();
                st.pop();
            }

            if (redundant == true)
            {
                return 1;
            }
        }
        else
        {
            // push every thing except ) in the stack
            st.push(c);
        }
    }

    return 0;
}