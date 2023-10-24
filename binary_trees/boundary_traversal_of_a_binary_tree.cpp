// Given a Binary Tree, find its Boundary Traversal. The traversal should be in the
// following order:
// Left boundary nodes: defined as the path from the root to the left-most node ie- the leaf
// node you could reach when you always travel preferring the left subtree over the right
// subtree.
// Leaf nodes: All the leaf nodes except for the ones that are part of left or right
// boundary.
// Reverse right boundary nodes: defined as the path from the right-most node to the root.
// The right-most node is the leaf node you could reach when you always travel preferring
// the right subtree over the left subtree. Exclude the root from this as it was already
// included in the traversal of left boundary nodes.
// Note: If the root doesn't have a left subtree or right subtree, then the root itself is
// the left or right boundary.

// Example:
// Input:          1
//                /
//               2
//             /  \
//            4    9
//          /  \    \
//         6    5    3
//                  /  \
//                 7     8
// Output: 1 2 4 6 5 7 8

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

bool isLeaf(Node *root)
{
    if ((root->left == nullptr) && (root->right == nullptr))
    {
        return true;
    }

    return false;
}

void leftBoundary(Node *root, vector<int> &res)
{
    Node *curr = root->left;

    while (curr != nullptr)
    {
        if (!isLeaf(curr))
        {
            res.push_back(curr->data);
        }

        if (curr->left != nullptr)
        {
            curr = curr->left;
        }
        else
        {
            curr = curr->right;
        }
    }
}

void rightBoundary(Node *root, vector<int> &res)
{
    Node *curr = root->right;

    vector<int> tmp;
    while (curr != nullptr)
    {
        if (!isLeaf(curr))
        {
            tmp.push_back(curr->data);
        }

        if (curr->right != nullptr)
        {
            curr = curr->right;
        }
        else
        {
            curr = curr->left;
        }
    }

    for (auto itr = tmp.rbegin(); itr != tmp.rend(); itr++)
    {
        res.push_back(*itr);
    }
}

void leafBoundary(Node *root, vector<int> &res)
{
    if (isLeaf(root))
    {
        res.push_back(root->data);
    }

    if (root->left != nullptr)
    {
        leafBoundary(root->left, res);
    }

    if (root->right != nullptr)
    {
        leafBoundary(root->right, res);
    }
}

vector<int> boundary(Node *root)
{
    vector<int> res;

    if (root == nullptr)
    {
        return res;
    }

    if (!isLeaf(root))
    {
        res.push_back(root->data);
    }

    leftBoundary(root, res);

    leafBoundary(root, res);

    rightBoundary(root, res);

    return res;
}
