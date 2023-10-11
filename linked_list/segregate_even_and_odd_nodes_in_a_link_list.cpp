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

Node *divide(int N, Node *head)
{
    Node *even_start = nullptr;
    Node *even_end = nullptr;
    Node *odd_start = nullptr;
    Node *odd_end = nullptr;

    Node *curr = head;
    while (curr != nullptr)
    {
        if (curr->data % 2 == 0)
        {
            if (even_start == nullptr)
            {
                even_start = curr;
                even_end = even_start;
            }
            else
            {
                even_end->next = curr;
                even_end = even_end->next;
            }
        }
        else
        {
            if (odd_start == nullptr)
            {
                odd_start = curr;
                odd_end = odd_start;
            }
            else
            {
                odd_end->next = curr;
                odd_end = odd_end->next;
            }
        }

        curr = curr->next;
    }

    if ((even_start == nullptr) || (odd_start == nullptr))
    {
        return head;
    }

    even_end->next = odd_start;
    odd_end->next = nullptr;

    return even_start;
}
