#include "FileReader.h"

FileReader::FileReader(const std::string& path)
    : file(path, std::ios::binary)
{
    if (!file.is_open())
    {
        throw FileError("Cannot open file: " + path);
    }
}

std::uintmax_t FileReader::sizeBytes()
{
    // save current position
    auto curPos = file.tellg();
    if (curPos == std::ifstream::pos_type(-1))
    {
        // maybe stream not positioned yet; try to clear and continue
        file.clear();
        // still try to get end
    }

    file.clear();
    file.seekg(0, std::ios::end);
    auto endPos = file.tellg();

    if (endPos == std::ifstream::pos_type(-1))
    {
        throw FileError("cannot determine size");
    }

    std::uintmax_t sz = static_cast<std::uintmax_t>(endPos);

    // restore position if possible
    if (curPos != std::ifstream::pos_type(-1))
    {
        file.seekg(curPos);
    }
    else
    {
        file.seekg(0, std::ios::beg);
    }

    return sz;
}
