#pragma once

#include <string>
#include <iostream>
#include "../vector.hpp"

#define YELLOW "\033[0;33m"
#define NOCOL "\033[0m"

void outputAssertion(std::string description, bool value)
{
    bool isErr = value != true;
    std::cout << "  - " << description << " " << (isErr ? "❌" : "✅") << std::endl;
    if (isErr)
        exit(1);
}

void outputSuiteTitle(std::string title)
{
    std::cout << std::endl
              << YELLOW << title << NOCOL << std::endl;
}

template <typename T>
bool isStrictEqual(T const &value, T const &reference, bool printValue)
{
    if (printValue)
        std::cout << std::boolalpha << "=====own===== " << value << " | " << reference << " =====ref=====" << std::endl;
    return (value == reference) ? true : false;
}
template <typename T>
bool isStrictEqual(T value, T reference)
{
    return (value == reference) ? true : false;
}
template <typename T>
bool isStrictEqual(T const *ownArr, T const *refArr, unsigned int len, bool printValue)
{
    for (unsigned int i = 0; i < len; ++i)
    {
        if (printValue)
            std::cout << ownArr[i] << " | " << refArr[i] << std::endl;
        if (ownArr[i] != refArr[i])
            return false;
    }
    return true;
}

template <typename T, typename V>
T returnPopulatedVector(int numOfEls, V value)
{
    T vector;
    for (int i = 0; i < numOfEls; ++i)
        vector.push_back(value);
    return vector;
}

template <typename T>
bool isConst(T &x)
{
    if (x)
    {
        // Not used
    }
    return false;
}
template <typename T>
bool isConst(T const &x)
{
    if (x)
    {
        // Not used
    }
    return true;
}

template <typename T>
void fillVectorWithValues(ft::vector<T> &vector, T valuesArray[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        vector.push_back(valuesArray[i]);
    }
}

template <typename T>
void fillVectorWithValues(std::vector<T> &vector, T valuesArray[], int size)
{
    for (int i = 0; i < size; ++i)
        vector.push_back(valuesArray[i]);
}