#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
};

string preorder(Node *node, vector<Node *> &subTrees, unordered_map<string, int> &m)
{
    if (node == nullptr)
    {
        return "";
    }

    string str = "(";
    str += to_string(node->data);
    str += preorder(node->left, subTrees, m);
    str += preorder(node->right, subTrees, m);
    str += ")";

    if (m[str] == 1)
    {
        subTrees.push_back(node);
    }

    m[str]++;

    return str;
}

vector<Node *> printAllDups(Node *root)
{
    vector<Node *> subTrees;
    unordered_map<string, int> m;

    preorder(root, subTrees, m);

    return subTrees;
}
