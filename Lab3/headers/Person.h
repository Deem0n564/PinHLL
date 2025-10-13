#pragma once

#include <iostream>
#include <string>

class Person 
{
protected:
    std::string name;
    int birthYear;

public:
    Person(const std::string& n = "", int y = 0) : name(n), birthYear(y) 
    {
    }

    int getBirthYear() const 
    { 
        return birthYear; 
    }

    std::string getName() const 
    { 
        return name; 
    }
};