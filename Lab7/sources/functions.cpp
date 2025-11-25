#include "functions.h"
#include "FileReader.h"

#include <iostream>
#include <fstream>
#include <cstdint>
#include <type_traits>

void write_mode(const std::string& fname)
{
    std::ofstream out(fname, std::ios::binary);

    if (!out.is_open())
    {
        std::cerr << "Cannot create file: " << fname << "\n";
        return;
    }

    std::cout << "Write mode.\n\nHow many int values do you want to write? ";
    int n;
    if (!(std::cin >> n) || n < 0)
    {
        std::cerr << "Invalid number of elements\n";
        return;
    }

    std::cout << "\nEnter values one by one (int). Press Enter after each.\n";

    for (int i = 0; i < n; ++i)
    {
        int val;
        std::cout << "element[" << i << "] = ";

        if (!(std::cin >> val))
        {
            std::cerr << "Invalid input\n";
            return;
        }

        out.write(reinterpret_cast<const char*>(&val), static_cast<std::streamsize>(sizeof(val)));

        if (!out)
        {
            std::cerr << "Error writing to file\n";
            return;
        }
    }

    std::cout << "Writing finished. File: " << fname << "\n";
}

void read_mode(const std::string& fname)
{
    try
    {
        FileReader fr(fname);
        std::cout << "Opened file: " << fname << "\n";
        auto sz = fr.sizeBytes();
        std::cout << "File size: " << sz << " bytes\n";

        std::cout << "Choose read type:\n";
        std::cout << "  1 - int (whole element)\n";
        std::cout << "  2 - uint8 (byte indexing)\n";
        std::cout << "Enter 1 or 2: ";
        int choice = 0;

        if (!(std::cin >> choice) || (choice != 1 && choice != 2))
        {
            std::cerr << "Invalid input\n";
            return;
        }

        std::cout << "Enter index (0-based): ";
        long long idx = 0;
        if (!(std::cin >> idx) || idx < 0)
        {
            std::cerr << "Invalid index input\n";
            return;
        }

        try
        {
            if (choice == 1)
            {
                int v = fr.readAtIndex<int>(idx);
                std::cout << "element[" << idx << "] (int) = " << v << "\n";
            }
            else
            {
                uint8_t b = fr.readAtIndex<uint8_t>(idx);
                std::cout << "byte[" << idx << "] (uint8) = " << static_cast<int>(b) << "\n";
            }
        }
        catch (const FileError& e)
        {
            std::cout << "Read error: " << e.what() << "\n";
        }
    }
    catch (const FileError& e)
    {
        std::cerr << "Failed to open file: " << e.what() << "\n";
    }
    catch (const std::exception& e)
    {
        std::cerr << "Unexpected error: " << e.what() << "\n";
    }
}
