#pragma once

#include "../Core/WorkFile.h"

namespace Storage::FileStorage
{
    class FileStorage
    {
    public:

        void create_file(const char *path);

        void read_file(const char *path);

        int is_exists_file(const char *path);

        int add();
        int get();
        void remove();
    };
};
