#pragma once

#include <iostream>
#include <string>
#include <algorithm>
#include "Person.h"
#include "Student.h"
#include "Employee.h"
#include "NotEnglishException.h"

bool isEnglishString(std::string& s);
int getInputInt();
float getInputFloat();
void menu(int* numS, int* numE, Student** s, Employee** e);
void printPersons(int numS, int numE, const Student* s, const Employee* e);
void addStudent(int* numS, Student** s);
void addEmployee(int* numE, Employee** e);
