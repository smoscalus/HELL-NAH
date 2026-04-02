#include "../../include/hellnah/Core/Id.h"
#include "../../include/hellnah/Core/DbHeader.h"
#include "../../include/hellnah/Core/RecordHeader.h"
#include "../../include/hellnah/Storage/IdStorage.h"

#include <cstdint>
#include <stdio.h>
#include <fstream>

namespace Storage
{
    IdStorage::IdStorage(const char *path, size_t size)
    {
        size_t RecordHeader_size = sizeof(Core::RecordHeader) + size;
        size_t DbHeader_size = sizeof(Core::DbHeader);

        std::ifstream file(path, std::ios::binary);
        if (!file)
            throw std::runtime_error("File is broken");

        file.seekg(0, std::ios::end);

        std::streampos file_size = file.tellg();

        if (file_size == DbHeader_size)
        {
            this->id.set_id(1);
        }

        size_t data_size = static_cast<size_t>(file_size) - sizeof(Core::DbHeader);
        size_t count = data_size / RecordHeader_size;

        std::streampos lastOffset = sizeof(Core::DbHeader) + (count - 1) * RecordHeader_size;

        Core::RecordHeader header{};
        file.seekg(lastOffset, std::ios::beg);
        file.read(reinterpret_cast<char *>(&header), sizeof(header));

        this->id.set_id(header.id);
    }

    uint64_t IdStorage::next_id(const char *path, size_t size)
    {
        uint64_t nex_id = this->id.get_id() + 1;
        this->id.set_id(nex_id);

        return nex_id;
    }
}
