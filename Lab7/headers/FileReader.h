#pragma once

#include <string>
#include <fstream>
#include <type_traits>
#include <cstddef>
#include <cstdint>
#include <vector>
#include <stdexcept>
#include <cstring>

class FileError : public std::runtime_error
{
public:
    explicit FileError(const std::string& msg) : std::runtime_error(msg) {}
};

class FileReader
{
public:
    explicit FileReader(const std::string& path);

    template<typename T>
    T readAtIndex(std::int64_t index)
    {
        static_assert(std::is_trivially_copyable_v<T>, "T must be trivially copyable");

        if (index < 0)
        {
            throw FileError("negative index");
        }

        const std::size_t elemSize = sizeof(T);
        std::streamoff offset = static_cast<std::streamoff>(index) * static_cast<std::streamoff>(elemSize);

        file.clear();
        file.seekg(offset, std::ios::beg);

        if (!file.good())
        {
            throw FileError("seek failed (maybe index out of range)");
        }

        std::vector<std::byte> buf(elemSize);
        file.read(reinterpret_cast<char*>(buf.data()), static_cast<std::streamsize>(buf.size()));

        if (file.gcount() != static_cast<std::streamsize>(buf.size()))
        {
            throw FileError("read failed or EOF reached");
        }

        T value;
        std::memcpy(&value, buf.data(), elemSize);

        return value;
    }

    std::uintmax_t sizeBytes();

private:
    std::ifstream file;
};
