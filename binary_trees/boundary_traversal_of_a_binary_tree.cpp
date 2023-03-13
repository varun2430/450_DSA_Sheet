#include<iostream>
#include<vector>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

bool isLeaf(Node *root)
{
    if ((root->left == nullptr) && (root->right == nullptr))
    {
        return true;
    }

    return false;
}

void leftBoundary(Node *root, vector<int> &res)
{
    Node *curr = root->left;

    while (curr != nullptr)
    {
        if (!isLeaf(curr))
        {
            res.push_back(curr->data);
        }

        if (curr->left != nullptr)
        {
            curr = curr->left;
        }
        else
        {
            curr = curr->right;
        }
    }
}

void rightBoundary(Node *root, vector<int> &res)
{
    Node *curr = root->right;

    vector<int> tmp;
    while (curr != nullptr)
    {
        if (!isLeaf(curr))
        {
            tmp.push_back(curr->data);
        }

        if (curr->right != nullptr)
        {
            curr = curr->right;
        }
        else
        {
            curr = curr->left;
        }
    }

    for (auto itr = tmp.rbegin(); itr != tmp.rend(); itr++)
    {
        res.push_back(*itr);
    }
}

void leafBoundary(Node *root, vector<int> &res)
{
    if (isLeaf(root))
    {
        res.push_back(root->data);
    }

    if (root->left != nullptr)
    {
        leafBoundary(root->left, res);
    }

    if (root->right != nullptr)
    {
        leafBoundary(root->right, res);
    }
}

vector<int> boundary(Node *root)
{
    vector<int> res;

    if (root == nullptr)
    {
        return res;
    }

    if (!isLeaf(root))
    {
        res.push_back(root->data);
    }

    leftBoundary(root, res);

    leafBoundary(root, res);

    rightBoundary(root, res);

    return res;
}
