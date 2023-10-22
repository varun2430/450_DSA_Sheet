// Given a binary tree, find its level order traversal.
// Level order traversal of a tree is breadth-first traversal for the tree.

// Example:
// Input:     1
//          /   \ 
//         3     2
// Output: 1 3 2

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

vector<int> levelOrder(Node *root)
{
    vector<int> res;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *tmp = q.front();
        res.push_back(tmp->data);
        q.pop();

        if (tmp->left != nullptr)
        {
            q.push(tmp->left);
        }

        if (tmp->right != nullptr)
        {
            q.push(tmp->right);
        }
    }

    return res;
}
