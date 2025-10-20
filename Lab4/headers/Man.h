#pragma once

#include "functions.h"

class Man : public Person
{
public:
    Man(const std::string& name, int age)
        : Person(name, age) {};
    void reactTo(const Person& other) const override;
};