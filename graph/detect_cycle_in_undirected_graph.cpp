#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool dcycle_bfs(int src, vector<int> adj[], bool visited[])
{
    queue<pair<int, int>> q;
    q.push({src, -1});
    visited[src] = true;

    while (!q.empty())
    {
        int vertex = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (auto adjVer : adj[vertex])
        {
            if (!visited[adjVer])
            {
                q.push({adjVer, vertex});
                visited[adjVer] = true;
            }
            else if (parent != adjVer)
            {
                return true;
            }
        }
    }

    return false;
}

bool dcycle_dfs(int vertex, int parent, vector<int> adj[], bool visited[])
{
    visited[vertex] = 1;

    for (auto adjVer : adj[vertex])
    {
        if (!visited[adjVer])
        {
            if (dcycle_dfs(adjVer, vertex, adj, visited) == true)
            {
                return true;
            }
        }
        else if (parent != adjVer)
        {
            return true;
        }
    }

    return false;
}

bool isCycle(int V, vector<int> adj[])
{
    bool visited[V] = {0};

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            if (dcycle_bfs(i, adj, visited))
            {
                return true;
            }

            // if(dcycle_dfs(i, -1, adj, visited) == true)
            // {
            //     return true;
            // }
        }
    }

    return false;
}