#ifndef __OUTPUTSTREAM_H__
#define __OUTPUTSTREAM_H__

#include <mutex>
#include <iostream>

using namespace std;

class OutputStream
{
    mutex m_mutex;

public:

    ostream& setupOutputStream()
    {
        m_mutex.lock();

        return cout;
    }

    void closeOutputStream()
    {
        m_mutex.unlock();
    }
};

OutputStream sg_outputStream;

ostream &getOutputStream()
{
    return sg_outputStream.setupOutputStream();
}

void closeOutputStreamSpecial()
{
    sg_outputStream.closeOutputStream();
}


#endif // __OUTPUTSTREAM_H__