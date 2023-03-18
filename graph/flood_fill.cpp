#include<bits/stdc++.h>
using namespace std;

void bfs(int sr, int sc, vector<vector<int>> &image, vector<vector<int>> &res, int &initialColor, int &newColor)
{
    const int m = image.size();
    const int n = image[0].size();

    int drow[4] = {-1, 0, 1, 0};
    int dcol[4] = {0, 1, 0, -1};

    queue<pair<int, int>> q;

    res[sr][sc] = newColor;
    q.push({sr, sc});

    while (!q.empty())
    {
        int c_row = q.front().first;
        int c_col = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int n_row = c_row + drow[i];
            int n_col = c_col + dcol[i];

            if ((n_row >= 0) && (n_row < m) && (n_col >= 0) && (n_col < n) && (image[n_row][n_col] == initialColor) && (res[n_row][n_col] != newColor))
            {
                res[n_row][n_col] = newColor;
                q.push({n_row, n_col});
            }
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    vector<vector<int>> res = image;

    int initialColor = image[sr][sc];
    int newColor = color;

    bfs(sr, sc, image, res, initialColor, newColor);

    return res;
}
