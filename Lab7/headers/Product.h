#pragma once

#include "functions.h"

class Product 
{
public:
    char name[50];
    int price;

    Product() : price(0) 
    {
        name[0] = '\0';
    }

    friend std::ostream& operator<<(std::ostream& os, const Product& p);
};

std::ostream& operator<<(std::ostream& os, const Product& p);