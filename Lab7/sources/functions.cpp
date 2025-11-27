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

int getInputInt()
{
    int input = 0;

    while (true)
    {
        if (std::cin >> input)
        {
            std::cin.ignore(100, '\n');

            return input;
        }

        else
        {
            std::cin.clear();
            std::cin.ignore(100, '\n');

            std::cout << " Incorrect! Please enter a valid integer: ";
        }
    }
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
    int value;

    std::cout << " Enter integer to file: ";
    std::cin >> value;
    addIntToFileEnd(filename, value);
    std::cout << " Integer " << value << " added to file.\n";
}

void readIntegerByIndex(const std::string& filename) 
{
    int index;
    size_t fileSize = getFileSize(filename);

    if (fileSize == 0) 
    {
        std::cout << " File is empty!\n";

        return;
    }

    size_t maxIndex = fileSize / sizeof(int) - 1;
    std::cout << " Enter index (0 to " << maxIndex << "): ";
    std::cin >> index;
    FileReader<int> arr(filename);
    int value = arr[index];
    std::cout << " Integer at index " << index << ": " << value << "\n";
}

void readByteByIndex(const std::string& filename) 
{
    int index;
    size_t fileSize = getFileSize(filename);

    if (fileSize == 0)
    {
        std::cout << " File is empty!\n";

        return;
    }

    std::cout << " Enter byte index (0 to " << fileSize - 1 << "): ";
    std::cin >> index;
    FileReader<std::byte> byteArr(filename);
    std::byte byte = byteArr[index];
    std::cout << " Byte at index " << index << ": "
        << static_cast<int>(byte) << "\n";
}