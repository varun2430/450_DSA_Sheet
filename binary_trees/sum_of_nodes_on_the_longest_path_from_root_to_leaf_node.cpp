#include<bits/stdc++.h>
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
