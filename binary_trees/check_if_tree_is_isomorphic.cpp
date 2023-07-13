#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

bool isIsomorphic(Node *root1, Node *root2)
{
    if ((root1 == nullptr) && (root2 == nullptr))
    {
        return true;
    }

    if ((root1 == nullptr) || (root2 == nullptr))
    {
        return false;
    }

    if (root1->data != root2->data)
    {
        return false;
    }

    bool same = isIsomorphic(root1->left, root2->left) && isIsomorphic(root1->right, root2->right);
    bool diff = isIsomorphic(root1->left, root2->right) && isIsomorphic(root1->right, root2->left);

    return (same || diff);
}