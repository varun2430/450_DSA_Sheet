#include <bits/stdc++.h>
using namespace std;

void swap(int *x, int *y);

class MinHeap
{
private:
    int *h_arr;
    int max_size;
    int heap_size;

    // return the parent of the ith element
    int parent(int i)
    {
        return (i - 1) / 2;
    }

    // return the left child of the ith element
    int left(int i)
    {
        return (2 * i + 1);
    }

    // return the right child of the ith element
    int right(int i)
    {
        return (2 * i + 2);
    }

public:
    MinHeap(int size)
    {
        h_arr = new int[size];
        max_size = size;
        heap_size = 0;
    }

    int get_min()
    {
        if (heap_size > 0)
        {
            return h_arr[0];
        }

        return INT_MAX;
    }

    void push(int x)
    {
        if (heap_size == max_size)
        {
            cout << "Heap Overflow!" << endl;
            return;
        }

        heap_size += 1;
        int i = heap_size - 1;
        h_arr[i] = x;

        while ((i != 0) && (h_arr[parent(i)] > h_arr[i]))
        {
            swap(&h_arr[parent(i)], &h_arr[i]);
            i = parent(i);
        }
    }

    int pop()
    {
        if (heap_size <= 0)
        {
            return INT_MAX;
        }

        if (heap_size == 1)
        {
            heap_size -= 1;
            return h_arr[0];
        }

        int root = h_arr[0];
        h_arr[0] = h_arr[heap_size - 1];
        heap_size -= 1;
        min_heapify(0);

        return root;
    }

    void min_heapify(int i)
    {
        int l = left(i);
        int r = right(i);
        int min_so_far = i;

        if ((l < heap_size) && (h_arr[l] < h_arr[i]))
        {
            min_so_far = l;
        }

        if ((r < heap_size) && (h_arr[r]) < h_arr[min_so_far])
        {
            min_so_far = r;
        }

        if (min_so_far != i)
        {
            swap(&h_arr[i], &h_arr[min_so_far]);
            min_heapify(min_so_far);
        }
    }
};

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

/* MAX HEAP */

void max_heapify(int i, int n, int arr[])
{
    int max_so_far = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if ((left < n) && (arr[left] > arr[max_so_far]))
    {
        max_so_far = left;
    }

    if ((right < n) && (arr[right] > arr[max_so_far]))
    {
        max_so_far = right;
    }

    if (max_so_far != i)
    {
        swap(arr[i], arr[max_so_far]);
        max_heapify(max_so_far, n, arr);
    }
}

void build_max_heap(int n, int arr[])
{
    // index of last non leaf node
    int idx = (n / 2) - 1;

    for (int i = idx; i > -1; i--)
    {
        max_heapify(i, n, arr);
    }
}
