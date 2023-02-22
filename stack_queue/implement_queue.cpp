#include<iostream>
using namespace std;

class QueueNode 
{
    public:
    int data;
    QueueNode* next;

    QueueNode(int x)
    {
        data = x;
        next = nullptr;
    }
};

class Queue
{
    QueueNode* root = nullptr;
    QueueNode* rear = nullptr;

    public:
    bool empty()
    {
        if(rear == nullptr)
        {
            return true;
        }

        return false;
    }

    int front()
    {
        if(empty())
        {
            return INT_MIN;
        }

        return root->data;
    }

    void enqueue(int x)
    {
        QueueNode* new_node = new QueueNode(x);

        if(empty())
        {
            root = new_node;
            rear = new_node;
            return;
        }

        rear->next = new_node;
        rear = new_node;
    }

    void dequeue()
    {
        if(empty())
        {
            return;
        }

        QueueNode* toDequeue = root;
        root = root->next;
        delete toDequeue;

        if(root == nullptr)
        {
            rear = nullptr;
        }
    }
};

int main()
{
    Queue q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);

    q.dequeue();
    q.dequeue();
    q.dequeue();

    cout << q.front() << endl;

    return 0;
}
