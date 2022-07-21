#ifndef __ONEEXPLICITALLOCATIONPEREXPRESSIONSTATEMENT_H__
#define __ONEEXPLICITALLOCATIONPEREXPRESSIONSTATEMENT_H__

#include <utility>
#include <iostream>
#include <memory>

using namespace std;

class Int
{
    int *m_p;

public:
    Int(int val) : m_p{new int{val}}
    {
        cout << "Int(" << val << ") called (memory allocated)\n";
    }

    Int(const Int &other) : m_p{new int{other.getVal()}}
    {
        // empty
    }

    Int &operator=(const Int &other)
    {
        cleanup();
        Int tmp(other);
        swap(*this, tmp); // Carefull the destructor is called twice for the initial *this object // This won't work if the move ctor is deleted. Advanced: Will this compile? If it compiles what would be reason for a crash when running?
        return *this;
    }

    Int(Int &&other) = default;

    Int &operator=(Int &&other) = default;

    ~Int()
    {
        cout << "Destructor called";
        cleanup();
    }

    int getVal() const
    {
        return *m_p;
    }

    void cleanup()
    {
        if (nullptr != m_p)
        {
            cout << "... for (" << *m_p << ")\n";
            delete m_p;
            m_p = nullptr;
        }
    }

    friend ostream &operator<<(ostream &out, const Int &obj);
};

ostream &operator<<(ostream &out, const Int &obj)
{
    return out << obj.getVal();
}

class Wrapper
{
    Int *m_i;
public:
    Wrapper(Int * ptr) : m_i{ptr}
    {
        cout << "Wrapper(" << ptr << ") called\n";
    }
};

void f(Wrapper&& i1, Wrapper&& i2, Wrapper&& i3)
{
    i1;
}

Wrapper&& throwException()
{
    throw logic_error("Indented exception.");
}

void testOneExplicitAllocationPerExpressionStatement()
{
    try
    {
        f(Wrapper(new Int{1}), throwException(), Wrapper(new Int{2})); // order is undefined
    }
    catch(std::logic_error err)
    {
        if (nullptr != y)
        {
            delete y;
        }
        if (nullptr != z)
        {
            delete z;
        }
        cout << err.what();
    }
}
#endif // __ONEEXPLICITALLOCATIONPEREXPRESSIONSTATEMENT_H__