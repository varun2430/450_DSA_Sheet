// The diameter of a tree (sometimes called the width) is the number of nodes on the longest
// path between two end nodes. The diagram below shows two trees each with diameter nine,
// the leaves that form the ends of the longest path are shaded (note that there is more
// than one path in each tree of length nine, but no path longer than nine nodes).

// Example:
// Input:     10
//          /   \
//        20    30
//      /   \ 
//     40   60
// Output: 4

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
