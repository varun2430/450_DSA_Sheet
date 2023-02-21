#include<iostream>
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

struct node *reverse(struct node *head, int k)
{
    if ((head == nullptr) || (k == 1))
    {
        return head;
    }

    node *new_head = new node(-1);
    new_head->next = head;

    node *prev = new_head, *curr = new_head, *next = new_head;

    int count = 0;
    while (curr != nullptr)
    {
        count++;
        curr = curr->next;
    }

    while (next != nullptr)
    {
        curr = prev->next;
        next = curr->next;

        int toLoop = count > k ? k : count - 1;
        for (int i = 1; i < toLoop; i++)
        {
            curr->next = next->next;
            next->next = prev->next;
            prev->next = next;
            next = curr->next;
        }

        prev = curr;
        count -= k;
    }

    return new_head->next;
}
