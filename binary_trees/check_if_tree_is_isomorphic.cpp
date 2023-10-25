// Given two Binary Trees. Check whether they are Isomorphic or not.

// Note:
// Two trees are called isomorphic if one can be obtained from another by a series of flips,
// i.e. by swapping left and right children of several nodes. Any number of nodes at any
// level can have their children swapped. Two empty trees are isomorphic.
// For example, the following two trees are isomorphic with the following sub-trees
// flipped: 2 and 3, NULL and 6, 7 and 8.

// Example:
// Input:
// T1    1     T2:    1
//     /  \         /   \
//    2    3       3     2
//   /                    \
//   4                     4
// Output: Yes

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