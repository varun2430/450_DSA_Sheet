#include<iostream>
#include<vector>
using namespace std;

void rotateClockwise(vector<vector<int>>& matrix)
{
    const int n = matrix.size();

    // clockwise rotation = rotation w.r.t. main diagonal + rotation w.r.t. middle column

    // rotate w.r.t. main diagonal
    for(int row=0 ; row < n ; row++)
    {
        for(int col=0 ; col < row ; col++)
        {
            swap(matrix[row][col], matrix[col][row]);
        }
    }

    // rotate w.r.t. middle column
    for(int row=0 ; row < n ; row++)
    {
        for(int col=0 ; col < n/2 ; col++)
        {
            swap(matrix[row][col], matrix[row][n-1 - col]);
        }
    }
}

void printMatrix(vector<vector<int>>& matrix)
{
    const int n = matrix.size();
    for(int row=0 ; row < n ; row++)
    {
        for(int col=0 ; col < n ; col++)
        {
            cout << matrix[row][col] << "  ";
        }
        cout << "\n";
    }
    cout << endl;
}

int main()
{
    vector<vector<int>> matrix = {  { 1, 2, 3, 4 },
                                    { 5, 6, 7, 8 },
                                    { 9, 10, 11, 12 },
                                    { 13, 14, 15, 16 } };

    printMatrix(matrix);
    rotateClockwise(matrix);
    printMatrix(matrix);

    return 0;
}
