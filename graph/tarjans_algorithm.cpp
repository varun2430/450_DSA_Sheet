#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, vector<int> adj[], int &currTime, vector<int> &time, vector<int> &lowest,
         vector<bool> &visited, vector<vector<int>> &bridges)
{
    visited[node] = true;
    time[node] = currTime;
    lowest[node] = currTime;
    currTime += 1;

    for (auto adjNode : adj[node])
    {
        if (adjNode == parent)
        {
            continue;
        }

        if (visited[adjNode] == false)
        {
            dfs(adjNode, node, adj, currTime, time, lowest, visited, bridges);
            lowest[node] = min(lowest[node], lowest[adjNode]);

            // if node can't be reached by any path other than parent
            // then node-adjNode forms a bridge
            if (lowest[adjNode] > time[node])
            {
                bridges.push_back({node, adjNode});
            }
        }
        else
        {
            lowest[node] = min(lowest[node], lowest[adjNode]);
        }
    }
}

// used to find bridge or critical connections in a graph
vector<vector<int>> tarjans_algo(int n, vector<vector<int>> &connections)
{
    vector<int> adj[n];
    for (auto itr : connections)
    {
        adj[itr[0]].push_back(itr[1]);
        adj[itr[1]].push_back(itr[0]);
    }

    vector<int> time(n, -1);   // the time at which the dfs visits the node
    vector<int> lowest(n, -1); // lowest time of the adjNode except parent
    vector<bool> visited(n, false);

    int currTime = 1;
    vector<vector<int>> bridges;

    dfs(0, -1, adj, currTime, time, lowest, visited, bridges);

    return bridges;
}
