// Given a Binary Tree, check if all leaves are at same level or not.

// Example:
// Input:      1
//           /   \
//          2     3
// Output: 1

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

bool check(Node *root)
{
    queue<Node *> q;
    q.push(root);

    bool leaf_found = false;

    while (!q.empty())
    {
        int q_size = q.size();
        for (int i = 0; i < q_size; i++)
        {
            Node *curr = q.front();
            q.pop();

            if (curr->left != nullptr)
            {
                q.push(curr->left);
            }

            if (curr->right != nullptr)
            {
                q.push(curr->right);
            }

            if ((curr->left == nullptr) && (curr->right == nullptr))
            {
                leaf_found = true;
            }
        }

        if ((!q.empty()) && (leaf_found == true))
        {
            return false;
        }
    }

    return true;
}
