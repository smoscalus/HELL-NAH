#include "../../include/hellnah/Core/Id.h"
#include "../../include/hellnah/Core/DbHeader.h"
#include "../../include/hellnah/Core/RecordHeader.h"

#include <cstdint>
#include <stdio.h>
#include <fstream>

void Core::Id::set_id(uint64_t id)
{
    if (id < 0)
    {
        throw std::runtime_error("File is broke");
    }
    this->id = id;
}

uint64_t Core::Id::get_id()
{
    return this->id;
}

uint64_t Core::Id::next_id()
{
    uint64_t nex_id = get_id() + 1;
    return nex_id;
}
