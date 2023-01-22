#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

void printDuplicates(string& s)
{
    const int n = s.length();
    unordered_map<char, int> m;

    for(int i=0 ; i < n ; i++)
    {
        m[s[i]]++;
    }

    for(auto itr : m)
    {
        if(itr.second > 1)
        {
            cout << itr.first << ": " << itr.second << "\n";
        }
    }
    cout << endl;
}

int main()
{
    string s = "test string";
    
    printDuplicates(s);

    return 0;
}
