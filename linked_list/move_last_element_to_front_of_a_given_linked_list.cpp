#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
};

Node* moveLastToFirst(Node* head)
{
    if( (head == nullptr) || (head->next == nullptr) )
    {
        return head;
    }

    Node* curr = head;
    Node* prev = nullptr;

    while(curr->next != nullptr)
    {
        prev = curr;
        curr = curr->next;
    }

    prev->next = nullptr;
    curr->next = head;
    head = curr;

    return head;
}
