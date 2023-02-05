#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//        6                                6
//      3   5                        4   5
//    2       4        ->          2   3
//  1                            1
//
//  pivot is 3

void nextPermutation(vector<int>& nums)
{
    const int n = nums.size();

    int pivot = -1;
    for(int i=n-2 ; i > -1 ; i--)
    {
        if(nums[i] < nums[i+1])
        {
            pivot = i;
            break;
        }
    }

    if(pivot == -1)
    {
        reverse(nums.begin(), nums.end());
    }
    else
    {
        int next;
        for(int i=n-1 ; i > pivot ; i--)
        {
            if(nums[i] > nums[pivot])
            {
                next = i;
                break;
            }
        }

        swap(nums[pivot], nums[next]);
        reverse(nums.begin()+pivot+1, nums.end());
    }
}

void printVector(vector<int> v)
{
    const int n = v.size();

    for(int& num : v)
    {
        cout << num << "  ";
    }
    cout << endl;
}

int main()
{
    vector<int> arr = { 1, 2, 3, 6, 5, 4 };

    printVector(arr);
    nextPermutation(arr);
    printVector(arr);

    return 0;
}
