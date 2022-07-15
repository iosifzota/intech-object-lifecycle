#ifndef __BOX_H__
#define __BOX_H__

#include <cmath>
#include <iostream>

using namespace std;

class Box
{
    unsigned int m_len;

    static unsigned int s_nbObjectsCreated;

public:
    Box() : m_len{}
    {
        s_nbObjectsCreated++;
    }

    void setLen(int newLen)
    {
        m_len = newLen;
    }

    unsigned int getVolume() const
    {
        return (unsigned int)pow(m_len, 3);
    }

    static unsigned int getNbObjectsCreated()
    {
        return s_nbObjectsCreated;
    }
};

unsigned int Box::s_nbObjectsCreated = 0;

void testBox()
{
    Box b1;
    b1.setLen(3);

    Box b2;
    b2.setLen(5);

    cout << b1.getVolume() << std::endl;
    cout << b2.getVolume() << std::endl;
    cout << "Total number of objects: " << b2.getNbObjectsCreated() << std::endl;
}


#endif // __BOX_H__