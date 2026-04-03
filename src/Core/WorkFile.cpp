#include "../../include/hellnah/Core/WorkFile.h"
#include "../../include/hellnah/Core/DbHeader.h"
#include "../../include/hellnah/Storage/FileStorage.h"

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstddef>

namespace Core
{
    int WorkFile::is_exists_file(const char *path)
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

    void WorkFile::create_file(const char *path)
    {
        std::ofstream file(path, std::ios::binary);

        Core::DbHeader header{};
        header.version = 0.1;

        file.write((char *)&header, sizeof(header));
        file.close();
    }

    void WorkFile::read_file(const char *path)
    {
        Core::DbHeader header;
        std::ifstream file(path, std::ios::binary);
        file.read(reinterpret_cast<char *>(&header), sizeof(header));

        if (memcmp(header.magic, "HELLNAH", 8) != 0)
        {
            throw std::runtime_error("The file is not a HELLNAH database!");
        }
    }

    Core::WorkFile::WorkFile(const char *path)
    {
        if (!is_exists_file(path))
        {
            create_file(path);
        }
        else
        {
            read_file(path);
        }

        strcpy(this->path, path);
    }
}
