#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <cstddef>
#include "FileException.h"
#include "FileReader.h"

void addIntToFileEnd(const std::string& filename, int value);
int getFileSize(const std::string& filename);