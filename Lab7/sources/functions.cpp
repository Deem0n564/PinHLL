#include "functions.h"

void addIntToFileEnd(const std::string& filename, int value)
{
    std::ofstream file(filename, std::ios::binary | std::ios::app);

    if (!file.is_open())
    {
        throw FileException("Cannot open file for writing: " + filename);
    }

    file.write(reinterpret_cast<const char*>(&value), sizeof(value));

    if (!file) 
    {
        throw FileException("Write error in file: " + filename);
    }

    file.close();
}

int getFileSize(const std::string& filename)
{
    std::ifstream file(filename, std::ios::binary | std::ios::ate);

    if (!file.is_open())
    {
        return 0;
    }

    int size = file.tellg();
    file.close();

    return size;
}