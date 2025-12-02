#pragma once

#include "functions.h"

class Product 
{
public:
    char name[50];
    int price = 0;

    Product()
    {
        name[0] = '\0';
    }

    friend std::ostream& operator<<(std::ostream& os, const Product& p)
    {
        {
            os << p.name << " " << p.price;

            return os;
        }
    }
};