#include "functions.h"

void Girl::reactTo(const Person& other) const 
{
    std::cout << " " << getName()
        << " noticed " << other.getName()
        << " and smiled)\n";
}