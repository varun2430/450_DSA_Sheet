// Given the root of a binary tree, invert the tree, and return its root.

// Example:
// Input:  root = [4,2,7,1,3,6,9]
// Output: [4,7,2,9,6,3,1]

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void mirror(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    else
    {
        mirror(root->left);
        mirror(root->right);

        swap(root->left, root->right);
    }
}

TreeNode *invertTree(TreeNode *root)
{
    mirror(root);
    return root;
}
