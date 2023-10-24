// Given a Binary Tree, print the diagonal traversal of the binary tree.
// Consider lines of slope -1 passing between nodes. Given a Binary Tree, print all diagonal
// elements in a binary tree belonging to same line.
// If the diagonal element are present in two different subtress then left subtree diagonal
// element should be taken first and then right subtree.

// Example:
// Input:          8
//              /     \
//             3      10
//           /   \      \
//          1     6     14
//              /   \   /
//             4     7 13
// Output : 8 10 14 3 6 7 13 1 4

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

void diagonalTraverse(Node *root, vector<int> &res)
{
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();

        while (size--)
        {
            Node *curr = q.front();
            q.pop();

            while (curr != nullptr)
            {
                res.push_back(curr->data);

                if (curr->left != nullptr)
                {
                    q.push(curr->left);
                }

                curr = curr->right;
            }
        }
    }
}

vector<int> diagonal(Node *root)
{
    vector<int> res;

    diagonalTraverse(root, res);

    return res;
}
