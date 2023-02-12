#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

vector<int> majorityElement(vector<int> &nums)
{
    const int n = nums.size();

    int maj_1 = INT_MIN, maj_2 = INT_MIN;
    int count_1 = 0, count_2 = 0;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] == maj_1)
        {
            count_1++;
        }
        else if (nums[i] == maj_2)
        {
            count_2++;
        }
        else if (count_1 == 0)
        {
            maj_1 = nums[i];
            count_1 = 1;
        }
        else if (count_2 == 0)
        {
            maj_2 = nums[i];
            count_2 = 1;
        }
        else
        {
            count_1--;
            count_2--;
        }
    }

    vector<int> res;
    count_1 = 0;
    count_2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == maj_1)
        {
            count_1++;
        }

        if (nums[i] == maj_2)
        {
            count_2++;
        }
    }

    if (count_1 > floor(n / 3))
    {
        res.push_back(maj_1);
    }

    if (count_2 > floor(n / 3))
    {
        res.push_back(maj_2);
    }

    return res;
}


int main()
{
    return 0;
}
