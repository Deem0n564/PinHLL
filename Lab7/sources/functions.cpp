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
size_t getFileSize(const std::string& filename)
{
    std::ifstream file(filename, std::ios::binary | std::ios::ate);

    if (!file.is_open())
    {
        return 0;
    }

    size_t size = file.tellg();
    file.close();

    return size;
}

void inputIntegerToFile(const std::string& filename) 
{
    std::cout << " Enter integer to file: ";
    int value;
    std::cin >> value;
    addIntToFileEnd(filename, value);
    std::cout << " Integer " << value << " added to file." << std::endl;
}

void readIntegerByIndex(const std::string& filename) 
{
    size_t fileSize = getFileSize(filename);

    if (fileSize == 0) 
    {
        std::cout << " File is empty!" << std::endl;
        return;
    }

    size_t maxIndex = fileSize / sizeof(int) - 1;
    std::cout << " Enter index (0 to " << maxIndex << "): ";
    int index;
    std::cin >> index;
    FileReader<int> arr(filename);
    int value = arr[index];
    std::cout << " Integer at index " << index << ": " << value << std::endl;
}

void readByteByIndex(const std::string& filename) 
{
    size_t fileSize = getFileSize(filename);

    if (fileSize == 0)
    {
        std::cout << " File is empty!" << std::endl;

        return;
    }

    std::cout << " Enter byte index (0 to " << fileSize - 1 << "): ";
    int index;
    std::cin >> index;
    FileReader<std::byte> byteArr(filename);
    std::byte byte = byteArr[index];
    std::cout << " Byte at index " << index << ": "
        << static_cast<int>(byte) << std::endl;
}