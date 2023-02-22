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

int height(Node *root, int &diameter)
{
    if (root == nullptr)
    {
        return 0;
    }

    int lheight = height(root->left, diameter);
    int rheight = height(root->right, diameter);

    diameter = max(diameter, lheight + rheight + 1);

    return (max(lheight, rheight) + 1);
}

int diameter(Node *root)
{
    int diameter = 0;

    height(root, diameter);

    return diameter;
}
