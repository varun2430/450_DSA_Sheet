#include<bits/stdc++.h>
using namespace std;

// if a cycle exists in the graph then the tasks cannot be finished

bool isPossible(int N, vector<pair<int, int>> &prerequisites)
{
    vector<int> adj[N];
    for (auto itr : prerequisites)
    {
        adj[itr.second].push_back(itr.first);
    }

    int inDegree[N] = {0};
    for (int i = 0; i < N; i++)
    {
        for (int &adjNode : adj[i])
        {
            inDegree[adjNode]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < N; i++)
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

    if (topo.size() != N)
    {
        return false;
    }

    return true;
}
