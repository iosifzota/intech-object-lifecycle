#include <iostream>

#include "UniquePtr.hpp"
#include "MemoryTracking.hpp"

using namespace std;

class Point3D
{
    int m_x, m_y, m_z;
public:
    Point3D(int x, int y, int z) 
        : m_x{x}, m_y{y}, m_z{z}
    {
        // empty
    }

    int getX() const
    {
        return m_x;
    }

    int getY() const
    {
        return m_y;
    }

    int getZ() const
    {
        return m_z;
    }
};

void doSomeProcessingNoLeaks()
{
    UniquePtr<Point3D> ptr{new Point3D(1,3,-1)};

    ptr->getX();
    ptr->getY();

    // memory is freed
}


void doSomeProcessingWithLeaks()
{
    Point3D *ptr = new Point3D(1,3,-1);

    ptr->getX();
    ptr->getY();
    
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