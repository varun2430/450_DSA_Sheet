#include<iostream>
#include<string>
using namespace std;

bool checkPalindrome(string& s)
{
    const int n = s.length();
    for(int i=0 ; i < n/2 ; i++)
    {
        if(s[i] != s[n-1 -i])
        {
            return false;
        }
    }

    return true;
}

int main()
{
    string s = "ABCDCBA";

    cout << checkPalindrome(s) << endl;

    return 0;
}
