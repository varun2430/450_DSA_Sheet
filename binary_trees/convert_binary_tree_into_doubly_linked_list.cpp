// Given a Binary Tree (BT), convert it to a Doubly Linked List(DLL) In-Place. The left and
// right pointers in nodes are to be used as previous and next pointers respectively in
// converted DLL. The order of nodes in DLL must be same as Inorder of the given Binary Tree.
// The first node of Inorder traversal (leftmost node in BT) must be the head node of the DLL.
// Note: H is the height of the tree and this space is used implicitly for the recursion stack.

// Example:
// Input:      10
//           /   \
//          20   30
//        /   \
//       40   60
// Output: 40 20 60 10 30

#include <bits/stdc++.h>
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
