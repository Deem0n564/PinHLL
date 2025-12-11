#include "functions.h"

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
            std::cout << "Incorrect! Please enter a valid integer: ";
        }
    }
}