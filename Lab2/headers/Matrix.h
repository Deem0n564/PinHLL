#pragma once

#include <iostream>
#include "functions.h"

class Matrix
{
    int rows;
    int cols;
    int** data = nullptr;

    void allocate(int r, int c);
    void deallocate();

public:
    explicit Matrix(int r = 0, int c = 0) : rows(r), cols(c)
    {
        if (rows > 0 && cols > 0)
        {
            allocate(rows, cols);
        }
    }

    Matrix(const Matrix& other) : rows(0), cols(0), data(nullptr)
    {
        if (other.rows > 0 && other.cols > 0)
        {
            allocate(other.rows, other.cols);

            for (int i = 0; i < rows; ++i)
            {
                for (int j = 0; j < cols; ++j)
                {
                    data[i][j] = other.data[i][j];
                }
            }
        }
    }

    Matrix& operator=(Matrix other)
    {
        std::swap(rows, other.rows);
        std::swap(cols, other.cols);
        std::swap(data, other.data);

        return *this;
    }

    ~Matrix()
    {
        deallocate();
    }

    friend Matrix operator+(const Matrix& a, const Matrix& b)
    {
        if (a.rows != b.rows || a.cols != b.cols)
        {
            std::cout << " Matrixes must have the same dimensions\n";

            exit(0);
        }

        Matrix result(a.rows, a.cols);

        for (int i = 0; i < a.rows; ++i)
        {
            for (int j = 0; j < a.cols; ++j)
            {
                result.data[i][j] = a.data[i][j] + b.data[i][j];
            }
        }

        return result;
    }

    friend std::istream& operator>>(std::istream& is, Matrix& m)
    {
        int r;
        int c;

        std::cout << " Enter rows: ";

        r = getInputInt();

        std::cout << " Enter cols: ";

        c = getInputInt();

        Matrix temp(r, c);

        for (int i = 0; i < r; ++i)
        {
            for (int j = 0; j < c; ++j)
            {
                std::cout << " Enter element(" << i << ")(" << j << "): ";

                temp.data[i][j] = getInputInt();
            }
        }

        m = std::move(temp);

        return is;
    }

    friend std::ostream& operator<<(std::ostream& os, const Matrix& m)
    {
        os << " Rows: Cols:\n" << "  " << m.rows << "     " << m.cols << "\n\n";

        for (int i = 0; i < m.rows; ++i)
        {
            for (int j = 0; j < m.cols; ++j)
            {
                os << m.data[i][j] << "  ";
            }

            os << "\n";
        }

        return os;
    }
};