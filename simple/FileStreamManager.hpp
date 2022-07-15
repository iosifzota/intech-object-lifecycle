#ifndef __FILESTREAMMANAGER_H__
#define __FILESTREAMMANAGER_H__

#include <fstream>
#include <vector>

#include "File.hpp"

using namespace std;

class FileManager
{
    vector<File *> files;

public:
    File &getFile(const string &fileName)
    {
        // Search if already touched the file
        for (File *filePtr : files)
        {
            if (filePtr->getFileName() == fileName)
            {
                return *filePtr;
            }
        }

        // Setup the file
        addFile(fileName);
        File *filePtr = files.back();
        return *filePtr;
    }

private:
    void addFile(const string &fileName)
    {
        files.push_back(createFile(fileName));
    }
};

static FileManager sg_fileManager;

fstream &getFileStream(const string &fileName)
{
    File &fileRef = sg_fileManager.getFile(fileName);
    return fileRef.setupFileStream();
}

void closeFileStream(const string &fileName)
{
    File &fileRef = sg_fileManager.getFile(fileName);
    fileRef.closeFileStream();
}


#endif // __FILESTREAMMANAGER_H__