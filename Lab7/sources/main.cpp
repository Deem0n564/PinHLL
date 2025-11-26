#include "functions.h"

int main()
{
    std::string filename = "data.bin";

    while (true)
    {
        std::cout << "\tMENU"
            << "\n 1. Input integer (to end of file)"
            << "\n 2. Read integer by index"
            << "\n 3. Read byte by index"
            << "\n 4. Clear file"
            << "\n 0. Exit"
            << "\n Your choice: ";

        int choice;
        std::cin >> choice;

        try
        {
            switch (choice)
            {
            case 1:
                inputIntegerToFile(filename);

                break;

            case 2:
                readIntegerByIndex(filename);

                break;

            case 3:
                readByteByIndex(filename);

                break;

            case 4:
            {
                FileReader<int>::clearFile(filename);

                std::cout << " File cleared successfully!" << std::endl;

                break;
            }

            case 0:
            {
                std::cout << "\n Exit...\n\n" << std::endl;

                return 0;
            }

            default:
            {
                std::cout << " Invalid option!" << std::endl;

                break;
            }
            }
        }
        catch (const FileException& e)
        {
            std::cerr << " File Error: " << e.what() << std::endl;
        }
        catch (const std::exception& e)
        {
            std::cerr << " Error: " << e.what() << std::endl;
        }
    }
}