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

int getNthFromLast(Node *head, int n)
{
    Node *ptr_1 = head;
    Node *ptr_2 = head;

    for (int i = 1; i < n; i++)
    {
        ptr_2 = ptr_2->next;

        if (ptr_2 == nullptr)
        {
            return -1;
        }
    }

    while ((ptr_2 != nullptr) && (ptr_2->next != nullptr))
    {
        ptr_1 = ptr_1->next;
        ptr_2 = ptr_2->next;
    }

    return ptr_1->data;
}
