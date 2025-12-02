#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <cstddef>
#include <cstring>
#include <stdexcept>
#include "FileException.h"
#include "FileReader.h"
#include "Product.h"

template<typename T>
void addObjectToFileEnd(const std::string& filename, const T& value);
template<typename T>
size_t getFileObjectCount(const std::string& filename);

int getInputInt();
size_t getFileSize(const std::string& filename);
void inputObjectToFile(const std::string& filename);
void readObjectByIndex(const std::string& filename);
void inputString(char* str, int size);
Product inputProduct();
void printProduct(const Product& p);