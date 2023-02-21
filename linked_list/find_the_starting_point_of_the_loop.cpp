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

int findFirstNode(Node *head)
{
    if ((head == nullptr) || (head->next == nullptr))
    {
        return -1;
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

        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }

        return slow->data;
    }

    return -1;
}
