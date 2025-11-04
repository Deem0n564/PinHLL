#pragma once

#include <iostream>
#include <string>
#include <stdexcept>
#include "Person.h"
#include "Student.h"
#include "Employee.h"

// Валидация строк и исключение
class NotEnglishException : public std::runtime_error {
public:
    explicit NotEnglishException(const std::string& field)
        : std::runtime_error("Поле \"" + field + "\" содержит символы не на английском языке") {}
};

bool isEnglishString(const std::string& s);

// Входные функции
int getInputInt();
float getInputFloat();

// Меню и операции
void menu(int* numS, int* numE, Student** s, Employee** e);
void printPersons(int numS, int numE, const Student* s, const Employee* e);
void addStudent(int* numS, Student** s);
void addEmployee(int* numE, Employee** e);
