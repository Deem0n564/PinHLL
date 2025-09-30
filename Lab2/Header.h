#pragma once

#include <iostream>

class Matrix
{
    int rows;
    int cols;
    double** data;

    void allocate(int r, int c);
    void deallocate();

public:
    Matrix(int r = 0, int c = 0) : rows(0), cols(0), data(nullptr)
    {
        if (r > 0 && c > 0)
        {
            allocate(r, c);
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

    Matrix operator+(const Matrix& rhs) const
    {
        if (rows != rhs.rows || cols != rhs.cols)
        {
            throw std::invalid_argument("Matrixes must have the same dimensions for addition");
        }

        Matrix result(rows, cols);

        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                result.data[i][j] = data[i][j] + rhs.data[i][j];
            }
        }

        return result;
    }

    friend std::istream& operator>>(std::istream& is, Matrix& m)
    {
        int r, c;

        is >> r >> c;
        if (!is) return is;

        Matrix temp(r, c);
        for (int i = 0; i < r; ++i)
        {
            for (int j = 0; j < c; ++j)
            {
                is >> temp.data[i][j];
            }
        }

        m = std::move(temp);

        return is;
    }

    friend std::ostream& operator<<(std::ostream& os, const Matrix& m)
    {
        os << m.rows << " " << m.cols << "\n";

        for (int i = 0; i < m.rows; ++i)
        {
            for (int j = 0; j < m.cols; ++j)
            {
                os << m.data[i][j] << " ";
            }

            os << "\n";
        }

        return os;
    }
};