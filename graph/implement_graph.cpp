#include<iostream>
#include<vector>
using namespace std;

class graph_al
{
public:
    int V = -1;
    vector<vector<int>> adjList;

    graph_al(int v)
    {
        V = v;
        vector<vector<int>> adjlst(v);
        adjList = adjlst;
    }

    void addEdgeU(int u, int v)
    {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void addEdgeD(int u, int v)
    {
        adjList[u].push_back(v);
    }

    void printGraph()
    {
        for(int i=0 ; i < V ; i++)
        {
            cout << i << " -> ";
            for(int& ver : adjList[i])
            {
                cout << ver << " ";
            }
            cout << "\n";
        }
    }
};

class graph_am
{
public:
    int V = -1;
    vector<vector<int>> adjMatrix;

    graph_am(int v)
    {
        V = v;
        vector<vector<int>> adjmatrix(v, vector<int>(v, 0));
        adjMatrix = adjmatrix;
    }

    void addEdgeU(int u, int v)
    {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }

    void addEdgeD(int u, int v)
    {
        adjMatrix[u][v] = 1;
    }

    void printGraph()
    {
        for(int u=0 ; u < V ; u++)
        {
            cout << u << " -> ";
            for(int v=0 ; v < V ; v++)
            {
                if(adjMatrix[u][v] > 0)
                {
                    cout << v << " ";
                }
            }
            cout << "\n";
        }
    }
};

int main()
{
    graph_am g(5);
    g.addEdgeD(0,1);
    g.addEdgeU(0,2);
    g.addEdgeD(0,3);
    g.addEdgeU(0,4);
    g.printGraph();

    return 0;
}
