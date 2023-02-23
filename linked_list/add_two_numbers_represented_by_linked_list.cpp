#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node* next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

struct Node* reverseList(struct Node* list)
{
    Node* prev = nullptr;
    Node* cur = list;
    Node* next = nullptr;
    
    while (cur != nullptr)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    
    return prev;
}

struct Node* addTwoLists(struct Node* first, struct Node* second)
{
    first = reverseList(first);
    second = reverseList(second);
    
    int carry = 0;
    Node* res = nullptr;
    while( (first != nullptr) || (second != nullptr) || (carry > 0) )
    {
        int sum = carry;
        
        if(first != nullptr)
        {
            sum += first->data;
            first = first->next;
        }
        
        if(second != nullptr)
        {
            sum += second->data;
            second = second->next;
        }
        
        Node* new_node = new Node(sum % 10);
        new_node->next = res;
        res = new_node;
        
        carry = sum / 10;
    }
    
    return res;
}
