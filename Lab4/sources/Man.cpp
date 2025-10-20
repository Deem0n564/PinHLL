#include "functions.h"

void Man::reactTo(const Person& other) const
{
    std::cout << " " << getName()
        << " made eye contact with " << other.getName()
        << " and nodded.\n";
}