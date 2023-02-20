#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

struct Node *reverseListIterative(struct Node *head)
{
    Node *prev = nullptr;
    Node *curr = head;
    Node *next = nullptr;

    while (curr != nullptr)
    {
        next = curr->next;
        curr->next = prev; // curr now points to prev
        prev = curr;
        curr = next;
    }

    head = prev;

    return head;
}

struct Node *reverseListRecursive(struct Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *rest = reverseListRecursive(head->next);
    head->next->next = head;

    head->next = NULL;

    return rest;
}
