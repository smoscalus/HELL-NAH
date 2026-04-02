#pragma once

#include <cstdint>

namespace Core
{
    struct Id
    {
    private:
        uint64_t id = 0;

    public:
        void set_id(uint64_t id);
        uint64_t get_id();
    };
}
