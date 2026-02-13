#pragma once

#include "../Core/WorkFile.h";
#include "IFileManager.h";

class FileManager : public IFileManager
{
    WorkFile _workFile;
private:
    FileManager(const char* path) : _workFile(path) {};
public: 
    static FileManager InitFile(const char* path)
    {
        return FileManager(path);
    };
    int Read() override;
    int write() override;
};
