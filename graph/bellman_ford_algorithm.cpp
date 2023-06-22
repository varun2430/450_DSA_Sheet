#include<bits/stdc++.h>
using namespace std;

vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S)
{
    vector<int> dist(V, 1e8);
    dist[S] = 0;

    // perform v-1 edge relaxation
    for (int i = 0; i < V - 1; i++)
    {
        for (auto itr : edges)
        {
            int u = itr[0];
            int v = itr[1];
            int edgeWeight = itr[2];

            if ((u != 1e8) && (dist[u] + edgeWeight < dist[v]))
            {
                dist[v] = dist[u] + edgeWeight;
            }
        }
    }

    // perform the vth edge relaxation
    // if shorter distance is found then
    // -ve cycle is present
    for (auto itr : edges)
    {
        int u = itr[0];
        int v = itr[1];
        int edgeWeight = itr[2];

        if ((u != 1e8) && (dist[u] + edgeWeight < dist[v]))
        {
            return {-1};
        }
    }

    return dist;
}
