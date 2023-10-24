// Given a binary tree with a value associated with each node, we need to choose a subset of
// these nodes such that the sum of selected nodes is maximum under a constraint that no two
// chosen nodes in the subset should be directly connected, that is, if we have taken a node
// in our sum then we can’t take any of its children in consideration and vice versa

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;

    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

int maxNonAdjSum(Node *node, unordered_map<Node *, int> &dp)
{
    if (node == nullptr)
    {
        return 0;
    }

    if (dp.find(node) != dp.end())
    {
        return dp[node];
    }

    int include = node->data;
    if (node->left != nullptr)
    {
        include += (maxNonAdjSum((node->left)->left, dp) + maxNonAdjSum((node->left)->right, dp));
    }

    if (node->right != nullptr)
    {
        include += (maxNonAdjSum((node->right)->left, dp) + maxNonAdjSum((node->right)->right, dp));
    }

    int exclude = maxNonAdjSum(node->left, dp) + maxNonAdjSum(node->right, dp);

    dp[node] = max(include, exclude);
    return dp[node];
}
