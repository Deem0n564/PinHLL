#pragma once

#include "Person.h"

class Employee : public Person 
{
    std::string position;
    int salary;

public:
    explicit Employee(const std::string& n = "", int y = 0, const std::string& p = "", int s = 0) : Person(n, y), position(p), salary(s) 
    {
    }

    void print() const 
    {
        std::cout << "Employee: " << name << ", " << position << ", salary " << salary << ", " << birthYear << " d.b\n";
    }
};