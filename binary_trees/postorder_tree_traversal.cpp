#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;

    Node(int x)
    {
        data = x;
        left = right = nullptr;
    }
};

void postorderRecursive(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    postorderRecursive(root->left);

    postorderRecursive(root->right);

    cout << root->data << " ";
}

void postorderIterative(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    stack<Node *> s;
    s.push(root);

    stack<int> output;
    while (!s.empty())
    {
        Node *curr = s.top();
        s.pop();

        output.push(curr->data);

        if (curr->left != nullptr)
        {
            s.push(curr->left);
        }

        if (curr->right != nullptr)
        {
            s.push(curr->right);
        }
    }

    while (!output.empty())
    {
        cout << output.top() << " ";
        output.pop();
    }
}
