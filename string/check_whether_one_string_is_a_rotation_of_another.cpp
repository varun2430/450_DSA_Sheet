#include<iostream>
#include<string>
using namespace std;

bool checkIfRotation(string& s, string& r)
{
    const int n = s.length();
    bool found=true;
    for(int i=0 ; i < n ; i++)
    {
        if(s[i] == r[0])
        {
            found = true;
            for(int j=0 ; j < n ; j++)
            {
                if(s[(i+j)%n] != r[j])
                {
                    found = false;
                    break;
                }
            }

            if(found)
            {
                return found;
            }
        }
    }

    return found;
}

int main()
{
    string s1 = "ABCD";
    string s2 = "CDAB";

    cout << checkIfRotation(s1, s2) << endl;
    
    return 0;
}
