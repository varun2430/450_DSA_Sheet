// Given a Binary Tree, return Left view of it. Left view of a Binary Tree is set of nodes
// visible when tree is visited from Left side. The task is to complete the function
// leftView(), which accepts root of the tree as argument.

// Example:
// Input:        1
//            /     \
//           2        3
//        /    \    /   \
//       4      5  6     7
//        \
//          8
// Output: 1 2 4 8

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
void leftViewUtil(Node *root, int level, int *max_level_so_far, vector<int> &res)
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

    leftViewUtil(root->left, level + 1, max_level_so_far, res);
    leftViewUtil(root->right, level + 1, max_level_so_far, res);
}

vector<int> leftView(Node *root)
{
    vector<int> res;
    int max_level_so_far = 0;

    leftViewUtil(root, 1, &max_level_so_far, res);

    return res;
}
