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

void inorderRecursive(Node* root)
{
    if(root == nullptr)
    {
        return;
    }

    inorderRecursive(root->left);

    cout << root->data << " ";

    inorderRecursive(root->right);
}

void inorderIterative(Node* root)
{
    stack<Node*> s;

    Node* curr = root;

    while( (!s.empty()) || (curr != nullptr) )
    {
        while (curr != nullptr)
        {
            s.push(curr);
            curr = curr->left;    
        }

        curr = s.top();
        s.pop();

        cout << curr->data << " ";

        curr = curr->right;
    }
}
