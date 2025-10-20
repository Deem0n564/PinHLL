#pragma once

#include <iostream>
#include <string>
#include"Person.h"
#include "Man.h"
#include "Girl.h"

int getInputInt();
void allocPerson(Person*** arr, int count);
void menu(Person*** people, int& count, int& choice);