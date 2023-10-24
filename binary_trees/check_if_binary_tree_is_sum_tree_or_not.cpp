// Given a Binary Tree. Return true if, for every node X in the tree other than the leaves,
// its value is equal to the sum of its left subtree's value and its right subtree's value.
// Else return false.
// An empty tree is also a Sum Tree as the sum of an empty tree can be considered to be 0.
// A leaf node is also considered a Sum Tree.

// Example:
// Input:        10
//             /    \
//           20      30
//         /   \ 
//        10    10
// Output: 0

#include <bits/stdc++.h>
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
