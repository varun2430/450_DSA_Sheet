#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

Node* addOne(Node *head) 
    {
        if(head == nullptr)
        {
            return head;
        }
        
        Node* curr = head;
        Node* last_lt_9 = head;
        while(curr->next != nullptr)
        {
            if(curr->data != 9)
            {
                last_lt_9 = curr;
            }
            
            curr = curr->next;
        }
        
        if(curr->data == 9)                                         // last digit is 9
        {
            if( (last_lt_9 == head) && (last_lt_9->data == 9) )     // all digits are 9
            {
                Node* new_node = new Node(1);
                new_node->next = head;
                head = new_node;
            }
            else                                                    // suffix is 9's
            {
                last_lt_9->data += 1;
                last_lt_9 = last_lt_9->next;
            }
            
            while(last_lt_9 != nullptr)
            {
                last_lt_9->data = 0;
                last_lt_9 = last_lt_9->next;
            }
        }
        else                                                        // last digit is less than 9
        {
            curr->data += 1;
        }
        
        return head;
    }
