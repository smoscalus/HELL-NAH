#pragma once

#include "Table.h"
#include "../Core/WorkFile.h"
#include "../Storage/FileStorage.h"

#include <cstring>

namespace Engine
{
    class Database
    {
        Core::WorkFile _workFile;

    public:
        Database(const char *path) : _workFile(path) {};

        template <typename T>
        Table<T> open_table(const char *table_name)
        {
            std::string file_name_s = std::string(table_name) + ".hellnot";
            const char *file_name = file_name_s.c_str();

            if (Storage::FileStorage::is_exists_file(file_name) == 0)
            {
                throw std::runtime_error(std::string("Table file does not exist: ") + file_name);
            }

            return Table<T>(_workFile);
        }
    };
}
