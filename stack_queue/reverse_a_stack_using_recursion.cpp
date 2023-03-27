#include<bits/stdc++.h>
using namespace std;

void insert_at_bottom(int x, stack<int> &St)
{
    if (St.size() == 0)
    {
        St.push(x);
    }
    else
    {
        int tmp = St.top();
        St.pop();

        insert_at_bottom(x, St);

        St.push(tmp);
    }
}

void Reverse(stack<int> &St)
{
    if (St.size() > 0)
    {
        int x = St.top();
        St.pop();

        Reverse(St);

        insert_at_bottom(x, St);
    }

    return;
}
