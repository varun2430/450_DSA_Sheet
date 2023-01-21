#include<iostream>
#include<string>
using namespace std;

void reverseStr(string& s)
{
    const int n = s.length();
    for(int i=0 ; i < n/2 ; i++)
    {
        swap(s[i], s[n-1 - i]);
    }
}

int main()
{
    string s = "Hannah";

    cout << s << endl;
    reverseStr(s);
    cout << s << endl;

    return 0;
}