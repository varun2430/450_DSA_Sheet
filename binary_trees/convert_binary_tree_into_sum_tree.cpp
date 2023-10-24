// Given a Binary Tree of size N , where each node can have positive or negative values.
// Convert this to a tree where each node contains the sum of the left and right sub trees
// of the original tree. The values of leaf nodes are changed to 0.

// Example:
// Input:
//              10
//           /      \
//         -2        6
//        /   \     /  \
//      8     -4   7    5

// Output:
//             20
//           /    \
//         4        12
//        /  \     /  \
//      0     0   0    0

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

int makeSumTree(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    int left = makeSumTree(root->left);
    int right = makeSumTree(root->right);

    int old_val = root->data;

    root->data = left + right;

    return old_val + left + right;
}
