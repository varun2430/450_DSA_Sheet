#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    char data;
    Node *next;
    Node *pre;

    Node(int data)
    {
        this->data = data;
        pre = NULL;
        next = NULL;
    }
};

// convert doubly linked list into circular linked list
// then disconnect the link at the required node
void rotateByN(Node *&head, int pos)
{
    if (pos == 0)
        return;

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = head;
    head->pre = temp;

    int count = 1;
    while (count <= pos)
    {
        head = head->next;
        temp = temp->next;
        count++;
    }

    temp->next = NULL;
    head->pre = NULL;
}
