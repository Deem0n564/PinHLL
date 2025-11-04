#include "functions.h"

float Student::getAverage() const
{
    return averageGrade;
}

void Student::print(int i) const
{
    std::cout << " Student[" << i << "]: " << getName() << ", " << getBirthYear() << " year of birth, " << "Average grade: " << averageGrade << '\n';
}