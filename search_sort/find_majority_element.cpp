#include<bits/stdc++.h>
using namespace std;

int majorityElement(int a[], int size)
{
    int curr = -1;
    int count = 0;

    for (int i = 0; i < size; i++)
    {
        if (count == 0)
        {
            curr = a[i];
        }

        if (curr == a[i])
        {
            count += 1;
        }
        else
        {
            count -= 1;
        }
    }

    count = 0;
    for (int i = 0; i < size; i++)
    {
        if (curr == a[i])
        {
            count += 1;
        }
    }

    if (count > size / 2)
    {
        return curr;
    }

    return -1;
}
