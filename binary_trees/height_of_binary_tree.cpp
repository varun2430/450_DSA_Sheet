#include<iostream>
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
