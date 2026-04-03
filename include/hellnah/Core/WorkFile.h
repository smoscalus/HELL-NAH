#pragma once

namespace Core
{
    struct WorkFile
    {
    private:
        char path[256];
        size_t size;

        void create_file(const char *path);
        void read_file(const char *path);
        int is_exists_file(const char *path);

    public:
        WorkFile(const char *path);
        void set_size(size_t size)
        {
            this->size = size;
        }
        size_t get_size() const
        {
            return this->size;
        }
        const char *get_path() const
        {
            return this->path;
        }
    };
}
