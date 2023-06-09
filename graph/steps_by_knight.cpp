#include <bits/stdc++.h>
using namespace std;

int minStepToReachTarget(vector<int>& KnightPos, vector<int>& TargetPos, int N)
{
    int kx = KnightPos[0] - 1;
    int ky = KnightPos[1] - 1;

    int tx = TargetPos[0] - 1;
    int ty = TargetPos[1] - 1;

    if ((kx == tx) && (ky == ty))
    {
        return 0;
    }

    vector<vector<int>> visited(N, vector<int>(N, 0));

    queue<pair<int, int>> q;
    q.push({kx, ky});

    int dx[] = {-1, 1, -1, 1, -2, -2, 2, 2};
    int dy[] = {-2, -2, 2, 2, -1, 1, -1, 1};

    bool found = false;
    while ((q.empty() == false) && (found == false))
    {
        pair<int, int> curr = q.front();
        int x = curr.first;
        int y = curr.second;
        q.pop();

        for (int i = 0; i < 8; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if ((nx >= 0) && (nx < N) && (ny >= 0) && (ny < N) && (visited[ny][nx] == 0))
            {
                q.push({nx, ny});
                visited[ny][nx] = visited[y][x] + 1;

                if ((nx == tx) && (ny == ty))
                {
                    found = true;
                    break;
                }
            }
        }
    }

    return visited[ty][tx];
}
