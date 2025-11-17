#include "functions.h"

double FileReader::sizeBytes()
{
    int cur = file.tellg();
    file.clear();
    file.seekg(0, std::ios::end);
    double sz = file.tellg();
    file.seekg(cur);

    if (sz == std::ifstream::pos_type(-1))
    {
        throw std::runtime_error("cannot determine size");
    }

    return sz;
}