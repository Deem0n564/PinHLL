#pragma once

#include <iostream>
#include <string>
#include "Person.h"
#include "Student.h"
#include "Employee.h"

int getInputInt();
float getInputFloat();
void menu(int *numS, int *numE, Student **s, Employee **e);
void printPersons(int numS, int numE, const Student *s, const Employee *e);