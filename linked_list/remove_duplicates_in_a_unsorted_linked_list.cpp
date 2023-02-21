#include<iostream>
#include<unordered_set>
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

Node *removeDuplicates(Node *head)
{
    if ((head == nullptr) || (head->next == nullptr))
    {
        return head;
    }

    unordered_set<int> visited;

    Node *curr = head;
    Node *prev = nullptr;

    while (curr != nullptr)
    {
        if (visited.find(curr->data) != visited.end())
        {
            prev->next = curr->next;
            delete curr;
        }
        else
        {
            visited.insert(curr->data);
            prev = curr;
        }

        curr = curr->next;
    }

    return head;
}
