#include<bits/stdc++.h>
using namespace std;

class DisjointSet
{
private:
    vector<int> parent;
    vector<int> rank;
    vector<int> size;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 1);
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int findUParent(int node)
    {
        if (node == parent[node])
        {
            return node;
        }

        parent[node] = findUParent(parent[node]);
        return parent[node];
    }

    void unionByRank(int u, int v)
    {
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);

        if (ulp_u == ulp_v)
        {
            return;
        }

        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_u] > rank[ulp_v])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u] += 1;
        }
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);

        if (ulp_u == ulp_v)
        {
            return;
        }

        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

int spanningTree(int V, vector<vector<int>> adj[])
{
    vector<pair<int, pair<int, int>>> edges;
    for (int i = 0; i < V; i++)
    {
        for (auto itr : adj[i])
        {
            int node = i;
            int adjNode = itr[0];
            int edgeWeight = itr[1];

            edges.push_back({edgeWeight, {i, adjNode}});
        }
    }

    sort(edges.begin(), edges.end());

    DisjointSet ds(V);

    int mstSum = 0;
    for (auto itr : edges)
    {
        int node = itr.second.first;
        int adjNode = itr.second.second;
        int edgeWeight = itr.first;

        if (ds.findUParent(node) != ds.findUParent(adjNode))
        {
            mstSum += edgeWeight;
            ds.unionByRank(node, adjNode);
        }
    }

    return mstSum;
}
