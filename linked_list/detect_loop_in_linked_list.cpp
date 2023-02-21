#include<iostream>
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

bool detectLoop(Node *head)
{
    if ((head == nullptr) || (head->next == nullptr))
    {
        return false;
    }

    Node *slow = head;
    Node *fast = head;

    while ((fast->next != nullptr) && ((fast->next)->next != nullptr))
    {
        slow = slow->next;
        fast = (fast->next)->next;

        if (slow == fast)
        {
            return true;
        }
    }

    return false;
}
