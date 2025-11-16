#pragma once

#include "functions.h"

class Man : public Person
{
public:
    using Person::Person;
    void reactTo(const Person& other) const override;
};