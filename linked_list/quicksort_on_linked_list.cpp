#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;

    node(int x)
    {
        data = x;
        next = NULL;
    }
};

node *partition(node *head, node *tail)
{
    node *curr = head;
    node *prev = head;
    node *pivot = head;

    while (curr != tail->next)
    {
        if (curr->data < pivot->data)
        {
            swap(curr->data, (prev->next)->data);
            prev = prev->next;
        }

        curr = curr->next;
    }

    swap(pivot->data, prev->data);
    return prev;
}

void quicksort(node *head, node *tail)
{
    if ((head == nullptr) || (tail == nullptr) || (head == tail))
    {
        return;
    }

    node *pivot = partition(head, tail);

    quicksort(head, pivot);
    quicksort(pivot->next, tail);
}

void quickSort(struct node **headRef)
{
    node *head = *headRef;

    if ((head == nullptr) || (head->next == nullptr))
    {
        return;
    }

    node *tail = head;
    while (tail->next != nullptr)
    {
        tail = tail->next;
    }

    quicksort(head, tail);
}
