#include<bits/stdc++.h>
using namespace std;

bool dfs(int vertex, vector<int> adj[], vector<bool> &visited, vector<bool> &pathVisited)
{
    visited[vertex] = true;
    pathVisited[vertex] = true;

    for (auto adjVer : adj[vertex])
    {
        if (!visited[adjVer])
        {
            if (dfs(adjVer, adj, visited, pathVisited) == true)
            {
                return true;
            }
        }
        else if (pathVisited[adjVer] == true)
        {
            return true;
        }
    }

    pathVisited[vertex] = false;
    return false;
}

bool isCyclicDfs(int V, vector<int> adj[])
{
    vector<bool> visited(V, false);
    vector<bool> pathVisited(V, false);

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            if (dfs(i, adj, visited, pathVisited) == true)
            {
                return true;
            }
        }
    }

    return false;
}

bool isCyclicBfs(int V, vector<int> adj[])
{
    int inDegree[V] = {0};
    for (int i = 0; i < V; i++)
    {
        for (int &adjNode : adj[i])
        {
            inDegree[adjNode]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        if (inDegree[i] == 0)
        {
            q.push(i);
        }
    }

    vector<int> topo;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        topo.push_back(node);

        for (int &adjNode : adj[node])
        {
            inDegree[adjNode]--;

            if (inDegree[adjNode] == 0)
            {
                q.push(adjNode);
            }
        }
    }

    if (topo.size() == V)
    {
        return false;
    }

    return true;
}
