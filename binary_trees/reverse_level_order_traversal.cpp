// Given a binary tree of size N, find its reverse level order traversal. ie- the traversal
// must begin from the last level.

// Example:
// Input : 1
//       /   \
//      3     2
// Output: 3 2 1

#include <bits/stdc++.h>
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

    stack<Node *> s;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *tmp = q.front();
        q.pop();
        s.push(tmp);

        if (tmp->right != nullptr)
        {
            // right is pushed first
            q.push(tmp->right);
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
