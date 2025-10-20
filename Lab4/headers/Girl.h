#pragma once

#include "functions.h"

class Girl : public Person
{
public:
    Girl(const std::string& name, int age)
        : Person(name, age) {};
    void reactTo(const Person& other) const override;
};