#include "../../include/hellnah/Storage/FileStorage.h"
#include "../../include/hellnah/Core/DbHeader.h"
#include "../../include/hellnah/Core/RecordHeader.h"
#include "../../include/hellnah/Storage/FileStorage.h"

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstddef>

namespace Storage
{
    int FileStorage::is_exists_file(const char *path)
    {
        std::fstream file(path, std::ios::in | std::ios::binary);
        if (!file.fail())
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    void FileStorage::create_file(const char *path)
    {
        std::ofstream file(path, std::ios::binary);

        Core::DbHeader header{};
        header.version = 0.1;

        file.write((char *)&header, sizeof(header));
        file.close();
    }

    void FileStorage::read_file(const char *path)
    {
        Core::DbHeader header;
        std::ifstream file(path, std::ios::binary);
        file.read(reinterpret_cast<char*>(&header), sizeof(header));

        if (memcmp(header.magic, "HELLNAH", 8) != 0)
        {
            throw std::runtime_error("The file is not a HELLNAH database!");
        }
    }

    int FileStorage::add(const char* path, size_t size)
    {
        std::ofstream file(path, std::ios::binary | std::ios::app);

        Core::RecordHeader record_header;

        record_header.id = 1; // "for now"
        record_header.size = size;
        record_header.isDeleted = 0;

        file.write(reinterpret_cast<char*>(&record_header), sizeof(record_header));

        return record_header.id;
    }
}
