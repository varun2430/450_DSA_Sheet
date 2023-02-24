#include<iostream>
#include<vector>
#include<stack>
using namespace std;

// process of elimination
int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> s;
        for(int i=0 ; i < n ; i++)
        {
            s.push(i);
        }
        
        while(s.size() > 1)
        {
            int p1 = s.top();
            s.pop();
            int p2 = s.top();
            s.pop();
            
            if(M[p1][p2] == 1)
            {
                s.push(p2);
            }
            else
            {
                s.push(p1);
            }
        }
        
        int candidate = s.top();
        for(int i=0 ; i < n ; i++)
        {
            if(i != candidate)
            {
                if( (M[candidate][i] == 1) || (M[i][candidate] == 0) )
                {
                    return -1;
                }
            }
        }
        
        return candidate;
    }
