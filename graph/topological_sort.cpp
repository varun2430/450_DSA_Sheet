#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], vector<bool> &visited, stack<int> &st)
{
    visited[node] = true;

    for (int &adjNode : adj[node])
    {
        if (!visited[adjNode])
        {
            dfs(adjNode, adj, visited, st);
        }
    }

    st.push(node);
}

vector<int> topoSortDfs(int V, vector<int> adj[])
{
    stack<int> st;
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            dfs(i, adj, visited, st);
        }
    }

    vector<int> res;
    while (!st.empty())
    {
        res.push_back(st.top());
        st.pop();
    }

    return res;
}

vector<int> topoSortBfs(int V, vector<int> adj[])
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

    vector<int> res;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        res.push_back(node);

        for (int &adjNode : adj[node])
        {
            inDegree[adjNode]--;

            if (inDegree[adjNode] == 0)
            {
                q.push(adjNode);
            }
        }
    }

    return res;
}
