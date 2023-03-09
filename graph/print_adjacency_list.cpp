
#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> printGraph(int V, vector<int> adj[])
{
    vector<vector<int>> adjList(V);

    for (int i = 0; i < V; i++)
    {
        adjList[i].push_back(i);

        for (int &v : adj[i])
        {
            adjList[i].push_back(v);
        }
    }

    return adjList;
}
