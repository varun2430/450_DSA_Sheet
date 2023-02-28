#include<iostream>
using namespace std;

struct Node {
  int data;
  struct Node *next;

  Node(int x)
  {
    data = x;
    next = nullptr;
  }
};

int intersectPoint(Node* head1, Node* head2)
{
    Node* itr1 = head1;
    Node* itr2 = head2;
    
    int count1 = 0;
    while(itr1 != nullptr)
    {
        count1 += 1;
        itr1 = itr1->next;
    }
    
    int count2 = 0;
    while(itr2 != nullptr)
    {
        count2 += 1;
        itr2 = itr2->next;
    }
    
    if(count1 < count2)
    {
        swap(head1, head2);
    }
    
    itr1 = head1;
    itr2 = head2;
    
    int dif = abs(count1 - count2);
    while(dif--)
    {
        itr1 = itr1->next;
    }
    
    while( (itr1 != nullptr) && (itr2 != nullptr) )
    {   
        if(itr1 == itr2)
        {
            return itr1->data;
        }
        
        itr1 = itr1->next;
        itr2 = itr2->next;
    }
    
    return -1;
}
