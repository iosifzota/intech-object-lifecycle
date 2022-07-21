#ifndef __RULEOFTHREECORRECT_H__
#define __RULEOFTHREECORRECT_H__

#include <utility>
#include <iostream>

using namespace std;

class Class3
{
    int *m_p;

public:
    Class3(int val) : m_p(new int(val))
    {
        // empty
    }

    Class3(const Class3 &other) : m_p(new int(*(other.m_p))) // Replace with: other->m_p --> Knowledge check: Is the right side of the assignment correct?
    {
        // empty
    }

    Class3 &operator=(const Class3 &other)
    {
        Class3 tmp(other);
        swap(*this, tmp);
        return *this;
    }

    ~Class3()
    {
        if (nullptr != m_p)
        {
            delete m_p;
            m_p = nullptr;
        }
    }

    int getVal() const
    {
        return *m_p;
    }

    void setVal(int newVal)
    {
        *m_p = newVal;
    }

    void print()
    {
        if (nullptr != m_p)
        {
            cout << *(m_p);
        }
        else
        {
            cout << "cannot access nullptr";
        }
    }
};

void testRuleOfThreeCorrect()
{
    Class3 mc(3);
    cout << "mc: ";
    mc.print();
    cout << endl;

    Class3 mccopy = mc;
    cout << "mccopy: ";
    mccopy.print();
    cout << endl;

    mccopy.setVal(4);
    cout << "== Modified mccopy ==\n";
    cout << "mc: ";
    mc.print();
    cout << endl;
    cout << "mccopy: ";
    mccopy.print();
    cout << endl;
}

#endif // __RULEOFTHREECORRECT_H__