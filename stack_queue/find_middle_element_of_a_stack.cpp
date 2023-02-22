#include<iostream>
using namespace std;

class StackNode
{
    public:
    int data;
    StackNode* next;
    StackNode* prev;

    StackNode(int x)
    {
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};

class Stack
{
    StackNode* head = nullptr;
    StackNode* mid = nullptr;
    int size = 0;

    public:
    void push(int x)
    {
        StackNode* new_node = new StackNode(x);

        if(size == 0)
        {
            head = new_node;
            mid = new_node;
            size++;
            return;
        }

        head->next = new_node;
        new_node->prev = head;
        head = head->next;

        if(size%2 == 1)
        {
            mid = mid->next;
        }
        size++;
    }

    int pop()
    {
        int popped = -1;

        if(size != 0)
        {
            StackNode* toPop = head;
            popped = toPop->data;

            if(size == 1)
            {
                head == nullptr;
                mid == nullptr;
            }
            else
            {
                head = head->prev;
                head->next = nullptr;

                if(size%2 == 0)
                {
                    mid = mid->prev;
                }
            }

            delete toPop;
            size--;
        }

        return popped;
    }

    int middle()
    {
        if(size == 0)
        {
            return -1;
        }

        return mid->data;
    }

    void deleteMiddle()
    {
        if(size != 0)
        {
            StackNode* toDelete = mid;

            if(size == 1)
            {
                head = nullptr;
                mid = nullptr;
            }
            else if(size == 2)
            {
                head = head->prev;
                mid = mid->prev;
                head->next = nullptr;
            }
            else
            {
                (mid->next)->prev = mid->prev;
                (mid->prev)->next = mid->next;

                if(size%2 == 0)
                {
                    mid = mid->prev;
                }
                else
                {
                    mid = mid->next;
                }
            }

            delete toDelete;
            size--;
        }
    }
};

int main()
{
    Stack st;
    st.push(11);
    st.push(22);
    st.push(33);
    st.push(44);
    st.push(55);
    st.push(66);
    st.push(77);
    st.push(88);
    st.push(99);

    st.pop();
    st.pop();

    cout << st.middle() << endl;

    st.deleteMiddle();
    
    cout << st.middle() << endl;
}
