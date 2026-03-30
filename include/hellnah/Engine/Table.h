#pragma once

#include "../Storage/FileStorage.h"
#include "../Core/WorkFile.h"

#include <fstream>

namespace Engine
{
template <typename T>
class Table
{
    Core::WorkFile& _workFile;

public:
    Table(Core::WorkFile& workFile) : _workFile(workFile) {}

    int insert(T obj)
    {
        const char* path = _workFile.getValue();
        size_t size = sizeof(obj);

        std::ofstream file(path, std::ios::binary | std::ios::app);

        int id = Storage::FileStorage::add(path, size);
        file.write(reinterpret_cast<const char*>(&obj), size);

        file.close();

        return id;
    }
    T get(T);
    void remove(T);
};
}
