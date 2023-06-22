#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

Node *construct(int pre[], int *preStart, int in[], int inStart, int inEnd, unordered_map<int, queue<int>> &m, int &n)
{
    if ((*preStart > n) || (inStart > inEnd))
    {
        return nullptr;
    }

    Node *root = new Node(pre[*preStart]);
    int rootPos = m[root->data].front();
    m[root->data].pop();

    *preStart = *preStart + 1;

    root->left = construct(pre, preStart, in, inStart, rootPos - 1, m, n);
    root->right = construct(pre, preStart, in, rootPos + 1, inEnd, m, n);

    return root;
}

Node *buildTree(int in[], int pre[], int n)
{
    unordered_map<int, queue<int>> m;
    for (int i = 0; i < n; i++)
    {
        m[in[i]].push(i);
    }

    int preStart = 0;

    return construct(pre, &preStart, in, 0, n - 1, m, n);
}
