#include<iostream>
#include<stack>
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

void preorderRecursive(Node* root)
{
    if(root == nullptr)
    {
        return;
    }

    cout << root->data << " ";

    preorderRecursive(root->left);

    preorderRecursive(root->right);
}

void preorderIterative(Node* root)
{
    if(root == nullptr)
    {
        return;
    }

    stack<Node*> s;
    s.push(root);

    while(!s.empty())
    {
        Node* curr = s.top();
        s.pop();

        cout << curr->data << " ";

        // push right first so that it gets poped last
        if(curr->right != nullptr)
        {
            s.push(curr->right);
        }

        if(curr->left != nullptr)
        {
            s.push(curr->left);
        }
    }
}
