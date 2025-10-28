#pragma once

#include <iostream>
#include "functions.h"

void startMenu(int chosenType);
int getInputInt();
float getInputFloat();
double getInputDouble();
void charMenu(int choice, int* size, char** arr);
void intMenu(int choice, int* size, int** arr);
void floatMenu(int choice, int* size, float** arr);
void doubleMenu(int choice, int *size, double **arr);
template <typename T>
void findByKeyTemplate(const T* arr, int size, const T& key)
{
    if (arr == nullptr || size <= 0) return;

    for (int i = 0; i < size; ++i)
    {
        if (arr[i] == key)
        {
            std::cout << " Key is founded on " << i << " element\n";

            return;
        }
    }
}