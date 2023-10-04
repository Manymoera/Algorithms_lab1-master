#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>
#include <fstream>
#include "Pointer_3_heap.h"
#include "QuickSorts.h"
using namespace std;
using namespace std::chrono;

void MakePseudoRandomSorted_3_Heap_Array(int size, ofstream& _file)
{
    srand(time(NULL));

    DHeap heap_rand_sort;

    vector<int64_t> vec;

    cout << "\n";

    cout << "Making unsorted random array of " << size << " elements" << "\n";

    for (int i = 0; i < size; i++)
    {
        vec.push_back(rand() % 1'000'000'000);
    }

    heap_rand_sort.heapify(vec);
    cout << "Made an array" << "\n";

    auto start = high_resolution_clock::now();

    heap_rand_sort.sort();
    cout << "Array sorted";

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(stop - start);
    _file << "Time taken to sort an array of " << size << " elements: " << duration.count() << " milliseconds" << "\n";

    cout << "\n";
}

void MakeSortedIncreasingArray_3_Heap(int size, ofstream& _file)
{
    DHeap heap_inc_sort;

    vector<int64_t> vec;

    cout << "\n";
    cout << "Making increasing array of " << size << " elements" << "\n";

    for (int i = 0; i < size; i++)
    {
        vec.push_back(i);
    }

    heap_inc_sort.heapify(vec);
    cout << "Made an array" << "\n";

    auto start = high_resolution_clock::now();

    heap_inc_sort.sort();
    cout << "Array sorted";

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(stop - start);
    _file << "Time taken to sort an array of " << size << " elements: " << duration.count() << " milliseconds" << "\n";

    cout << "\n";
}

void MakeSortedDecreasingArray_3_Heap(int size, ofstream& _file)
{
    DHeap heap_inc_sort;

    vector<int64_t> vec;

    cout << "\n";
    cout << "Making increasing array of " << size << " elements" << "\n";

    for (int i = 0; i < size; i++)
    {
        vec.push_back(size - i);
    }

    heap_inc_sort.heapify(vec);
    cout << "Made an array" << "\n";

    auto start = high_resolution_clock::now();

    heap_inc_sort.sort();
    cout << "Array sorted";

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(stop - start);
    _file << "Time taken to sort an array of " << size << " elements: " << duration.count() << " milliseconds" << "\n";

    cout << "\n";
}

void MakePseudoRandomSortedQuickArray(int size, ofstream& _file)
{
    srand(time(NULL));

    vector<int64_t> vec;

    cout << "\n";
    cout << "Making unsorted random array of " << size << " elements" << "\n";

    for (int i = 0; i < size; i++)
    {
        vec.push_back(rand() % 1'000'000'000);
    }
    cout << "Made an array" << "\n";

    auto start = high_resolution_clock::now();

    QuickSort(vec, 0, vec.size() - 1);
    cout << "Array sorted";

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(stop - start);
    _file << "Time taken to sort an array of " << size << " elements: " << duration.count() << " milliseconds" << "\n";

    cout << "\n";
}

void MakeSortedIncreasingQuickArray(int size, ofstream& _file)
{
    vector<int64_t> vec;

    cout << "\n";
    cout << "Making increasing array of " << size << " elements" << "\n";

    for (int i = 0; i < size; i++)
    {
        vec.push_back(i);
    }

    cout << "Made an array" << "\n";

    auto start = high_resolution_clock::now();

    QuickSort(vec, 0, vec.size() - 1);
    cout << "Array sorted";

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(stop - start);
    _file << "Time taken to sort an array of " << size << " elements: " << duration.count() << " milliseconds" << "\n";

    cout << "\n";
}

void MakeSortedDecreasingQuickArray(int size, ofstream& _file)
{
    vector<int64_t> vec;

    cout << "\n";
    cout << "Making decreasing array of " << size << " elements" << "\n";

    for (int i = 0; i < size; i++)
    {
        vec.push_back(size - i);
    }

    cout << "Made an array" << "\n";

    auto start = high_resolution_clock::now();

    QuickSort(vec, 0, vec.size() - 1);
    cout << "Array sorted";

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(stop - start);
    _file << "Time taken to sort an array of " << size << " elements: " << duration.count() << " milliseconds" << "\n";

    cout << "\n";
}

void SortTestFirstCase(ofstream& file)
{
    cout << "\n";

    //-----------------------------3-Heap Sorts-----------------------------//

    file << "First Case: " << "\n\n\n";
    file << "Time measurments for 3-heap sorting a pseudo random array with numbers which have a maximum value of 10^9" << "\n";
    for (int64_t i = 1; i <= 1'000'001; i += 10'000)
    {
        MakePseudoRandomSorted_3_Heap_Array(i, file);
    }
    file << "\n\n";
    file << "Time measurments for 3-heap sorting an increasing array with numbers which have a maximum value of 10^9" << "\n";
    for (int64_t i = 1; i <= 1'000'001; i += 10'000)
    {
        MakeSortedIncreasingArray_3_Heap(i, file);
    }
    file << "\n\n";
    file << "Time measurments for 3-heap sorting a decreasing array with numbers which have a maximum value of 10^9" << "\n";
    for (int64_t i = 1; i <= 1'000'001; i += 10'000)
    {
        MakeSortedDecreasingArray_3_Heap(i, file);
    }

    //-------------------------Quick Sorts-------------------------//

    file << "\n\n";
    file << "Time measurments for quick sorting a pseudo random array with numbers which have a maximum value of 10^9" << "\n";
    for (int64_t i = 1; i <= 1'000'001; i += 10'000)
    {
        MakePseudoRandomSortedQuickArray(i, file);
    }
    file << "\n\n";
    file << "Time measurments for quick sorting an increasing array with numbers which have a maximum value of 10^9" << "\n";
    for (int64_t i = 1; i <= 1'000'001; i += 10'000)
    {
        MakeSortedIncreasingQuickArray(i, file);
    }
    file << "\n\n";
    file << "Time measurments for quick sorting a decreasing array with numbers which have a maximum value of 10^9" << "\n";
    for (int64_t i = 1; i <= 1'000'001; i += 10'000)
    {
        MakeSortedDecreasingQuickArray(i, file);
    }
}