#pragma once

namespace Core
{
    struct WorkFile
    {
    private:
        char Value[256];

    public:
        WorkFile(const char *path);
        const char *getValue() const { return Value; }
    };
}
