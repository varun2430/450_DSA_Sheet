#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> bfsOfGraph(int V, vector<int> adj[])
{
    vector<int> res;

    vector<bool> visited(V, false);
    queue<int> q;

    q.push(0);
    visited[0] = true;

    while (!q.empty())
    {
        int vertex = q.front();
        q.pop();

        res.push_back(vertex);

        for (int &ver : adj[vertex])
        {
            if (!visited[ver])
            {
                q.push(ver);
                visited[ver] = true;
            }
        }
    }

    return res;
}
