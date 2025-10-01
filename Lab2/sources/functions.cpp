#include "Matrix.h"
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

            std::cout << " Incorrect! Please enter a valid integer: ";
        }
    }
}

void Matrix::allocate(int r, int c)
{
    rows = r;
    cols = c;
    data = new int* [rows];

    for (int i = 0; i < rows; ++i)
    {
        data[i] = new int[cols];
    }
}

void Matrix::deallocate()
{
    if (data)
    {
        for (int i = 0; i < rows; ++i)
        {
            delete[] data[i];
        }

        delete[] data;

        data = nullptr;
    }

    rows = cols = 0;
}