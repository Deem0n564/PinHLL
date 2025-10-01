#include "Matrix.h"

int main() 
{
    Matrix A;
    Matrix B;

    std::cout << " Enter matrix A:\n";
    std::cin >> A;

    std::cout << "\n Enter matrix B:\n";
    std::cin >> B;

        Matrix C = A + B;

        std::cout << "\n Result matrix C = A + B:\n" << C;
    
    return 0;
}