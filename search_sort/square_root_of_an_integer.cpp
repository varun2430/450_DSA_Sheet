#include<iostream>
using namespace std;

long long int floorSqrt(long long int x)
{
    long long int low = 1;
    long long int high = x;
    long long int mid = 0;
    long long int sqr = 0;

    long long int res = 0;

    while (low <= high)
    {
        mid = low + (high - low) / 2;

        sqr = mid * mid;

        if (sqr == x)
        {
            return mid;
        }
        else if (sqr <= x)
        {
            low = mid + 1;
            res = mid;
        }
        else
        {
            high = mid - 1;
        }
    }

    return res;
}
