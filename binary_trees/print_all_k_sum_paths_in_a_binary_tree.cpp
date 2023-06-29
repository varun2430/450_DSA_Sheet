#include <bits/stdc++.h>
using namespace std;

class BinaryTreeNode
{
public:
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void preorder(BinaryTreeNode *node, vector<int> &path, int &k, vector<vector<int>> &res)
{
    if (node == nullptr)
    {
        return;
    }

    path.push_back(node->data);

    preorder(node->left, path, k, res);
    preorder(node->right, path, k, res);

    int sum = 0;
    vector<int> sumPath;
    for (int i = path.size() - 1; i > -1; i--)
    {
        sum += path[i];
        sumPath.push_back(path[i]);

        if (sum == k)
        {
            vector<int> tmp = sumPath;
            reverse(tmp.begin(), tmp.end());
            res.push_back(tmp);
        }
    }

    path.pop_back();
}

vector<vector<int>> kPathSum(BinaryTreeNode *root, int k)
{
    vector<vector<int>> res;
    vector<int> path;

    preorder(root, path, k, res);

    return res;
}
