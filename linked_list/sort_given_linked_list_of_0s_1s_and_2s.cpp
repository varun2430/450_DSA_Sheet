#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node *segregate(Node *head)
{
    Node *zero_node = new Node(0);
    Node *one_node = new Node(0);
    Node *two_node = new Node(0);

    Node *zero = zero_node;
    Node *one = one_node;
    Node *two = two_node;

    Node *curr = head;
    while (curr != nullptr)
    {
        if (curr->data == 0)
        {
            zero->next = curr;
            zero = zero->next;
        }
        else if (curr->data == 1)
        {
            one->next = curr;
            one = one->next;
        }
        else
        {
            two->next = curr;
            two = two->next;
        }

        curr = curr->next;
    }

    zero->next = (one_node->next != nullptr) ? one_node->next : two_node->next;
    one->next = two_node->next;
    two->next = nullptr;

    head = zero_node->next;

    delete zero_node;
    delete one_node;
    delete two_node;

    return head;
}
