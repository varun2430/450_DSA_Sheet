#include<iostream>
#include<cstring>
#include<stack>
using namespace std;

char* reverse(char *S, int len)
{
    const int s_len = strlen(S);
    stack<char> s;
    
    for(int i=0 ; i < s_len ; i++)
    {
        s.push(S[i]);
    }
    
    int itr = 0;
    while(!s.empty())
    {
        S[itr++] = s.top();
        s.pop();
    }
    
    return S;
}
