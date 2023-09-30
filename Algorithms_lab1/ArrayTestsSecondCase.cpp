#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>
#include <fstream>
#include "Pointer_3_heap.h"
#include "QuickSorts.h"
using namespace std;
using namespace std::chrono;

void MakePseudoRandom_3_HeapArray(int i, ofstream& _file)
{
	srand(time(NULL));

	DHeap heap_rand_sort;

	int64_t* rand_arr;
	rand_arr = new int64_t[1'000'000];

	for (int i = 0; i < 1'000'000; i++)
	{
		rand_arr[i] = rand() % i;
	}

	heap_rand_sort.heapify(rand_arr, 1'000'000);
	cout << "Made an array" << "\n";

	auto start = high_resolution_clock::now();

	heap_rand_sort.sort();
	cout << "Array sorted";

	auto stop = high_resolution_clock::now();

	auto duration = duration_cast<milliseconds>(stop - start);
	_file << "Time taken to sort an array of " << size << " elements: " << duration.count() << " milliseconds" << "\n";

	cout << "\n";
}


void SortTestSecondCase(ofstream& file)
{
	file << "Second case: " << "\n\n\n";
	file << "Time measurments for 3-Heap sorting a pseudo random array with numbers which have a various max value" << "\n";
	for (int i = 1; i <= 100; i++)
	{
		MakePseudoRandom_3_HeapArray(i, file);
	}
}