#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

long long multiplyTwoLists(Node *l1, Node *l2)
{
    long long MOD = 1000000007;

    long long res = 0;

    long long n1 = 0;
    long long n2 = 0;
    while ((l1 != nullptr) || (l2 != nullptr))
    {
        if (l1 != nullptr)
        {
            n1 = ((n1 * 10) % MOD) + l1->data;
            l1 = l1->next;
        }

        if (l2 != nullptr)
        {
            n2 = ((n2 * 10) % MOD) + l2->data;
            l2 = l2->next;
        }
    }

    res = (n1 * n2) % MOD;

    return res;
}
