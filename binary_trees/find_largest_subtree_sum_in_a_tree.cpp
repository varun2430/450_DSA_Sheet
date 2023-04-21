#include<bits/stdc++.h>
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
