#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>
#include <fstream>
#include "Pointer_3_heap.h"
#include "QuickSorts.h"
using namespace std;
using namespace std::chrono;

void MakePseudoRandomSorted_3_Heap_ArraySecond(int h_border, ofstream& _file)
{
    srand(time(NULL));

    DHeap heap_rand_sort;

    vector<int64_t> vec;

    cout << "\n";

    cout << "Making unsorted random array which have a max value of " << h_border << "\n";

    for (int i = 0; i < 1'000'000; i++)
    {
        vec.push_back(rand() % h_border);
    }

    heap_rand_sort.heapify(vec);
    cout << "Made an array" << "\n";

    auto start = high_resolution_clock::now();

    heap_rand_sort.sort();
    cout << "Array sorted";

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(stop - start);
    _file << "Time taken to sort a random array with a max value of " <<h_border<< ": " << duration.count() << " milliseconds" << "\n";

    cout << "\n";
}

void MakeSortedIncreasingArray_3_HeapSecond(int h_border, ofstream& _file)
{
    srand(time(NULL));

    DHeap heap_rand_sort;

    vector<int64_t> vec;

    cout << "\n";

    cout << "Making increasing random array which have a max value of " << h_border << "\n";

    for (int i = 0; i < 1'000'000; i++)
    {
        vec.push_back(rand() % h_border);
    }

    sort(vec.begin(), vec.end());

    heap_rand_sort.heapify(vec);
    cout << "Made an array" << "\n";

    auto start = high_resolution_clock::now();

    heap_rand_sort.sort();
    cout << "Array sorted";

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(stop - start);
    _file << "Time taken to sort an increasing array with a max value of " << h_border << ": " << duration.count() << " milliseconds" << "\n";

    cout << "\n";
}

void MakeSortedDecreasingArray_3_HeapSecond(int h_border, ofstream& _file)
{
    srand(time(NULL));

    DHeap heap_rand_sort;

    vector<int64_t> vec;

    cout << "\n";

    cout << "Making decreasing random array which have a max value of " << h_border << "\n";

    for (int i = 0; i < 1'000'000; i++)
    {
        vec.push_back(rand() % h_border);
    }

    sort(vec.begin(), vec.end(), greater<int>());

    heap_rand_sort.heapify(vec);
    cout << "Made an array" << "\n";

    auto start = high_resolution_clock::now();

    heap_rand_sort.sort();
    cout << "Array sorted";

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(stop - start);
    _file << "Time taken to sort a decreasing array with a max value of " << h_border << ": " << duration.count() << " milliseconds" << "\n";

    cout << "\n";
}

void MakePseudoRandomSortedQuickArraySecond(int h_border, ofstream& _file)
{
    srand(time(NULL));

    vector<int64_t> vec;

    cout << "\n";
    cout << "Making unsorted random array which have a max value of " << h_border << "\n";

    for (int i = 0; i < 1'000'000; i++)
    {
        vec.push_back(rand() % h_border);
    }
    cout << "Made an array" << "\n";

    auto start = high_resolution_clock::now();

    QuickSort(vec, 0, vec.size() - 1);
    cout << "Array sorted";

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(stop - start);
    _file << "Time taken to sort a random array with a max value of " << h_border << ": " << duration.count() << " milliseconds" << "\n";

    cout << "\n";
}

void MakeSortedIncreasingQuickArraySecond(int h_border, ofstream& _file)
{
    srand(time(NULL));

    vector<int64_t> vec;

    cout << "\n";
    cout << "Making increasing random array which have a max value of " << h_border << "\n";

    for (int i = 0; i < 1'000'000; i++)
    {
        vec.push_back(rand() % h_border);
    }
    sort(vec.begin(), vec.end());
    cout << "Made an array" << "\n";

    auto start = high_resolution_clock::now();

    QuickSort(vec, 0, vec.size() - 1);
    cout << "Array sorted";

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(stop - start);
    _file << "Time taken to sort an increasing array with a max value of " << h_border << ": " << duration.count() << " milliseconds" << "\n";

    cout << "\n";
}

void MakeSortedDecreasingQuickArraySecond(int h_border, ofstream& _file)
{
    srand(time(NULL));

    vector<int64_t> vec;

    cout << "\n";
    cout << "Making decreasing random array which have a max value of " << h_border << "\n";

    for (int i = 0; i < 1'000'000; i++)
    {
        vec.push_back(rand() % h_border);
    }
    sort(vec.begin(), vec.end(), greater<int>());
    cout << "Made an array" << "\n";

    auto start = high_resolution_clock::now();

    QuickSort(vec, 0, vec.size() - 1);
    cout << "Array sorted";

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(stop - start);
    _file << "Time taken to sort a decreasing array with a max value of " << h_border << ": " << duration.count() << " milliseconds" << "\n";

    cout << "\n";
}

void SortTestSecondCase(ofstream& file)
{
    cout << "\n";

    //-----------------------------3-Heap Sorts-----------------------------//

    file << "Second Case: " << "\n\n\n";
    file << "Time measurments for 3-heap sorting a pseudo random array with a variable high border of values" << "\n";
    for (int i = 1; i <= 100; ++i)
    {
        MakePseudoRandomSorted_3_Heap_ArraySecond(i, file);
    }
    file << "\n\n";
    file << "Time measurments for 3-heap sorting an increasing array with a variable high border of values" << "\n";
    for (int i = 1; i <= 100; ++i)
    {
        MakeSortedIncreasingArray_3_HeapSecond(i, file);
    }
    file << "\n\n";
    file << "Time measurments for 3-heap sorting a decreasing array with a variable high border of values" << "\n";
    for (int i = 1; i <= 100; ++i)
    {
        MakeSortedDecreasingArray_3_HeapSecond(i, file);
    }

    //-------------------------Quick Sorts-------------------------//

    file << "\n\n";
    file << "Time measurments for quick sorting a pseudo random array with a variable high border of values" << "\n";
    for (int i = 1; i <= 100; ++i)
    {
        MakePseudoRandomSortedQuickArraySecond(i, file);
    }
    file << "\n\n";
    file << "Time measurments for quick sorting an increasing array with a variable high border of values" << "\n";
    for (int i = 1; i <= 100; ++i)
    {
        MakeSortedIncreasingQuickArraySecond(i, file);
    }
    file << "\n\n";
    file << "Time measurments for quick sorting a decreasing array with a variable high border of values" << "\n";
    for (int i = 1; i <= 100; ++i)
    {
        MakeSortedDecreasingQuickArraySecond(i, file);
    }
}