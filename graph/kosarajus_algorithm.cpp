#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<bool> &visited, vector<vector<int>> &adj, stack<int> &st)
{
    visited[node] = true;

    for (auto adjNode : adj[node])
    {
        if (visited[adjNode] == false)
        {
            dfs(adjNode, visited, adj, st);
        }
    }

    st.push(node);
}

// dfs without stack
void dfs(int node, vector<bool> &visited, vector<int> adj[])
{
    visited[node] = true;

    for (auto adjNode : adj[node])
    {
        if (visited[adjNode] == false)
        {
            dfs(adjNode, visited, adj);
        }
    }
}

// used to find the strongly connected components in a graph
int kosaraju(int V, vector<vector<int>> &adj)
{
    vector<bool> visited(V, false);

    // sort all the nodes according to finishing time
    // i.e. the last node traversed will be last and
    // the first node traversed will be first
    stack<int> st;
    for (int i = 0; i < V; i++)
    {
        if (visited[i] == false)
        {
            dfs(i, visited, adj, st);
        }
    }

    // reverse all the edges in adj
    // and store in radj
    vector<int> radj[V];
    for (int node = 0; node < V; node++)
    {
        visited[node] = false; // mark all nodes a unvisited

        for (auto adjNode : adj[node])
        {
            radj[adjNode].push_back(node);
        }
    }

    int count = 0;
    while (!st.empty())
    {
        int node = st.top();
        st.pop();

        if (visited[node] == false)
        {
            count += 1;
            dfs(node, visited, radj);
        }
    }

    return count;
}
