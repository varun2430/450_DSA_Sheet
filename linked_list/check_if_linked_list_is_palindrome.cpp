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

bool compare(Node *head1, Node *head2)
{
    while ((head1 != nullptr) && (head2 != nullptr))
    {
        if (head1->data != head2->data)
        {
            return false;
        }
        else
        {
            head1 = head1->next;
            head2 = head2->next;
        }
    }

    if ((head1 == nullptr) && (head2 == nullptr))
    {
        return true;
    }

    return false;
}

void reverse(Node **head)
{
    Node *prev = nullptr;
    Node *curr = *head;
    Node *next = nullptr;

    while (curr != nullptr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    *head = prev;
}

bool isPalindrome(Node *head)
{
    if ((head == nullptr) || (head->next == nullptr))
    {
        return true;
    }

    Node *slow = head;
    Node *fast = head;
    Node *prev_to_slow = nullptr;
    Node *mid = nullptr;

    while ((fast != nullptr) && (fast->next != nullptr))
    {
        fast = (fast->next)->next;
        prev_to_slow = slow;
        slow = slow->next;
    }

    // if odd len then store mid separately
    // thus excluding it from the second half
    if (fast != nullptr)
    {
        mid = slow;
        slow = slow->next;
    }

    // head of second half
    Node *second_half = slow;

    // detach the two parts
    prev_to_slow->next = nullptr;

    reverse(&second_half);

    bool res = compare(head, second_half);

    reverse(&second_half);

    // restore the list to original state
    if (mid != nullptr)
    {
        prev_to_slow->next = mid;
        mid->next = second_half;
    }
    else
    {
        prev_to_slow->next = second_half;
    }

    return res;
}
