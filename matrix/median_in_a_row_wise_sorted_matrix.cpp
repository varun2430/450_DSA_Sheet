#include<iostream>
#include<vector>
#include<algorithm>

// Simple approach would be to convert the matrix into array, sort the array and print the middle element.

// Time Complexity: O(32 * r * log(c)). The upper bound function will take log(c) time and is performed for each row. And since the numbers will be max of 32 bit, so binary search of numbers from min to max will be performed in at most 32 ( log2(2^32) = 32 ) operations. 
// Auxiliary Space: O(1) 
int getMedian(std::vector<std::vector<int>> matrix)
{
    const int row=matrix.size(), col=matrix[0].size();
    int mn=INT_MAX, mx=INT_MIN;

    for(int i=0 ; i < row ; i++)
    {
        mn = std::min(mn, matrix[i][0]);
        mx = std::max(mx, matrix[i][col-1]);
    }

    int mid=0, ub=0;
    while(mn < mx)
    {
        mid = mn + (mx-mn)/2;
        
        ub = 0;
        for(int i=0 ; i < row ; i++)
        {
            ub += (int)( std::upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin() );
        }

        if(ub < (row*col+1)/2)
        {
            mn = mid+1;
        }
        else
        {
            mx = mid;
        }
    }

    return mn;
}

int main()
{
    std::vector<std::vector<int>> matrix = {{1,3,5}, 
                                            {2,6,9},
                                            {3,6,9} };

    std::cout << getMedian(matrix) << std::endl;

    return 0;
}