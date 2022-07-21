#include <iostream>
#include <exception>

using namespace std;

class MovableClass
{
    int *m_p;

public:
    MovableClass(int val) : m_p(new int(val))
    {
        // empty
    }

    MovableClass(const MovableClass &other) : m_p(new int(*(other.m_p))) // Replace with: other->m_p --> Knowledge check: Is the right side of the assignment correct?
    {
        // empty
    }

    MovableClass &operator=(const MovableClass &other)
    {
        cleanup();
        MovableClass tmp(other);
        std::swap(*this, tmp);
        return *this;
    }

    MovableClass(MovableClass &&other) : m_p(other.m_p)
    {
        other.m_p = nullptr;
    }

    MovableClass &operator=(MovableClass &&other)
    {
        cleanup(); // cleanup is optional, it's a bad practice to use the moved-from object again.
        MovableClass tmp(std::move(other));
        std::swap(*this, tmp);
        return *this;
    }

    ~MovableClass()
    {
        cleanup();
    }

    void cleanup()
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

    friend std::ostream &operator<<(std::ostream &out, const MovableClass &mc);
};

std::ostream &operator<<(std::ostream &out, const MovableClass &mc)
{
    if (nullptr != mc.m_p)
    {
        return out << *(mc.m_p);
    }
    return out << "cannot access nullptr";
}

int main()
{
    MovableClass mc(3);
    cout << "mc: " << mc << std::endl;

    MovableClass mccopy = mc;
    cout << "mccopy: " << mccopy << std::endl;

    mccopy.setVal(4);
    cout << "== Modified mccopy ==\n";
    cout << "mc: " << mc << std::endl;
    cout << "mccopy: " << mccopy << std::endl;

    MovableClass mcmoved = std::move(mc);
    cout << "== Moved mc ==\n";
    cout << "mc: " << mc << std::endl;
    cout << "mcmoved: " << mcmoved << std::endl;

    return 0;
}