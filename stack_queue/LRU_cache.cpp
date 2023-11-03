// Design a data structure that works like a LRU Cache. Here cap denotes the capacity of the
// cache and Q denotes the number of queries. Query can be of two types:
//     SET x y: sets the value of the key x with value y
//     GET x: gets the key of x if present else returns -1.

// The LRUCache class has two methods get() and set() which are defined as follows.
//     get(key): returns the value of the key if it already exists in the cache otherwise
//     returns -1.
//     set(key, value): if the key is already present, update its value. If not present, add
//     the key-value pair to the cache. If the cache reaches its capacity it should
//     invalidate the least recently used item before inserting the new item.
//     In the constructor of the class the capacity of the cache should be initialized.

// Example:
// Input:  cap = 2, Q = 2
//         Queries = SET 1 2 GET 1
// Output: 2

#include <bits/stdc++.h>
using namespace std;

class LRUCache
{
public:
    class node
    {
    public:
        int key;
        int val;
        node *next;
        node *prev;
        node(int _key, int _val)
        {
            key = _key;
            val = _val;
        }
    };

    node *head = new node(-1, -1);
    node *tail = new node(-1, -1);

    int cap;
    unordered_map<int, node *> m;

    LRUCache(int capacity)
    {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addnode(node *newnode)
    {
        node *temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }

    void deletenode(node *delnode)
    {
        node *delprev = delnode->prev;
        node *delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }

    int GET(int key_)
    {
        if (m.find(key_) != m.end())
        {
            node *resnode = m[key_];
            int res = resnode->val;
            m.erase(key_);
            deletenode(resnode);
            addnode(resnode);
            m[key_] = head->next;
            return res;
        }

        return -1;
    }

    void SET(int key_, int value)
    {
        if (m.find(key_) != m.end())
        {
            node *existingnode = m[key_];
            m.erase(key_);
            deletenode(existingnode);
        }
        if (m.size() == cap)
        {
            m.erase(tail->prev->key);
            deletenode(tail->prev);
        }

        addnode(new node(key_, value));
        m[key_] = head->next;
    }
};
