#pragma once

#include <cstdint>
#include <stdio.h>

#include "../Core/Id.h"

namespace Storage
{
    class IdStorage
    {
        Core::Id id;

    public:
        IdStorage(const char *path, size_t size);
        uint64_t next_id(const char *path, size_t size);
    };
}
