#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *arb;

    Node(int x)
    {
        data = x;
        next = nullptr;
        arb = nullptr;
    }
};

// can also be solved using hashmap

Node *copyList(Node *head)
{
    Node *copy_head = new Node(0);
    Node *copy_curr = copy_head;
    Node *curr = head;
    Node *next = nullptr;

    // add new copy nodes after original nodes
    while (curr != nullptr)
    {
        next = curr->next;
        Node *copy_node = new Node(curr->data);
        curr->next = copy_node;
        copy_node->next = next;
        curr = next;
    }

    // set random pointer for the copy nodes
    curr = head;
    while (curr != nullptr)
    {
        if (curr->arb != nullptr)
        {
            (curr->next)->arb = (curr->arb)->next;
        }

        curr = (curr->next)->next;
    }

    // seperate the original and copy nodes into two lists
    curr = head;
    while (curr != nullptr)
    {
        next = (curr->next)->next;
        copy_curr->next = curr->next;
        copy_curr = copy_curr->next;
        curr->next = next;
        curr = next;
    }

    copy_head = copy_head->next;

    return copy_head;
}
