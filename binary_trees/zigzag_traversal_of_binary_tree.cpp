#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

vector <int> zigZagTraversal(Node* root)
{
	vector<int> res;
	if(root == nullptr)
	{
	    return res;
	}
	
	queue<Node*> q;
	q.push(root);
	
	bool leftToRight = true;
	while(!q.empty())
	{
	    int q_size = q.size();
	    vector<int> level(q_size);
	    
	    for(int i=0 ; i < q_size ; i++)
	    {
	        Node* tmp = q.front();
	        q.pop();
	        
	        int index = (leftToRight) ? i : (q_size - 1 - i);
	        level[index] = tmp->data;
	        
	        if(tmp->left != nullptr)
	        {
	            q.push(tmp->left);
	        }
	        
	        if(tmp->right != nullptr)
	        {
	            q.push(tmp->right);
	        }
	    }
	    
	    for(int& num : level)
	    {
	        res.push_back(num);
	    }
	    
	    leftToRight = !leftToRight;
	}
	
	return res;
}
