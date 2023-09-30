#include <fstream>
#include "Pointer_3_heap.h"
#include "ArrayTests.h"
#include "ArrayTestsSecondCase.h";
using namespace std;

int main()
{
    ofstream file;
    file.open("MeasurmentsFirstCase.txt", ofstream::out | ofstream::trunc);
    SortTestFirstCase(file);
    file.close();
}