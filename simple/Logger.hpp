#ifndef __LOGGER_H__
#define __LOGGER_H__

#include "OutputStream.hpp"

class GoodLogger
{
    ostream &out;

public:
    GoodLogger() : out{getOutputStream()}
    {
        // empty
    }

    ~GoodLogger()
    {
        closeOutputStreamSpecial();
    }

    void log(const string& str)
    {
        out << str;
    }
};

class LoggerWithNoDestructor
{
    ostream &out;

public:
    LoggerWithNoDestructor() : out{getOutputStream()}
    {
        // empty
    }

    void log(const string& str)
    {
        out << str;
    }
};


void testBadFirstWrite()
{
    LoggerWithNoDestructor logger;
    logger.log("output");

    // Close the stream manually if you know how!
}

void testGoodFirstWrite()
{
    GoodLogger logger;
    logger.log("output\n");

    // I don't have to worry about cleanup.
}

void testSecondWrite()
{
    GoodLogger logger;
    logger.log("second write\n");
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