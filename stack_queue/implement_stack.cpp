#include<iostream>
using namespace std;

class StackNode
{
    public:
    int data;
    StackNode* next;

    StackNode(int x)
    {
        data = x;
        next = nullptr;
    }
};

class Stack
{
    StackNode* root = nullptr;
    
    public:
    bool empty()
    {
        if(root == nullptr)
        {
            return true;
        }

        return false;
    }

    void push(int x)
    {
        StackNode* new_node = new StackNode(x);
        new_node->next = root;
        root = new_node;
    }

    int pop()
    {
        if(empty())
        {
            return INT_MIN;
        }

        StackNode* toPop = root;
        root = root->next;
        int popped = toPop->data;
        delete toPop;
        return popped;
    }

    int top()
    {
        if(empty())
        {
            return INT_MIN;
        }

        return root->data;
    }
};


int main()
{
    Stack s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.top() << endl;

    return 0;
}
