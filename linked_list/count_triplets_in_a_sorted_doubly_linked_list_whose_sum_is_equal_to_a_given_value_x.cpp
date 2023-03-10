#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *next, *prev;
};

int countPair(Node* left, Node* right, int x)
{
    int count = 0;

    while( (left != nullptr) && (right != nullptr) && (left != right) && (right->next != left) )
    {
        if((left->data + right->data) == x)
        {
            count += 1;

            left = left->next;
            right = right->prev;
        }
        else if((left->data + right->data) < x)
        {
            left = left->next;
        }
        else
        {
            right = right->prev;
        }
    }

    return count;
}

int countTriplets(Node* head, int x)
{
    if(head == nullptr)
    {
        return 0;
    }

    Node* curr = head;
    Node* left = nullptr;
    Node* right = head;

    while(right->next != nullptr)
    {
        right = right->next;
    }

    int count = 0;
    while(curr != nullptr)
    {
        left = curr->next;

        count += countPair(left, right, x - curr->data);

        curr = curr->next;
    }

    return count;
}
