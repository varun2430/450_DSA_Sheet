#include <bits/stdc++.h>
using namespace std;

class DLLNode
{
public:
    int data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(int val)
    {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class Compare
{
public:
    bool operator()(DLLNode *a, DLLNode *b)
    {
        return (a->data > b->data);
    }
};

DLLNode *sortAKSortedDLL(DLLNode *head, int k)
{
    priority_queue<DLLNode *, vector<DLLNode *>, Compare> pq;

    while ((head != nullptr) && (k >= 0))
    {
        pq.push(head);
        head = head->next;
        k -= 1;
    }

    DLLNode *newHead = nullptr;
    DLLNode *tail = nullptr;
    while (!pq.empty())
    {
        DLLNode *node = pq.top();
        pq.pop();

        if (newHead == nullptr)
        {
            newHead = node;
            newHead->prev = nullptr;
            tail = newHead;
        }
        else
        {
            tail->next = node;
            node->prev = tail;
            tail = tail->next;
        }

        if (head != nullptr)
        {
            pq.push(head);
            head = head->next;
        }
    }

    tail->next = nullptr;

    return newHead;
}
