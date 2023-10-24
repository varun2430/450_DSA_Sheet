// Given a binary tree, find if it is height balanced or not.
// A tree is height balanced if difference between heights of left and right subtrees is
// not more than one for all nodes of tree.

// Example:
// Input:     10
//          /   \
//         20   30
//       /   \
//      40   60
// Output: 1

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

int check(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    int left = check(root->left);
    if (left == -1)
    {
        return -1;
    }

    int right = check(root->right);
    if (right == -1)
    {
        return -1;
    }

    if (abs(left - right) > 1)
    {
        return -1;
    }

    return max(left, right) + 1;
}

bool isBalanced(Node *root)
{
    return (check(root) != -1);
}
