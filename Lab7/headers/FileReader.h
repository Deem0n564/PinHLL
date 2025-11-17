#pragma once

#include "functions.h"

class FileReader
{
public:
    explicit FileReader(const std::string& path)
        : file(path, std::ios::binary)
    {
        if (!file.is_open())
        {
            throw std::runtime_error("Cannot open file: " + path);
        }
    }

    template<typename T>
    T readAtIndex(std::size_t index)
    {
        static_assert(std::is_trivially_copyable<T>::value, "T must be trivially copyable");
        std::streamoff offset = static_cast<std::streamoff>(index) * static_cast<std::streamoff>(sizeof(T));
        file.clear(); // clear flags
        file.seekg(offset, std::ios::beg);

        if (!file.good())
        {
            throw std::runtime_error("seek failed (maybe index out of range)");
        }

        T value{};
        file.read(reinterpret_cast<char*>(&value), static_cast<std::streamsize>(sizeof(T)));

        if (file.gcount() != static_cast<std::streamsize>(sizeof(T)))
        {
            throw std::runtime_error("read failed or EOF reached");
        }

        return value;
    }

    double sizeBytes();

private:
    std::ifstream file;
};