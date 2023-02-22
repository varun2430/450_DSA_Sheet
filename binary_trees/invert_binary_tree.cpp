#include<iostream>
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
