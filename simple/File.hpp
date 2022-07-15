#ifndef __FILE_H__
#define __FILE_H__

#include <string>
#include <mutex>
#include <fstream>

using namespace std;

class File
{
    const string m_fileName;
    fstream m_stream;
    mutex m_mutex;

public:
    File(const string& fileName) : m_fileName{fileName}
    {
        // empty
    }

    void cleanupStream()
    {
        m_stream.flush();
        m_stream.close();
        m_stream.clear();
    }

    fstream& setupFileStream()
    {
        // Make sure this file stream is unique.
        m_mutex.lock();
        m_stream.open(m_fileName, std::ios::app);
        return m_stream;
    }

    void closeFileStream()
    {
        cleanupStream();
        m_mutex.unlock();
    }

    const string &getFileName() const
    {
        return m_fileName;
    }
    // How to make the File objects unique using 'delete' keyword?
};

File * createFile(const string& fileName)
{
    return new File(fileName);
}
#endif // __FILE_H__