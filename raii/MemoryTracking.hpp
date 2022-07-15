#ifndef __MEMORYTRACKING_H__
#define __MEMORYTRACKING_H__

#include <cstdint>
#include <iostream>

using namespace std;

struct AllocationMatrix
{
    uint32_t totalAllocated = 0;
    uint32_t totalFreed = 0;

    uint32_t getUsage() const
    {
        return totalAllocated - totalFreed;
    }
};

static AllocationMatrix sg_allocationMatrix;


void *operator new(size_t size)
{
    sg_allocationMatrix.totalAllocated += size;
    return malloc(size);
}

void operator delete(void* mem, size_t size)
{
    sg_allocationMatrix.totalFreed += size;
    free(mem);
}

bool isMemoryLeaked()
{
    return  0 != sg_allocationMatrix.getUsage();
}

void printStatus()
{
    if (isMemoryLeaked())
    {
        cout << "[Error] Memory was leaked.\n";
    }
    else
    {
        cout << "[OK] All memory freed.\n";
    }
}

void printMemoryUsage()
{
    cout << "Total memory in use: " << sg_allocationMatrix.getUsage() << std::endl;
}

#endif // __MEMORYTRACKING_H__