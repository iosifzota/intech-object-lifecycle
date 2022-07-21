#ifndef __SMARTPTR_H__
#define __SMARTPTR_H__

#include <iostream>
#include "Point3D.hpp"

using namespace std;

class UniquePtr
{
    Point3D *m_ptr;

public:

    UniquePtr() : m_ptr{nullptr}
    {
        // empty
    }

    UniquePtr(Point3D *ptr) : m_ptr{ptr}
    {
        // empty
    }

    UniquePtr(const UniquePtr &) = delete;
    UniquePtr &operator=(const UniquePtr &) = delete;
    UniquePtr(UniquePtr &&) = delete;
    UniquePtr &operator=(UniquePtr &&) = delete;

    ~UniquePtr()
    {
        if (nullptr != m_ptr)
        {
            delete m_ptr;
            m_ptr = nullptr;
            cout << "Memory released.\n";
        }
    }

    Point3D &operator*()
    {
        if (nullptr != m_ptr)
        {
            return *m_ptr;
        }
        throw logic_error("Attempt to dereference nullptr.");
    }

    Point3D *operator->()
    {
        if (nullptr != m_ptr)
        {
            return m_ptr;
        }

        throw logic_error("Attempt to dereference nullptr.");
    }

    Point3D *get() const
    {
        return m_ptr;
    }

    void set(Point3D * ptr)
    {
        if (nullptr == ptr)
        {
            m_ptr = ptr;
        }
        throw logic_error("Error: Dangling pointer.");
    }

    void unsafeOverwrite(Point3D *ptr)
    {
        m_ptr = ptr;
    }

    bool isNull() const
    {
        return nullptr == m_ptr;
    }
};



#endif // __SMARTPTR_H__