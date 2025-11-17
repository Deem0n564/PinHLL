#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <type_traits>
#include <cstdint>
#include "FileReader.h"

void write_mode(const std::string& fname);
void read_mode(const std::string& fname);
