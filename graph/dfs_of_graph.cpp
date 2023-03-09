#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> dfs_iterative(int V, vector<int> adj[])
{
    vector<int> res;

    vector<bool> visited(V, false);
    stack<int> s;

    s.push(0);
    while (!s.empty())
    {
        int vertex = s.top();
        s.pop();

        if (!visited[vertex])
        {
            res.push_back(vertex);
            visited[vertex] = true;
        }

        for (auto itr = adj[vertex].begin(); itr != adj[vertex].end(); itr++)
        {
            if (!visited[*itr])
            {
                s.push(*itr);
            }
        }
    }

    return res;
}

void dfs_recursive(int ver ,int& V, vector<int> adj[], vector<bool>& visited, vector<int>& res)
{
    res.push_back(ver);
    visited[ver] = true;
    
    for(auto itr=adj[ver].begin() ; itr != adj[ver].end() ; itr++)
    {
        if(!visited[*itr])
        {
            dfs_recursive(*itr, V, adj, visited, res);
        }
    }
}
