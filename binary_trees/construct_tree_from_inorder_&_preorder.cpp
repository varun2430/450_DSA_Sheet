#include<bits/stdc++.h>
using namespace std;

Node* buildTree(int pStart, int pEnd, int iStart, int iEnd, int pre[], int in[], unordered_map<int, int>& inPos)
{
    if(iStart > iEnd)
    {
        return nullptr;
    }
    
    Node* root = new Node(pre[pStart]);
    
    if(iStart == iEnd)
    {
        return root;
    }
    
    int inRootPos = inPos[root->data];
    int noLeft = inRootPos - iStart;
    
    root->left = buildTree(pStart + 1, pStart + noLeft, iStart, inRootPos - 1, pre, in, inPos);
    root->right = buildTree(pStart + noLeft + 1, pEnd, inRootPos + 1, iEnd, pre, in, inPos);
    
    return root;
}

Node* buildTree(int in[],int pre[], int n)
{
    unordered_map<int, int> inPos;
    for(int i=0 ; i < n ; i++)
    {
        inPos[in[i]] = i;
    }
    
    Node* root = buildTree(0, n-1, 0, n-1, pre, in, inPos);
    
    return root;
}
