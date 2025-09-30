#include "Header.h"

void Matrix::allocate(int r, int c)
{
    rows = r;
    cols = c;
    data = new double* [rows];

    for (int i = 0; i < rows; ++i)
    {
        data[i] = new double[cols];
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