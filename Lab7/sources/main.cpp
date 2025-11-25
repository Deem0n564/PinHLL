#include "functions.h"

int main() 
{
    const std::string fname = "data.bin";
    std::cout << "\tProgram for writing/reading binary file data.bin\n\n"
        << " Choose mode:\n"
        << "   w - write\n"
        << "   r - read\n"
        << " Enter w or r: ";

    char mode = 0;

    if (!(std::cin >> mode)) 
    {
        std::cerr << "Invalid input\n";

        return 1;
    }

    if (mode == 'w' || mode == 'W') 
    {
        write_mode(fname);
    }

    else if (mode == 'r' || mode == 'R') 
    {
        read_mode(fname);
    }

    else 
    {
        std::cerr << "Unknown mode: " << mode << "\n";

        return 1;
    }

    std::cout << "Done.\n";

    return 0;
}
