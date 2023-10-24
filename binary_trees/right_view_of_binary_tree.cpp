// Given a Binary Tree, find Right view of it. Right view of a Binary Tree is set of nodes
// visible when tree is viewed from right side.

// Example:
// Input:    10
//         /   \
//       20     30
//      /   \
//     40  60
// Output: 10 30 60

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

// can also be solved iteratively using level order traversal
void rightViewUtil(Node *root, int level, int *max_level_so_far, vector<int> &res)
{
    if (root == nullptr)
    {
        return;
    }

    if (level > *max_level_so_far)
    {
        res.push_back(root->data);
        *max_level_so_far = level;
    }

    rightViewUtil(root->right, level + 1, max_level_so_far, res);
    rightViewUtil(root->left, level + 1, max_level_so_far, res);
}

vector<int> rightView(Node *root)
{
    vector<int> res;
    int max_level_so_far = 0;

    rightViewUtil(root, 1, &max_level_so_far, res);

    return res;
}
