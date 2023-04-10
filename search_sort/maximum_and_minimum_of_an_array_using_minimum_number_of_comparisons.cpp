#include<bits/stdc++.h>
using namespace std;

void findSum(int A[], int N)
{
    int cmin = INT_MAX;
    int cmax = INT_MIN;

    int itr = 0;

    if (N % 2 == 0)
    {
        if (A[0] > A[1])
        {
            cmin = A[1];
            cmax = A[0];
        }
        else
        {
            cmin = A[0];
            cmax = A[1];
        }

        itr = 2;
    }
    else
    {
        cmin = A[0];
        cmax = A[0];

        itr = 1;
    }

    while (itr < N - 1)
    {
        if (A[itr] > A[itr + 1])
        {
            if (A[itr] > cmax)
            {
                cmax = A[itr];
            }
            if (A[itr + 1] < cmin)
            {
                cmin = A[itr + 1];
            }
        }
        else
        {
            if (A[itr] < cmin)
            {
                cmin = A[itr];
            }
            if (A[itr + 1] > cmax)
            {
                cmax = A[itr + 1];
            }
        }

        itr += 2;
    }

    cout << "min: " << cmin << endl;
    cout << "max: " << cmax << endl;
}
