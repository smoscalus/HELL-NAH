#pragma once

#include "Table.h"
#include "../Core/WorkFile.h"

class Database
{
    WorkFile _workFile;

public:
    Database(const char *path): _workFile(path) {};
    
    template <typename T>
    Table<T> open_table(const char *path)
    {
        return Table<T>(_workFile);
    }
};
