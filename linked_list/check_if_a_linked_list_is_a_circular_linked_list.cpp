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

bool isCircular(Node *head)
{
   if(head == nullptr)
   {
       return false;
   }
   
   Node* itr = head->next;
   while( (itr != nullptr) && (itr != head) )
   {
       itr = itr->next;
   }
   
   return (itr == head);
}
