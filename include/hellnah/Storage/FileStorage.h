#pragma once

#include "../Core/WorkFile.h"

#include <cstddef>

namespace Storage
{
    class FileStorage
    {
    public:
        static void create_file(const char *path);
        static void read_file(const char *path);
        static int is_exists_file(const char *path);
        static int add_record(const char *path, size_t size);
    };
};
