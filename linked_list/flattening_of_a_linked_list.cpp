#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

// merge two sorted linked list
Node *merge(Node *a, Node *b)
{
    Node *tmp = new Node(0);
    Node *res = tmp;

    while ((a != nullptr) && (b != nullptr))
    {
        if (a->data < b->data)
        {
            tmp->bottom = a;
            tmp = tmp->bottom;
            a = a->bottom;
        }
        else
        {
            tmp->bottom = b;
            tmp = tmp->bottom;
            b = b->bottom;
        }
    }

    if (a != nullptr)
    {
        tmp->bottom = a;
    }

    if (b != nullptr)
    {
        tmp->bottom = b;
    }

    return res->bottom;
}

// merge two linked list from the end
Node *flatten(Node *root)
{
    if ((root == nullptr) || (root->next == nullptr))
    {
        return root;
    }

    root->next = flatten(root->next);
    root = merge(root, root->next);

    return root;
}
