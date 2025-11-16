#pragma once

#include "functions.h"

class Person
{
    std::string name;
    int age;

public:
    Person(const std::string& name, int age)
        : name(name), age(age) {};
    virtual ~Person() = default;
    virtual void reactTo(const Person& other) const = 0;
    const std::string& getName() const;
    int getAge() const;
};