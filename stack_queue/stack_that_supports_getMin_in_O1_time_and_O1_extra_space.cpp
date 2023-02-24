#include <iostream>
#include <stack>
using namespace std;

// How (2*x – minEle) is less than x in push()? 
// ( x < minEle ) which means ( x – minEle < 0 )
//
// Adding x on both sides
// x – minEle + x < 0 + x 
// 2*x – minEle < x 
// We can conclude 2*x – minEle < new minEle

// How previous minimum element, prevMinEle is, 2*minEle – y
// in pop() is y the popped element?

// We pushed y as 2x – prevMinEle
// Here prevMinEle is minEle before y was inserted
//
// y = 2*x – prevMinEle  
//
// Value of minEle was made equal to x
// minEle = x .
//
// new minEle = 2 * minEle – y 
//            = 2*x – (2*x – prevMinEle)
//            = prevMinEle

stack<int> s;
int minEle = INT_MAX;

int getMin()
{
    if (s.empty())
    {
        return -1;
    }

    return minEle;
}

int pop()
{
    if (s.empty())
    {
        return -1;
    }

    int topEle = s.top();
    s.pop();

    if (topEle < minEle)
    {
        int minVal = minEle;
        minEle = 2 * minEle - topEle;
        return minVal;
    }
    else
    {
        return topEle;
    }
}

void push(int x)
{
    if (s.empty())
    {
        s.push(x);
        minEle = x;
        return;
    }

    if (x < minEle)
    {
        s.push(2 * x - minEle);
        minEle = x;
    }
    else
    {
        s.push(x);
    }
}
