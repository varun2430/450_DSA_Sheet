#include<iostream>
#include<vector>
using namespace std;

void dfs(int row, int col, vector<vector<char>> &grid, vector<vector<bool>> &visited)
{
    const int r = grid.size();
    const int c = grid[0].size();

    visited[row][col] = true;

    for (int drow = -1; drow <= 1; drow++)
    {
        for (int dcol = -1; dcol <= 1; dcol++)
        {
            int nrow = row + drow;
            int ncol = col + dcol;

            if ((nrow >= 0) && (nrow < r) && (ncol >= 0) && (ncol < c) && (visited[nrow][ncol] == false) && (grid[nrow][ncol] == '1'))
            {
                dfs(nrow, ncol, grid, visited);
            }
        }
    }
}

int numIslands(vector<vector<char>> &grid)
{
    const int r = grid.size();
    const int c = grid[0].size();

    vector<vector<bool>> visited(r, vector<bool>(c, false));

    int count = 0;
    for (int row = 0; row < r; row++)
    {
        for (int col = 0; col < c; col++)
        {
            if ((visited[row][col] == false) && (grid[row][col] == '1'))
            {
                dfs(row, col, grid, visited);
                count += 1;
            }
        }
    }

    return count;
}
