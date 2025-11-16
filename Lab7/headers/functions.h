#pragma once

#include <iostream>
#include <string>
#include"Person.h"
#include "Man.h"
#include "Girl.h"

int getInputInt();
void allocPerson(Person*** arr, int count);
bool readNameAndAge(std::string& name, int& age);
void menu(Person*** people, int& count, const int& choice);