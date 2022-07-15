#ifndef __LOGGER_H__
#define __LOGGER_H__

#include "FileStreamManager.hpp"

class GoodLogger
{
    fstream &m_fstream;
    const string m_fileName;

public:
    GoodLogger(const string &fileName) : m_fstream{getFileStream(fileName)}, m_fileName{fileName}
    {
        // empty
    }

    ~GoodLogger()
    {
        closeFileStream(m_fileName);
    }

    void log(const string& str)
    {
        m_fstream << str;
    }
};

class LoggerWithNoDestructor
{
    fstream &m_fstream;
    const string m_fileName;

public:
    LoggerWithNoDestructor(const string &fileName) : m_fstream{getFileStream(fileName)}, m_fileName{fileName}
    {
        // empty
    }

    void log(const string& str)
    {
        m_fstream << str;
    }
};

const string kFileName = "test.txt";

void testBadFirstWrite()
{
    LoggerWithNoDestructor logger{ kFileName};
    logger.log("output");

    // Close the stream manually if you know how!
}

void testGoodFirstWrite()
{
    GoodLogger logger{ kFileName};
    logger.log("output");

    // I don't have to worry about cleanup.
}

void testSecondWrite()
{
    GoodLogger logger{ kFileName};
    logger.log("second write");
}

void testBadScenario()
{
    testBadFirstWrite();
    testSecondWrite();
}

void testGoodScenario()
{
    testGoodFirstWrite();
    testSecondWrite();
}
#endif // __LOGGER_H__