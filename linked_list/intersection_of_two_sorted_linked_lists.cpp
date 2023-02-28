#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node* findIntersection(Node* head1, Node* head2)
{
    Node* res = new Node(-1);
    Node* res_tail = res;
    
    while( (head1 != nullptr) && (head2 != nullptr) )
    {
        if(head1->data == head2->data)
        {
            Node* tmp = new Node(head1->data);
            res_tail->next = tmp;
            res_tail = res_tail->next;
            
            head1 = head1->next;
            head2 = head2->next;
        }
        else if(head1->data < head2->data)
        {
            head1 = head1->next;
        }
        else
        {
            head2 = head2->next;
        }
    }
    
    return res->next;
}

// using pointer to pointer and without dummy node
Node* findIntersection(Node* head1, Node* head2)
{
    Node* res = nullptr;
    Node** res_tail = &res;
    
    while( (head1 != nullptr) && (head2 != nullptr) )
    {
        if(head1->data == head2->data)
        {
            Node* tmp = new Node(head1->data);
            tmp->next = *res_tail;
            *res_tail = tmp;
            res_tail = &((*res_tail)->next);
            
            head1 = head1->next;
            head2 = head2->next;
        }
        else if(head1->data < head2->data)
        {
            head1 = head1->next;
        }
        else
        {
            head2 = head2->next;
        }
    }
    
    return res;
}
