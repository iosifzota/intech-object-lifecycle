#include <iostream>
#include "Shapes.hpp"
#include "PrintBits.hpp"

using namespace std;

void testInMemory()
{
    Square square(3, 4, 9);

    printBits(cout, square);

    cout << "sizeof(Square)     = " << (int)sizeof(square) << endl;
    cout << "sizeof(Square.len) = " << (int)sizeof(square.getLen()) << endl;
}

void testBasic()
{
    Square square(1, 1, 2);

    // Call of Square function
    cout << "Len: " << square.getLen() << endl;

    // Call of base function.
    cout << "x, y = " << square.getX() << ", " << square.getY() << endl;
}

int main()
{
    // testBasic();
    // testInMemory();

    return 0;
}