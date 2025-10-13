#pragma once

#include "Person.h"

class Student : public Person 
{
    float averageGrade;
public:
    explicit Student(const std::string& n = "", int y = 0, float avg = 0.0) : Person(n, y), averageGrade(avg)
    {
    }

    void setAverage(float avg)
    { 
        averageGrade = avg; 
    }

    float getAverage() const
    { 
        return averageGrade; 
    }

    void print() const 
    {
        std::cout << "Student: " << name << ", " << birthYear << " d.b., " << "Average grade: " << averageGrade << '\n';
    }
};