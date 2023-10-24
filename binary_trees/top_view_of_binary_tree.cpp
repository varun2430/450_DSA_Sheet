// Given below is a binary tree. The task is to print the top view of binary tree. Top view
// of a binary tree is the set of nodes visible when the tree is viewed from the top.
// Note: Return nodes from leftmost node to rightmost node. Also if 2 nodes are outside the
// shadow of the tree and are at same position then consider the extreme ones only(i.e.
// leftmost and rightmost).

// Example:
// Input:     10
//         /      \
//       20        30
//      /   \    /    \
//     40   60  90    100
// Output: 40 20 10 30 100

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

vector<int> topView(Node *root)
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

        if (m.find(cur_line) == m.end())
        {
            m[cur_line] = cur_node->data;
        }

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
