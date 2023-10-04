#pragma once
#include <iostream>
#include <vector>
using namespace std;

class DHeap
{
private:
    int d = 3;
    vector<int64_t> heap;
public:
    void heapify(vector<int64_t> _heap)
    {
        heap.clear();
        while (!_heap.empty())
        {
            insert(_heap.back());
            _heap.pop_back();
        }

    }
    void insert(int value) 
    {
        heap.push_back(value);
        bubble_up(heap.size() - 1);
    }
    int bubble_up(int index)
    {
        int parent_index = (index - 1) / d;
        if (index == 0 || heap[parent_index] >= heap[index])
        {
            return index;
        }
        else
        {
            swap(heap[parent_index], heap[index]);
            return bubble_up(parent_index);
        }
    }
    void printHeap() {
        for (int i = 0; i < heap.size(); ++i)
        {
            cout << heap[i] << " ";
        }
        cout << std::endl;
    }
    int getMaxElement()
    {
        return heap[0];
    }
    void Make_3_Heap(vector<int64_t>& arr, int n, int i)
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
        for (int i = heap.size() / 2 - 1; i >= 0; i--)
            Make_3_Heap(heap, heap.size(), i);

        for (int i = heap.size() - 1; i >= 0; i--)
        {
            swap(heap[0], heap[i]);

            Make_3_Heap(heap, i, 0);
        }
    }
};