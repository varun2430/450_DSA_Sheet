// A permutation of an array of integers is an arrangement of its members into a sequence 
// or linear order.
// For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3],
//  [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
// The next permutation of an array of integers is the next lexicographically greater 
// permutation of its integer. More formally, if all the permutations of the array are 
// sorted in one container according to their lexicographical order, then the next 
// permutation of that array is the permutation that follows it in the sorted container. 
// If such arrangement is not possible, the array must be rearranged as the lowest 
// possible order (i.e., sorted in ascending order).
// For example, the next permutation of arr = [1,2,3] is [1,3,2].
// Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
// While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
// Given an array of integers nums, find the next permutation of nums.
// The replacement must be in place and use only constant extra memory.

// Example:
// Input: nums = [1,2,3]
// Output: [1,3,2]

#include<bits/stdc++.h>
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
