#include "../../include/hellnah/Core/WorkFile.h"
#include <string.h>
#include <iostream>

WorkFile::WorkFile(const char *path)
{
    strcpy(Value, path);
    for (int i = 0; Value[i] != '\0'; i++) //for test
        std::cout << Value[i];
}