#include<bits/stdc++.h>
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

Node *split(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;

    while ((slow->next != nullptr) && (fast != nullptr) && (fast->next != nullptr))
    {
        slow = slow->next;
        fast = (fast->next)->next;
    }

    return slow;
}

Node *merge(Node *left, Node *right)
{
    // assign merged dummy node
    Node *merged = new Node(-1);
    Node *itr = merged;

    while ((left != nullptr) && (right != nullptr))
    {
        if (left->data <= right->data)
        {
            itr->next = left;
            left = left->next;
        }
        else
        {
            itr->next = right;
            right = right->next;
        }

        itr = itr->next;
    }

    while (left != nullptr)
    {
        itr->next = left;
        left = left->next;
        itr = itr->next;
    }

    while (right != nullptr)
    {
        itr->next = right;
        right = right->next;
        itr = itr->next;
    }

    // skip the dummy node;
    return merged->next;
}

Node *mergeSort(Node *head)
{
    if (head->next == nullptr)
    {
        return head;
    }

    Node *mid = split(head);

    Node *left = head;
    Node *right = mid->next; // points to element next to mid
    mid->next = nullptr;     // splites the linked list into two

    left = mergeSort(left);
    right = mergeSort(right);

    return merge(left, right);
}
