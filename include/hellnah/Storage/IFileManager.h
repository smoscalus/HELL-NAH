#pragma once

#include "../Core/WorkFile.h";
#include "FileManager.h";

class IFileManager
{
public:
    virtual ~IFileManager() = default;

    virtual int Read() = 0;
    virtual int write() = 0;
};