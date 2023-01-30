#include<iostream>
using namespace std;

// simple approach would be to use hashmap to slove in linear time & space

// using Floyd's Tortoise and Hare
// Time Complexity:  O(N)
// Auxiliary Space: O(1)
int findDuplicate(int arr[], int n)
{
    int slow = arr[0];
    int fast = arr[0];

    do
    {
        slow = arr[slow];
        fast = arr[arr[fast]];
    }
    while (slow != fast);

    fast = arr[0];

    while(slow != fast)
    {
        slow = arr[slow];
        fast = arr[fast];
    }
    
    return slow;
}

int main()
{
    int arr[] = {3,1,3,4,2};
    const int n = sizeof(arr) / sizeof(arr[0]);

    cout << findDuplicate(arr, n) << endl;

    return 0;
}
