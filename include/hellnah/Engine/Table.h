#pragma once

#include "../Storage/FileStorage.h"
#include "../Core/WorkFile.h"
#include "../Core/DbHeader.h"
#include "../Core/RecordHeader.h"

#include <fstream>

namespace Engine
{
    template <typename T>
    class Table
    {
        Core::WorkFile &_workFile;

    public:
        Table(Core::WorkFile &workFile) : _workFile(workFile) {}

        uint64_t insert(T obj)
        {
            const char *path = _workFile.getValue();
            size_t size = sizeof(obj);

            std::ofstream file(path, std::ios::binary | std::ios::app);

            uint64_t id = Storage::FileStorage::add_record(path, size);
            file.write(reinterpret_cast<const char *>(&obj), size);

            file.close();

            return id;
        }

        T get(int id)
        {
            uint64_t offset = sizeof(Core::DbHeader) + (id - 1) * (sizeof(Core::RecordHeader) + sizeof(T));

            std::fstream file(_workFile.getValue(), std::ios::binary | std::ios::in);
            file.seekg(offset, std::ios::beg);

            Core::RecordHeader header;
            file.read(reinterpret_cast<char *>(&header), sizeof(header));

            if (header.isDeleted == 1)
            {
                throw std::runtime_error("Record deleted");
            }
            
            if (header.id == 0)
            {
                throw std::runtime_error("no record");
            }

            T value;
            file.read(reinterpret_cast<char *>(&value), sizeof(T));
            return value;
        }

        void remove(int id)
        {
            uint64_t offset = sizeof(Core::DbHeader) + (id - 1) * (sizeof(Core::RecordHeader) + sizeof(T));

            std::fstream file(_workFile.getValue(), std::ios::binary | std::ios::in | std::ios::out);
            file.seekg(offset, std::ios::beg);

            Core::RecordHeader header;
            file.read(reinterpret_cast<char *>(&header), sizeof(header));

            if (header.isDeleted == 1)
            {
                throw std::runtime_error("Record deleted");
            }

            header.isDeleted = 1;

            file.seekp(offset, std::ios::beg);
            file.write(reinterpret_cast<char *>(&header), sizeof(header));
        }
    };
}
