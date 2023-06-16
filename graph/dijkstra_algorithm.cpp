#include<bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    vector<int> dist(V, 1e9);
    dist[S] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, S});

    while (!pq.empty())
    {
        int node = pq.top().second;
        int nodeDist = pq.top().first;
        pq.pop();

        for (auto itr : adj[node])
        {
            int adjNode = itr[0];
            int edgeWeight = itr[1];

            if ((nodeDist + edgeWeight) < dist[adjNode])
            {
                dist[adjNode] = nodeDist + edgeWeight;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }

    return dist;
}
