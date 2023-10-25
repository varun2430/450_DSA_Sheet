// Given a binary tree of size N, your task is to that find all duplicate subtrees from the
// given binary tree.

// Note: Here's the Output of every Node printed in the Pre-Order tree traversal format.
// Arrange nodes in the answer array based on the lexicographically increasing order of
// their preorder traversal of subtree.
// For Example: if we have 3 preorder traversal as {1,2,3},{1},{11,2,3} then your
// lexicographically increasing order is {1},{1,2,3},{11,2,3}, you are supposed to output
// the head of all these subtrees in the same order.

// Example:
// Input:      1
//            / \
//           2   3
//          /   / \
//         4   2   4
//            /
//           4
// Output: 2 4
//         4

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
};

string preorder(Node *node, vector<Node *> &subTrees, unordered_map<string, int> &m)
{
    if (node == nullptr)
    {
        return "";
    }

    string str = "(";
    str += to_string(node->data);
    str += preorder(node->left, subTrees, m);
    str += preorder(node->right, subTrees, m);
    str += ")";

    if (m[str] == 1)
    {
        subTrees.push_back(node);
    }

    m[str]++;

    return str;
}

vector<Node *> printAllDups(Node *root)
{
    vector<Node *> subTrees;
    unordered_map<string, int> m;

    preorder(root, subTrees, m);

    return subTrees;
}
