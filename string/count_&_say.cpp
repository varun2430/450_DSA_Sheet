#include<bits/stdc++.h>
using namespace std;

string countAndSay(int n)
{
    string s = "1";
    
    while (--n)
    {
        string cur = "";

        int s_len = s.size();
        for (int i = 0; i < s_len; i++)
        {
            int count = 1;
            while ((i + 1 < s_len) && (s[i] == s[i + 1]))
            {
                count++;
                i++;
            }

            cur += to_string(count) + s[i];
        }

        s = cur;
    }

    return s;
}
