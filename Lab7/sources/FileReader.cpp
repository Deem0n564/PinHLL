#include "functions.h"

FileReader::FileReader(const std::string& path)
    : file(path, std::ios::binary)
{
    if (!file.is_open())
    {
        throw std::runtime_error(" Cannot open file: " + path);
    }
}

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