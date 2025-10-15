#pragma once

# include "functions.h"

class Person 
{
private:
    std::string name;
    int birthYear;

public:
    explicit Person(const std::string& n = "", int y = 0) : name(n), birthYear(y) 
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