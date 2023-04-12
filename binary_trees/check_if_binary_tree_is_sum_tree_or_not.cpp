#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

int checkSumTree(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    int left = checkSumTree(root->left);
    if (left == INT_MIN)
    {
        return INT_MIN;
    }

    int right = checkSumTree(root->right);
    if (right == INT_MIN)
    {
        return INT_MIN;
    }

    if ((root->left == nullptr && root->right == nullptr) || (root->data == left + right))
    {
        return (left + root->data + right);
    }
    else
    {
        return INT_MIN;
    }
}

bool isSumTree(Node *root)
{
    int res = checkSumTree(root);

    if (res == INT_MIN)
    {
        return false;
    }

    return true;
}
