#include <iostream>
#include <utility>

using namespace std;

struct SwapableClass
{
    int m_val;
    SwapableClass(int val) : m_val{val}
    {
        // empty
    }

    SwapableClass(const SwapableClass& other) : m_val{other.m_val}
    {
        // empty
    }

    SwapableClass& operator=(const SwapableClass& other)
    {
        SwapableClass tmp{other};
        swap(*this, tmp); // using the swap from STL
        // How about implementing our own swap?
        return *this;
    }

    int getVal() const
    {
        return m_val;
    }
};

int main()
{
    SwapableClass c1(3), c2(4);

    cout << "== Before copy ==\n";
    cout << "c1: " << c1.getVal() << endl;
    cout << "c2: " << c2.getVal() << endl;

    // Will the assignment below work?
    // Run the code to see what happens.
    c1 = c2;

    cout << "== After copy ==\n";
    cout << "c1: " << c1.getVal() << endl;
    cout << "c2: " << c2.getVal() << endl;

    return 0;
}