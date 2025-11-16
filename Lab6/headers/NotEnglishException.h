#pragma once

#include "functions.h"

class NotEnglishException : public std::runtime_error
{
public:
    explicit NotEnglishException(const std::string& field)
        : std::runtime_error("Field \"" + field + "\" contains non English symbols( ") {}
};