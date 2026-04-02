#pragma once

#include <cstdint>

namespace Core
{
    struct Id
    {
    private:
        uint64_t id = 0;

    public:
        void set_id(uint64_t id)
        {
            if(id < 0)
            {  
                throw std::runtime_error("file is broke");          
            }

            this->id = id;
        }
        uint64_t get_id()
        {
            return this->id;
        }
    };
}
