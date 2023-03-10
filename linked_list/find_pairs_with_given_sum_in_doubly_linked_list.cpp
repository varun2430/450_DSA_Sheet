#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next, *prev;
};

void getPair(Node* head, int key)
{
    Node* left = head;
    Node* right = head;

    while(right->next != nullptr)
    {
        right = right->next;
    }

    while( (left != right) && (right->next != left) )
    {
        if((left->data + right->data) == key)
        {
            cout << left->data << " " << right->data << "\n";

            left = left->next;
            right = right->prev;
        }
        else if((left->data + right->data) < key)
        {
            left = left->next;
        }
        else
        {
            right = right->prev;
        }
    }
}
