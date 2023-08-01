// Given an integer N, find its factorial. return a list of integers denoting the digits
// that make up the factorial of N.

// Example:
// Input:  N = 10
// Output: 3628800

#include <bits/stdc++.h>
using namespace std;

void multiply(vector<int> &res, int x)
{
    const int n = res.size();

    int carry = 0;
    for (int i = 0; i < n; i++)
    {
        int product = (res[i] * x) + carry;
        res[i] = product % 10;
        carry = product / 10;
    }

    while (carry)
    {
        res.push_back(carry % 10);
        carry /= 10;
    }
}

vector<int> factorial(int N)
{
    vector<int> res;
    res.push_back(1);

    for (int i = 2; i <= N; i++)
    {
        multiply(res, i);
    }

    reverse(res.begin(), res.end());

    return res;
}
