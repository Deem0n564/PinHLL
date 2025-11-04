#include "functions.h"

void Employee::print(int i) const
{
    std::cout << " Employee[" << i << "]: " << getName() << ", " << position << ", Salary " << salary << ", " << getBirthYear() << " year of birth\n";
}