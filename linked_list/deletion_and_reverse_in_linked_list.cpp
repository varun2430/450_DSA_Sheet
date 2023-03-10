#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

void deleteNode(struct Node **head, int key)
{
    if (*head == nullptr)
    {
        return;
    }

    if (((*head)->data == key) && ((*head)->next == *head))
    {
        free(*head);
        *head = nullptr;
        return;
    }

    if ((*head)->data == key)
    {
        Node *last = *head;
        while (last->next != *head)
        {
            last = last->next;
        }

        last->next = (*head)->next;
        free(*head);
        *head = last->next;
    }

    Node *itr = *head;
    while ((itr->next != *head) && ((itr->next)->data != key))
    {
        itr = itr->next;
    }

    if ((itr->next)->data == key)
    {
        Node *tmp = itr->next;
        itr->next = tmp->next;
        free(tmp);
    }
}

void reverse(struct Node **head_ref)
{
    if (*head_ref == nullptr)
    {
        return;
    }

    Node *prev = nullptr;
    Node *curr = *head_ref;
    Node *next = nullptr;

    // curr == *head_ref initially
    // so use do while loop
    do
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    } while (curr != (*head_ref));

    (*head_ref)->next = prev;
    *head_ref = prev;
}