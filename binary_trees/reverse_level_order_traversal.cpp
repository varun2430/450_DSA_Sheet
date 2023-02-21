#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

vector<int> reverseLevelOrder(Node *root)
{
    vector<int> res;

    stack<Node*> s;

    queue<Node*> q;
    q.push(root);

    while (!q.empty())
    {
        Node *tmp = q.front();
        q.pop();
        s.push(tmp);

        if (tmp->right != nullptr)
        {
            q.push(tmp->right);     // right is pushed first
        }

        if (tmp->left != nullptr)
        {
            q.push(tmp->left);
        }
    }

    while (!s.empty())
    {
        Node *tmp = s.top();
        s.pop();
        res.push_back(tmp->data);
    }

    return res;
}
