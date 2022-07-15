#ifndef __SMARTPTR_H__
#define __SMARTPTR_H__

#include <iostream>

using namespace std;

template<typename T>
class UniquePtr
{
    T *m_ptr;

public:

    UniquePtr() : m_ptr{nullptr}
    {
        // empty
    }

    UniquePtr(T *ptr) : m_ptr{ptr}
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

    T &operator*()
    {
        if (nullptr != m_ptr)
        {
            return *m_ptr;
        }
        throw logic_error("Attempt to dereference nullptr.");
    }

    T *operator->()
    {
        if (nullptr != m_ptr)
        {
            return m_ptr;
        }

        throw logic_error("Attempt to dereference nullptr.");
    }

    T *get() const
    {
        return m_ptr;
    }

    void set(T * ptr)
    {
        if (nullptr == ptr)
        {
            m_ptr = ptr;
        }
        throw logic_error("Error: Dangling pointer.");
    }

    void unsafeOverwrite(T *ptr)
    {
        m_ptr = ptr;
    }

    bool isNull() const
    {
        return nullptr == m_ptr;
    }
};



#endif // __SMARTPTR_H__