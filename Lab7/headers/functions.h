#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <cstddef>
#include "FileException.h"
#include "FileReader.h"

void addIntToFileEnd(const std::string& filename, int value);
int getInputInt();
size_t getFileSize(const std::string& filename);

void inputIntegerToFile(const std::string& filename);
void readIntegerByIndex(const std::string& filename);
void readByteByIndex(const std::string& filename);