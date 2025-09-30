#include "Header.h"

int main() 
{
    Matrix A, B;

    std::cout << " Enter matrix A (First,rows cols, then elements):\n";
    std::cin >> A;

    std::cout << " Enter matrix B (First,rows cols, then elements):\n";
    std::cin >> B;

        Matrix C = A + B;

        std::cout << " Result matrix C = A + B:\n" << C;
    
    return 0;
}