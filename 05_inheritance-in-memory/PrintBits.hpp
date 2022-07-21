#ifndef __PRINTBITS_H__
#define __PRINTBITS_H__

#include <ostream>
#include "Shapes.hpp"

using namespace std;

ostream &printBits(ostream &out, const Square &type)
{
    const char *ptr = nullptr;

    {
        const Square *tmpPtr = &type;
        ptr = (const char *)tmpPtr;
    }

    // Switch to hex mode
    out << hex;

    for (unsigned int i = 0; i < sizeof(Square); ++i)
    {
        out << (int)ptr[i] << " ";
    }
    out << endl;

    // Back to decimal mode
    out << dec;
    return out;
}

#endif // __PRINTBITS_H__