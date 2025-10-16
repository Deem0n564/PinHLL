#pragma once

# include "functions.h"

class Student : public Person 
{
    float averageGrade;
public:
    explicit Student(const std::string& n = "", int y = 0, float avg = 0.0) : Person(n, y), averageGrade(avg)
    {
    }

    float getAverage() const
    { 
        return averageGrade; 
    }

    void print() const 
    {
        std::cout << " Student: " << getName() << ", " << getBirthYear() << " year of birth, " << "Average grade: " << averageGrade << '\n';
    }
};