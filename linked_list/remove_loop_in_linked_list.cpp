#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void removeLoop(Node *head)
{
    if ((head == nullptr) || (head->next == nullptr))
    {
        return;
    }

    Node *slow = head;
    Node *fast = head;

    while ((fast->next != nullptr) && ((fast->next)->next != nullptr))
    {
        slow = slow->next;
        fast = (fast->next)->next;

        if (slow == fast)
        {
            break;
        }
    }

    if (slow == fast)
    {
        slow = head;

        // condition when loop is at head
        if (slow == fast)
        {
            while (fast->next != slow)
            {
                fast = fast->next;
            }
        }
        else
        {
            while (slow->next != fast->next)
            {
                slow = slow->next;
                fast = fast->next;
            }
        }

        fast->next = nullptr;
    }
}
