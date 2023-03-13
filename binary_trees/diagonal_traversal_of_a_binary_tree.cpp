#include<iostream>
#include<vector>
#include<queue>
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
