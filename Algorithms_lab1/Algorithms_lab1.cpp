#include <fstream>
#include "Pointer_3_heap.h"
#include "ArrayTests.h"
#include "QuickSorts.h"
#include "SecondCaseTest.h"
using namespace std;

int main()
{
    ofstream file;
    ofstream fileSecond;
    file.open("MeasurmentsFirstCase.txt", ofstream::out | ofstream::trunc);
    SortTestFirstCase(file);
    file.close();
    fileSecond.open("MeasurmentsSecondCase.txt", ofstream::out | ofstream::trunc);
    SortTestSecondCase(fileSecond);
    fileSecond.close();
}