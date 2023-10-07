#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

struct compare
{
    bool operator()(
        struct Node *a, struct Node *b)
    {
        return a->data > b->data;
    }
};

Node *mergeKLists(Node *arr[], int K)
{
    priority_queue<Node *, vector<Node *>, compare> pq;

    for (int i = 0; i < K; i++)
    {
        if (arr[i] != nullptr)
        {
            pq.push(arr[i]);
        }
    }

    if (pq.empty())
    {
        return nullptr;
    }

    Node *head = new Node(0);
    Node *curr = head;
    while (!pq.empty())
    {
        Node *node = pq.top();
        pq.pop();

        curr->next = node;
        curr = curr->next;

        if (node->next != nullptr)
        {
            pq.push(node->next);
        }
    }

    return head->next;
}
