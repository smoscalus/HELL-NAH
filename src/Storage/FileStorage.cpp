#include "../../include/hellnah/Storage/FileStorage.h"
#include "../../include/hellnah/Core/DbHeader.h"
#include "../../include/hellnah/Storage/FileStorage.h"

#include <iostream>
#include <fstream>
#include <cstring>

using namespace Storage::FileStorage;

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

    DbHeader header{};
    header.version = 0.1;

    file.write((char *)&header, sizeof(header));
    file.close();
}

void FileStorage::read_file(const char *path)
{
    DbHeader header;
    std::ifstream file(path, std::ios::binary);
    file.read((char *)&header, sizeof(header));

    if (memcmp(header.magic, "HELLNOT", 8) != 0)
    {
        throw std::runtime_error("Файл не является HELLNAH базой!");
    }
}
