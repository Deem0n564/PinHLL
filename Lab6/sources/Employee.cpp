#include "functions.h"

void Employee::print() const
{
    std::cout << " Employee: " << getName() << ", " << position << ", Salary " << salary << ", " << getBirthYear() << " year of birth\n";
}