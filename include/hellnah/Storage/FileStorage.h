#pragma once

#include "../Core/WorkFile.h"

#include <cstddef>

namespace Storage
{
    class FileStorage
    {
        IdStorage _idStorage;
        
    public:
        FileStorage(): _idStorage(){};

        void create_file(const char *path);
        void read_file(const char *path);
        int is_exists_file(const char *path);
        int add_record(const char *path, size_t size);
    };
};
