// Given a binary tree of size N. Your task is to complete the function
// sumOfLongRootToLeafPath(), that find the sum of all nodes on the longest path from root
// to leaf node.
// If two or more paths compete for the longest path, then the path having maximum sum of
// nodes is being considered.

// Example:
// Input:        1
//             /   \
//            2     3
//           / \   / \
//          4   5 6   7
// Output: 11

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
        left = NULL;
        right = NULL;
    }
};

void sumRootToLeaf(Node *root, int sum, int &max_sum, int len, int &max_len)
{
    if (root == nullptr)
    {
        if (len > max_len)
        {
            max_len = len;
            max_sum = sum;
        }
        else if ((len == max_len) && (sum > max_sum))
        {
            max_sum = sum;
        }

        return;
    }

    sumRootToLeaf(root->left, sum + root->data, max_sum, len + 1, max_len);
    sumRootToLeaf(root->right, sum + root->data, max_sum, len + 1, max_len);
}

int sumOfLongRootToLeafPath(Node *root)
{
    int max_sum = INT_MIN;
    int max_len = INT_MIN;

    sumRootToLeaf(root, 0, max_sum, 0, max_len);

    return max_sum;
}
