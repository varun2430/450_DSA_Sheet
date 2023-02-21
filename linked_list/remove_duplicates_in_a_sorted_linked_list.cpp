#include<iostream>
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

Node *removeDuplicates(Node *head)
{
    if (head == NULL)
    {
        return head;
    }

    Node *curr = head;
    Node *next = nullptr;

    while (curr->next != NULL)
    {
        next = curr->next;

        if (curr->data == next->data)
        {
            curr->next = next->next;
            free(next);
        }
        else
        {
            curr = curr->next;
        }
    }

    return head;
}
