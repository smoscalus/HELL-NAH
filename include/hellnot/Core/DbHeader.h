#pragma once

#include <cstdint>

struct DbHeader
{
    char magic[8];
    uint32_t version;
};


static_assert(sizeof(DbHeader) == 12, "DbHeader size must be 12 bytes");