// Given a binary tree, task is to find subtree with maximum sum in tree.

// Examples:
// Input:         1
//             /    \
//           -2      3
//           / \    /  \
//          4   5  -6   2
// Output : 7

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    Node *left, *right;
};

int findLargestSubtreeSum(Node *root, int &max_sum)
{
    if (root == nullptr)
    {
        return 0;
    }

    int curr_sum = root->key + findLargestSubtreeSum(root->left, max_sum) + findLargestSubtreeSum(root->right, max_sum);

    max_sum = max(max_sum, curr_sum);

    return curr_sum;
}
