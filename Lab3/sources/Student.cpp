#include "functions.h"

float Student::getAverage() const
{
    return averageGrade;
}

void Student::print() const
{
    std::cout << " Student: " << getName() << ", " << getBirthYear() << " year of birth, " << "Average grade: " << averageGrade << '\n';
}