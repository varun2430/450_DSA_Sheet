// Construct a binary tree from a string consisting of parenthesis and integers. The whole 
// input represents a binary tree. It contains an integer followed by zero, one or two pairs 
// of parenthesis. The integer represents the roots value and a pair of parenthesis contains 
// a child binary tree with the same structure. Always start to construct the left child 
// node of the parent first if it exists. The integer values will be less than or equal 
// to 10^5.

// Example:
// Input:  "4(2(3)(1))(6(5))"
// Output: 3 2 1 4 5 6
// Explanation:
//            4
//          /   \
//         2     6
//        / \   / 
//       3   1 5  

#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

void mapBrackets(string &str, unordered_map<int, int> &m)
{
    int str_len = str.length();

    stack<int> s;
    for (int i = 0; i < str_len; i++)
    {
        if (str[i] == '(')
        {
            s.push(i);
        }
        else if (str[i] == ')')
        {
            m[s.top()] = i;
            s.pop();
        }
    }
}

Node *construct(string &str, int &n, unordered_map<int, int> &m, int start, int end)
{
    if (start > end)
    {
        return nullptr;
    }

    int num = 0;
    while ((start < n) && (isdigit(str[start])))
    {
        int x = (int)(str[start] - '0');
        num = num * 10 + x;
        start++;
    }

    Node *root = new Node(num);

    int leftEnd = -1;
    if ((start <= end) && (str[start] == '('))
    {
        leftEnd = m[start];
    }

    if (leftEnd != -1)
    {
        root->left = construct(str, n, m, start + 1, leftEnd - 1);

        root->right = construct(str, n, m, leftEnd + 2, end - 1);
    }

    return root;
}

Node *treeFromString(string str)
{
    int str_len = str.length();

    unordered_map<int, int> m;
    mapBrackets(str, m);

    Node *root = construct(str, str_len, m, 0, str_len - 1);

    return root;
}
