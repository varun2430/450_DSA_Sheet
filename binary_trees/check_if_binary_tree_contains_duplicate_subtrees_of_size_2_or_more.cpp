// Given a binary tree, find out whether it contains a duplicate sub-tree of size two or
// more, or not.
// Note: Two same leaf nodes are not considered as subtree as size of a leaf node is one.

// Example:
// Input:         1
//              /   \ 
//            2       3
//          /   \       \    
//         4     5       2
//                      /  \    
//                     4    5
// Output: 1

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    char data;
    struct Node *left;
    struct Node *right;
};

string solve(Node *root, unordered_map<string, int> &freq)
{
    if (root == nullptr)
    {
        return "#";
    }

    string str = "";

    if ((root->left == nullptr) && (root->right == nullptr))
    {
        return to_string(root->data);
    }

    str = str + to_string(root->data);
    str = str + "$" + solve(root->left, freq);
    str = str + "$" + solve(root->right, freq);

    freq[str]++;

    return str;
}

int dupSub(Node *root)
{
    unordered_map<string, int> freq;

    solve(root, freq);

    for (auto itr : freq)
    {
        if (itr.second > 1)
        {
            return true;
        }
    }

    return false;
}
