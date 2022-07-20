#include <iostream>

#include "UniquePtr.hpp"
#include "MemoryTracking.hpp"

using namespace std;

void doSomeProcessingNoLeaks()
{
    // Allocate a Point3D object on the heap but give it to UniquePtr

    // memory is freed
}


void doSomeProcessingWithLeaks()
{
    // allocate a Pointe3D object on the heap
    
    // intentionally forgot to free memory
    // memory is leaked
}

void testdoSomeProcessingWithLeaks()
{
    cout << "== Before doSomeProcessingWithLeaks() ==\n";
    printMemoryUsage();
    doSomeProcessingWithLeaks();
    cout << "== After doSomeProcessingWithLeaks() ==\n";
    printMemoryUsage();
}

void testdoSomeProcessingNoLeaks()
{
    cout << "== Before doSomeProcessingNoLeaks() ==\n";
    printMemoryUsage();
    doSomeProcessingNoLeaks();
    cout << "== After doSomeProcessingNoLeaks() ==\n";
    printMemoryUsage();
}


void testRaii()
{
    // testdoSomeProcessingWithLeaks();
    testdoSomeProcessingNoLeaks();
}

int main()
{
    testRaii();
    printStatus();
    return 0;
}