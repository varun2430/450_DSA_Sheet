// Given a binary tree, print the bottom view from left to right.
// A node is included in bottom view if it can be seen when we look at the tree from bottom.

// Example:
// Input:       10
//            /    \
//           20    30
//          /  \
//         40   60
// Output: 40 20 60 30

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

vector<int> bottomView(Node *root)
{
    vector<int> res;
    if (root == nullptr)
    {
        return res;
    }

    queue<pair<Node *, int>> q;
    q.push({root, 0});

    map<int, int> m;
    while (!q.empty())
    {
        auto itr = q.front();
        q.pop();

        Node *cur_node = itr.first;
        int cur_line = itr.second;

        m[cur_line] = cur_node->data;

        if (cur_node->left != nullptr)
        {
            q.push({cur_node->left, cur_line - 1});
        }

        if (cur_node->right != nullptr)
        {
            q.push({cur_node->right, cur_line + 1});
        }
    }

    for (auto itr : m)
    {
        res.push_back(itr.second);
    }

    return res;
}
