#ifndef NUM_CONVERTER_H
#define NUM_CONVERTER_H

#include <iostream>
#include <string>
#include <math.h>

void fill_array(char *str, char unit, size_t length)
{
    std::cout << "scsc\n";
    memset(str, unit, length);
}

template<typename T>
void fill_array(T *arr, T unit, size_t length)
{
    for (size_t i = 0; i < length; i++) arr[i] = unit;
}

void print_array(char *arr, size_t length)
{
    for (size_t i = 0; i < length - 1; i++) std::cout << arr[i] << std::string(", ");
    std::cout << arr[length - 1] << std::string(";");
}

template<typename T>
void print_array(T *arr, size_t length)
{
    for (size_t i = 0; i < length - 1; i++) std::cout << arr[i] << std::string(", ");
    std::cout << arr[length - 1] << std::string(";");
}

#endif
