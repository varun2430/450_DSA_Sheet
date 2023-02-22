#include<iostream>
using namespace std;

class TwoStack
{
    int size;
    int* arr;
    int top1, top2;

    public:
    TwoStack(int s)
    {
        size = s;
        arr = new int[s];
        top1 = -1;
        top2 = s;
    }

    void push1(int x)
    {
        if(top1 < top2 - 1)
        {
            top1++;
            arr[top1] = x;
        }
    }

    void push2(int x)
    {
        if(top1 < top2 - 1)
        {
            top2--;
            arr[top2] = x;
        }
    }

    int pop1()
    {
        if(top1 > -1)
        {
            int popped = arr[top1];
            top1--;
            return popped;
        }
        else
        {
            return INT_MIN;
        }
    }

    int pop2()
    {
        if(top2 < size)
        {
            int popped = arr[top2];
            top2++;
            return popped;
        }
        else
        {
            return INT_MIN;
        }
    }

};
