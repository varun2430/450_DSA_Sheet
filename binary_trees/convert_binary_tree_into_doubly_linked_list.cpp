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
        left = right = NULL;
    }
};

void inOrder(Node *root, Node **head, Node **prev)
{
    if (root == nullptr)
    {
        return;
    }

    inOrder(root->left, head, prev);

    if (*head == nullptr)
    {
        *head = root;
    }
    else
    {
        (*prev)->right = root;
        root->left = *prev;
    }
    *prev = root;

    inOrder(root->right, head, prev);
}

Node *bToDLL(Node *root)
{
    Node *head = nullptr;
    Node *prev = nullptr;

    inOrder(root, &head, &prev);

    return head;
}
