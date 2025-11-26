#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <cstddef>
#include "FileException.h"
#include "FileReader.h"

void addIntToFileEnd(const std::string& filename, int value);
size_t getFileSize(const std::string& filename);