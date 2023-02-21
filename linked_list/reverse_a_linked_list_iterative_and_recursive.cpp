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
        curr->next = prev;          // curr now points to prev
        prev = curr;
        curr = next;
    }

    head = prev;

    return head;
}

struct Node *reverseListRecursive(struct Node *head)
{
    if( (head == nullptr) || (head->next == nullptr) )
    {
        return head;
    }

    Node *new_head = reverseListRecursive(head->next);

    Node *next = head->next;
    next->next = head;          // next now points to curr
    head->next = nullptr;       // curr now points to null

    return new_head;
}
