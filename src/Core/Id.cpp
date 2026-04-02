#include "../../include/hellnah/Core/Id.h"

#include <iostream>

namespace Core
{
    Id::Id(uint64_t id)
    {
        if(id < 0)
        {   
            throw std::runtime_error("file is broke");          
        }
        this->id = id;
    }

    uint64_t Id::get_id()
    {
        return this->id;
    }
}