// A binary tree and a number k are given. Print every path in the tree with sum of the
// nodes in the path as k.
// A path can start from any node and end at any node and must be downward only, i.e. they
// need not be root node and leaf node; and negative numbers can also be there in the tree.

// Example:
// Input:
// k = 5
//            1
//         /     \
//       3        -1
//     /   \     /   \
//    2     1  4       5
//        /  /   \       \                    
//       1 1       2       6
// Output:
// 3 2
// 3 1 1
// 1 3 1
// 4 1
// 1 -1 4 1
// -1 4 2
// 5
// 1 -1 5

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
