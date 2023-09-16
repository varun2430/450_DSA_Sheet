#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

Node *reverseDLLInGroups(Node *head, int k)
{
    if ((head == nullptr) || (k <= 1))
    {
        return head;
    }

    Node *curr_group_start = head;
    Node *prev_group_end = nullptr;
    Node *new_head = nullptr;

    while (curr_group_start != nullptr)
    {
        Node *curr = curr_group_start;
        Node *prev = nullptr;
        Node *next = nullptr;

        int count = 0;
        while ((curr != nullptr) && (count < k))
        {
            next = curr->next;
            curr->prev = next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count += 1;
        }

        if (new_head == nullptr)
        {
            new_head = prev;
            new_head->prev = nullptr;
        }

        if (prev_group_end == nullptr)
        {
            prev_group_end = curr_group_start;
        }
        else
        {
            // link prev group's end to curr reversed ddl
            prev_group_end->next = prev;
            prev->prev = prev_group_end;

            prev_group_end = curr_group_start;
        }

        curr_group_start = curr;
    }

    return new_head;
}
