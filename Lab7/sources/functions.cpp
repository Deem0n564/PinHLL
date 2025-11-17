#include "functions.h"
#include "FileReader.h"

#include <iostream>
#include <fstream>
#include <cstdint>
#include <stdexcept>

void write_mode(const std::string& fname)
{
    std::ofstream out(fname, std::ios::binary);
    if (!out.is_open())
    {
        std::cerr << "Cannot create file: " << fname << "\n";

        return;
    }

    std::cout << "Write mode. How many int32 values do you want to write? ";
    std::size_t n;

    if (!(std::cin >> n))
    {
        std::cerr << "Invalid number of elements\n";

        return;
    }

    std::cout << "Enter values one by one (int32). Press Enter after each.\n";

    for (std::size_t i = 0; i < n; ++i)
    {
        int32_t val;
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
        std::cout << "  1 - int32 (whole element)\n";
        std::cout << "  2 - uint8 (byte indexing)\n";
        std::cout << "Enter 1 or 2: ";
        int choice = 0;

        if (!(std::cin >> choice))
        {
            std::cerr << "Invalid input\n";

            return;
        }

        std::cout << "Enter index (0-based): ";
        std::size_t idx = 0;

        if (!(std::cin >> idx))
        {
            std::cerr << "Invalid index input\n";

            return;
        }

        try
        {
            if (choice == 1)
            {
                // index in int32 elements (each element is 4 bytes)
                int32_t v = fr.readAtIndex<int32_t>(idx);
                std::cout << "element[" << idx << "] (int32) = " << v << "\n";
            }

            else
            {
                // index in uint8 elements (i.e. byte index)
                uint8_t b = fr.readAtIndex<uint8_t>(idx);
                std::cout << "byte[" << idx << "] (uint8) = " << static_cast<int>(b) << "\n";
            }
        }

        catch (const std::exception& e)
        {
            std::cout << "Read error: " << e.what() << "\n";
        }

    }

    catch (const std::exception& e)
    {
        std::cerr << "Failed to open file: " << e.what() << "\n";
    }
}
