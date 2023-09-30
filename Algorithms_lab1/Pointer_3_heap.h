#pragma once
#include <iostream>
using namespace std;

class DHeap
{
private:
    int d = 3;
    int64_t* heap_pointer;
    int64_t heap_size;
public:
    void heapify(int64_t* arr_point, int64_t arr_size)
    {
        heap_size = arr_size;
        heap_pointer = new int64_t[heap_size];
        for (int i = 0; i < heap_size; i++)
        {
            heap_pointer[i] = 0;
        }
        for (int i = 0; i < heap_size; i++)
        {
            insert(arr_point[i], i);
        }
    }
    void insert(int64_t value, int i)
    {
        heap_pointer[i] = value;
        bubble_up(i);
    }
    int bubble_up(int index)
    {
        int parent_index = (index - 1) / d;
        if (index == 0 || heap_pointer[parent_index] >= heap_pointer[index])
        {
            return index;
        }
        else
        {
            swap(heap_pointer[parent_index], heap_pointer[index]);
            return bubble_up(parent_index);
        }
    }
    void printHeap() {
        for (int i = 0; i < heap_size; ++i)
        {
            cout << heap_pointer[i] << " ";
        }
        cout << std::endl;
    }
    int getMaxElement()
    {
        return heap_pointer[0];
    }
    void Make_3_Heap(int64_t* arr, int n, int i)
    {
        int root = i;

        int l = 2 * i + 1;
        int m = 2 * i + 2;
        int r = 2 * i + 3;

        if (l < n && arr[l] > arr[root])
            root = l;
        if (m < n && arr[m] > arr[root])
            root = m;
        if (r < n && arr[r] > arr[root])
            root = r;

        if (root != i)
        {
            swap(arr[i], arr[root]);
            Make_3_Heap(arr, n, root);
        }
    }
    void sort()
    {
        for (int i = heap_size / 2 - 1; i >= 0; i--)
            Make_3_Heap(heap_pointer, heap_size, i);

        for (int i = heap_size - 1; i >= 0; i--)
        {
            swap(heap_pointer[0], heap_pointer[i]);

            Make_3_Heap(heap_pointer, i, 0);
        }
    }
};