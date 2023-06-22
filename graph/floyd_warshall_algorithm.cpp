#include<bits/stdc++.h>
using namespace std;

void shortest_distance(vector<vector<int>> &matrix)
{
    int n = matrix.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == -1)
            {
                matrix[i][j] = 1e9;
            }

            if (i == j)
            {
                matrix[i][j] = 0;
            }
        }
    }

    // go from src to des via every node
    // k is intermediate node
    // i is src node
    // j is des node
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }

    // if cost of node to node is -ve
    // then -ve cycle is present
    for (int i = 0; i < n; i++)
    {
        if (matrix[i][i] < 0)
        {
            cout << "negative cycle found" << endl;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 1e9)
            {
                matrix[i][j] = -1;
            }
        }
    }
}
