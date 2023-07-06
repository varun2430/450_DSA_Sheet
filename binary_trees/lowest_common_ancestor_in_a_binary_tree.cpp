#include <bits/stdc++.h>
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

// simple approach is to find paths for both nodes seperately and
// find the farthest common node from the root in both the paths

Node *lca(Node *root, int n1, int n2)
{
    if ((root == nullptr) || (root->data == n1) || (root->data == n2))
    {
        return root;
    }

    Node *left = lca(root->left, n1, n2);
    Node *right = lca(root->right, n1, n2);

    // if any one node is found return the found node
    // if both the nodes are found return the root node that called
    // the function
    if (left == nullptr)
    {
        return right;
    }
    else if (right == nullptr)
    {
        return left;
    }
    else
    {
        return root;
    }
}
