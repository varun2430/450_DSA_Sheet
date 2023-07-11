#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

// simple solution is to find the distance of each node from the root and
// determine the minimum distance between the two nodes

// a better solution is to find the lca of the two nodes first and find the
// distance of the two nodes from the lca to calculate the minimum distance

// optimal solution to get minimum distance in one pass
int solve(Node *root, int &a, int &b, int &minDist)
{
    if (root == nullptr)
    {
        return 0;
    }

    int left = solve(root->left, a, b, minDist);
    int right = solve(root->right, a, b, minDist);

    if ((left > 0) && (right > 0)) // if the curr node is the lca
    {
        minDist = left + right;
        return 0;
    }
    else if ((root->data == a) || (root->data == b)) // if curr node is one of the required nodes
    {
        if ((left > 0) || (right > 0)) // the other node is already found
        {
            minDist = max(left, right);
            return 0;
        }
        else // first time reaching the required node
        {
            return 1;
        }
    }
    else if ((left > 0) || (right > 0)) // the curr node is in between the two required nodes
    {
        return max(left, right) + 1;
    }

    return 0;
}

int findDist(Node *root, int a, int b)
{
    int minDist = 0;

    solve(root, a, b, minDist);

    return minDist;
}
