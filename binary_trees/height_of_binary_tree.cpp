// Given a binary tree, find its height.

// Example:
// Input:  2
//           \
//            1
//           /
//         3
// Output: 3

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

int height(struct Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    int lheight = height(root->left);
    int rheight = height(root->right);

    return (max(lheight, rheight) + 1);
}
