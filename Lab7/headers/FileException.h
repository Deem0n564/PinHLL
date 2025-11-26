#pragma once

#include "functions.h"

class FileException : public std::runtime_error 
{
public:
    using std::runtime_error::runtime_error;
};