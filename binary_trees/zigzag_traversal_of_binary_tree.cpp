// Given a Binary Tree. Find the Zig-Zag Level Order Traversal of the Binary Tree.

// Example:
// Input:	   7
// 	        /     \
// 	       9       7
// 	     /  \     /
// 	    8    8   6
// 	   /  \
// 	  10   9
// Output:  7 7 9 8 8 6 9 10

#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node *left;
	Node *right;
};

vector<int> zigZagTraversal(Node *root)
{
	vector<int> res;
	if (root == nullptr)
	{
		return res;
	}

	queue<Node *> q;
	q.push(root);

	bool leftToRight = true;
	while (!q.empty())
	{
		int q_size = q.size();
		vector<int> level(q_size);

		for (int i = 0; i < q_size; i++)
		{
			Node *tmp = q.front();
			q.pop();

			int index = (leftToRight) ? i : (q_size - 1 - i);
			level[index] = tmp->data;

			if (tmp->left != nullptr)
			{
				q.push(tmp->left);
			}

			if (tmp->right != nullptr)
			{
				q.push(tmp->right);
			}
		}

		for (int &num : level)
		{
			res.push_back(num);
		}

		leftToRight = !leftToRight;
	}

	return res;
}
