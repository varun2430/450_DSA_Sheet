#include<iostream>
#include<vector>

bool searchMatrix(std::vector<std::vector<int>>& matrix, int k)
{
    const int row=matrix.size(), col=matrix[0].size();
    int crow=0;

    while(crow < row)
    {
        if( (k >= matrix[crow][0]) && (k <= matrix[crow][col-1]) )
        {
            break;
        }
        crow++;
    }

    if( (crow > -1) && (crow < row) && (k >= matrix[crow][0]) && (k <= matrix[crow][col-1]) )
    {
        int low=0, mid=0, high=col-1;
        while(low <= high && low > -1)
        {
            mid = low + (high - low)/2;

            if(matrix[crow][mid] == k)
            {
                return true;
            }
            else if(matrix[crow][mid] > k)
            {
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
    }

    return false;
}

int main()
{
    std::vector<std::vector<int>> matrix = {{1,3,5,7},
                                            {10,11,16,20},
                                            {23,30,34,60}   };

    std::cout << searchMatrix(matrix, 13) << std::endl;

    return 0;
}
