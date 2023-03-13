#include<iostream>
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
