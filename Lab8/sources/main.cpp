#include "functions.h"

int main()
{
    int choice;

    while (true)
    {
        std::cout << "\tMENU"
            << "\n 1. "
            << "\n 0. Exit"
            << "\n Your choice: ";
        choice = getInputInt();

        try
        {
            switch (choice)
            {
            case 1:
            {
                

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
        catch (const std::exception& e)
        {
            std::cerr << " Error: " << e.what() << "\n";
        }
    }
}