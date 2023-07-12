#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
};

Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// a simpler approach would be to get all nodes in the path from root to the required node
// and determine the kth ancestor

Node *solve(Node *root, int &k, int &node)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    if (root->data == node)
    {
        return root;
    }

    Node *left = solve(root->left, k, node);
    Node *right = solve(root->right, k, node);

    if ((left != nullptr) || (right != nullptr))
    {
        k -= 1;
        if (k <= 0)
        {
            k = INT_MAX; // lock k so that it no longer return any other node
            return root;
        }

        return (left != nullptr) ? left : right;
    }

    return nullptr;
}

int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    int k = 3;
    int node = 5;

    Node *res = solve(root, k, node);

    if ((res == nullptr) || (res->data == node))
    {
        cout << -1 << endl;
    }
    else
    {
        cout << res->data << endl;
    }

    return 0;
}
