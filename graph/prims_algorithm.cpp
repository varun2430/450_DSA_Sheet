#include<bits/stdc++.h>
using namespace std;

// traverse all the nodes by picking the shortest path
// this is done by using priority queue
int spanningTree(int V, vector<vector<int>> adj[])
{
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({0, {0, -1}});

    vector<pair<int, int>> mst;

    vector<bool> visited(V, false);

    int mstSum = 0;
    while (!pq.empty())
    {
        int nodeWeight = pq.top().first;
        int node = pq.top().second.first;
        int parent = pq.top().second.second;
        pq.pop();

        if (visited[node])
        {
            continue;
        }

        if (parent != -1)
        {
            mst.push_back({parent, node});
        }

        visited[node] = true;

        mstSum += nodeWeight;

        for (auto itr : adj[node])
        {
            int adjNode = itr[0];
            int edgeWeight = itr[1];

            if (!visited[adjNode])
            {
                pq.push({edgeWeight, {adjNode, node}});
            }
        }
    }

    for (auto itr : mst)
    {
        cout << itr.first << " -> " << itr.second << "\n";
    }
    cout << endl;

    return mstSum;
}
