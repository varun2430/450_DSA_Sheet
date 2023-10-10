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

Node *reverse(Node *head)
{
    Node *prev = nullptr;
    Node *curr = head;
    Node *next = nullptr;

    while (curr != nullptr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

Node *compute(Node *head)
{
    head = reverse(head);

    Node *prev = head;
    Node *curr = head->next;

    int max_so_far = head->data;
    while (curr != nullptr)
    {
        if (curr->data < max_so_far)
        {
            Node *tmp = curr;
            prev->next = curr->next;
            curr = curr->next;
            delete tmp;
        }
        else
        {
            max_so_far = max(max_so_far, curr->data);
            prev = curr;
            curr = curr->next;
        }
    }

    head = reverse(head);

    return head;
}
