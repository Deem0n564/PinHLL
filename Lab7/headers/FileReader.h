#pragma once

#include "functions.h"

template<typename T>
class FileReader
{
private:
    std::ifstream file;
    std::string filename;

public:
    explicit FileReader(const std::string& fname) : filename(fname)
    {
        file.open(filename, std::ios::binary);

        if (!file.is_open())
        {
            throw FileException("Cannot open file: " + filename);
        }
    }

    ~FileReader()
    {
        if (file.is_open())
        {
            file.close();
        }
    }

    static void clearFile(const std::string& filename)
    {
        std::ofstream file(filename, std::ios::binary | std::ios::trunc);
        if (!file) 
        {
            throw FileException("Cannot clear file: " + filename);
        }
        file.close();
    }

    T operator[](int index)
    {
        T value = T();

        file.seekg(index * sizeof(T));
        file.read(static_cast<char*>(static_cast<void*>(&value)), sizeof(T));

        if (!file)
        {
            throw FileException("Read error at index: " + std::to_string(index));
        }

        return value;
    }
};