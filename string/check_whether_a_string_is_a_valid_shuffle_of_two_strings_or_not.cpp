#include<bits/stdc++.h>
using namespace std;

bool checkShuffle(string a, string b, string s)
{
    const int a_len = a.length();
    const int b_len = b.length();
    const int s_len = s.length();

    if(s_len != a_len + b_len)
    {
        return false;
    }

    a = a + b;
    sort(a.begin(), a.end());
    sort(s.begin(), s.end());

    if(a != s)
    {
        return false;
    }

    return true;
}

int main()
{
    string a = "XY";
    string b = "12";
    string s = "1XY2";

    cout << checkShuffle(a, b, s) << endl;

    return 0;
}
