#include "../../include/hellnah/Core/WorkFile.h"
#include "../../include/hellnah/Core/DbHeader.h"
#include "../../include/hellnah/Storage/FileStorage.h"

#include <cstring>

Core::WorkFile::WorkFile(const char *path)
{
    if (!Storage::FileStorage::is_exists_file(path))
    {
        Storage::FileStorage::create_file(path);
    }
    else
    {
        Storage::FileStorage::read_file(path);
    }

    strcpy(Value, path);
}
