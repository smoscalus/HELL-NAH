#pragma once

#include <cstdint>

using RecordId = uint64_t;

struct RecordHeader
{
    RecordId id;
    uint32_t size;
    uint8_t isDeleted;
};

static_assert(sizeof(RecordHeader) == 16, "RecordHeader size must be 16 bytes");