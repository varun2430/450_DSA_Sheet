#include<iostream>
#include<vector>


// Time Complexity: O(m+n) where m is the number of rows and n is the number of columns in the matrix.
// Auxiliary Space:  O(1)
int rowMax1s(std::vector<std::vector<int>>& matrix)
{
    const int row=matrix.size(), col=matrix[0].size();
    int mrow=-1, mcol=col-1;
    bool update=false;

    for(int i=0 ; i < row ; i++)
    {
        update = false;
        while((mcol > -1) && (matrix[i][mcol] == 1))
        {
            mcol--;
            mrow = i;
        }
    }

    if(mrow == -1)
    {
        return -1;
    }

    return mrow;
}

int main()
{
    std::vector<std::vector<int>> matrix = {{0, 0, 0, 1},
                                            {0, 1, 1, 1},
                                            {1, 1, 1, 1},
                                            {0, 0, 0, 0}};

    std::cout << rowMax1s(matrix) << std::endl;

    return 0;
}
