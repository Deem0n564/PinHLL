#include "functions.h"

int main()
{
    int choice;
    std::string filename = "data.bin";

    while (true)
    {
        std::cout << "\tMENU"
            << "\n 1. Input object to file"
            << "\n 2. Read object by index"
            << "\n 3. Clear file"
            << "\n 0. Exit"
            << "\n Your choice: ";
        choice = getInputInt();

        try
        {
            switch (choice)
            {
            case 1:
            {
                inputObjectToFile(filename);

                break;
            }

            case 2:
            {
                readObjectByIndex(filename);

                break;
            }

            case 3:
            {
                FileReader<int>::clearFile(filename);
                std::cout << " File cleared successfully!\n";

                break;
            }

            case 0:
            {
                std::cout << "\n Exit...\n\n";

                return 0;
            }

            default:
            {
                std::cout << " Invalid option!\n";

                break;
            }
            }
        }
        catch (const FileException& e)
        {
            std::cerr << " File Error: " << e.what() << "\n";
        }
        catch (const std::exception& e)
        {
            std::cerr << " Error: " << e.what() << "\n";
        }
    }
}