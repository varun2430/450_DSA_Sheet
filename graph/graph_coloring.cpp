#include<bits/stdc++.h>
using namespace std;

// if it is possible to color the graph using two colors
// then it is a bipartite graph
bool check(int src, vector<int> adj[], vector<int> &color)
{
    queue<int> q;
    q.push(src);
    color[src] = 0;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int adjNode : adj[node])
        {
            if (color[adjNode] == -1)
            {
                color[adjNode] = !color[node];
                q.push(adjNode);
            }
            else if (color[node] == color[adjNode])
            {
                return false;
            }
        }
    }

    return true;
}

bool isBipartite(int V, vector<int> adj[])
{
    vector<int> color(V, -1);
    for (int i = 0; i < V; i++)
    {
        if (color[i] == -1)
        {
            if (check(i, adj, color) == false)
            {
                return false;
            }
        }
    }

    return true;
}
