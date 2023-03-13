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
