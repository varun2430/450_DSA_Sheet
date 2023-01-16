#include<iostream>
#include<algorithm>
#include<set>
#include<iterator>

// using std::sort
// Time Complexity: O(N log N)
// Auxiliary Space: O(1) 
int getKthSmallestSort(int arr[], int n, int k)
{
    std::sort(arr, arr+n);
    return arr[k-1];
}

// using std::set
// Time Complexity:  O(N*log N)
// Auxiliary Space: O(N)
int getKthSmallestSet(int arr[], int n, int k)
{
    std::set<int> s(arr, arr+n);

    std::set<int>::iterator itr = s.begin();
    std::advance(itr, k-1);
    return *itr;
}

int main()
{
    int arr[] = {12, 3, 5, 7, 19};
    const int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << getKthSmallestSet(arr, n, 2) << std::endl;

    return 0;
}
