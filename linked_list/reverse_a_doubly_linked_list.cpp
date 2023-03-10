#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
    Node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

Node *reverseDLL(Node *head)
{
    Node *tmp = nullptr;
    Node *curr = head;

    while (curr != nullptr)
    {
        tmp = curr->prev;
        curr->prev = curr->next;
        curr->next = tmp;
        curr = curr->prev;
    }

    // check if list was empty
    if (tmp != nullptr)
    {
        head = tmp->prev;
    }

    return head;
}
