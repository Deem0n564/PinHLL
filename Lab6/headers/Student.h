#pragma once

# include "functions.h"

class Student : public Person 
{
    float averageGrade;
public:
    explicit Student(const std::string& n = "", int y = 0, float avg = 0.0) : Person(n, y), averageGrade(avg) {}
    float getAverage() const;
    void print() const;
};