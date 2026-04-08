#include "../../include/hellnah/Storage/FileStorage.h"
#include "../../include/hellnah/Core/DbHeader.h"
#include "../../include/hellnah/Core/RecordHeader.h"

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdint>

namespace Storage
{
    uint64_t FileStorage::add_record()
    {
        const char *path = _workFile.get_path();
        size_t size = _workFile.get_size();

        std::ofstream file(path, std::ios::binary | std::ios::app);

        Core::RecordHeader record_header;

        record_header.id = _id.next_id();
        _id.set_id(record_header.id);
        record_header.size = size;
        record_header.isDeleted = 0;

        file.write(reinterpret_cast<char *>(&record_header), sizeof(record_header));

        return record_header.id;
    }
}
