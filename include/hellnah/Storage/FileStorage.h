#pragma once

#include "../Core/WorkFile.h"
#include "../Storage/IdStorage.h"

#include <cstddef>

namespace Storage
{
    class FileStorage
    {
        Core::WorkFile &_workFile;
        Storage::IdStorage &_IdStorage;

    public:
        FileStorage(Core::WorkFile &workFile, Storage::IdStorage &idStorage): _workFile(workFile), _IdStorage(idStorage){};
        uint64_t add_record();
    };
};
