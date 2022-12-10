#pragma once

#include <string>
#include <stack>
#include <iostream>
#include <chrono>
#include <iomanip>
#include <cmath>

#include "../vector.hpp"
#include "../stack.hpp"
#include "../pair.hpp"

#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define GREEN "\033[0;32m"
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
template <typename T1, typename T2>
bool isStrictEqual(ft::pair<T1, T2> pair1, std::pair<T1, T2> pair2, bool printValue)
{
    if (printValue)
        std::cout << "=====own===== "
                  << "(" << pair1.first << ", " << pair2.first << ") "
                  << " | "
                  << "(" << pair1.second << ", " << pair2.second << ") "
                                                                    " =====ref====="
                  << std::endl;
    if (pair1.first == pair2.first && pair1.second == pair2.second)
        return true;
    return false;
}

template <typename T1, typename T2>
bool areStacksStrictEqual(ft::stack<T1, T2> ownStack, std::stack<T1, T2> originalStack, bool printValue)
{
    if (ownStack.empty())
    {
        if (printValue)
            std::cout << "=====own===== "
                      << "(empty: " << ownStack.empty() << ", size: " << ownStack.size()
                      << ") "
                      << " | "
                      << "(empty: " << originalStack.empty() << ", size: " << originalStack.size()
                      << ") "
                      << " =====ref====="
                      << std::endl;
        if ((ownStack.empty() == originalStack.empty()) && (ownStack.size() == originalStack.size()))
            return true;
    }
    else
    {
        if (printValue)
            std::cout << "=====own===== "
                      << "(top: " << ownStack.top() << ", empty: " << ownStack.empty() << ", size: " << ownStack.size()
                      << ") "
                      << " | "
                      << "(top: " << originalStack.top() << ", empty: " << originalStack.empty() << ", size: " << originalStack.size()
                      << ") "
                      << " =====ref====="
                      << std::endl;
        if ((ownStack.top() == originalStack.top()) && (ownStack.empty() == originalStack.empty()) && (ownStack.size() == originalStack.size()))
            return true;
    }
    return false;
}

template <typename T1>
bool areStacksStrictEqual(ft::stack<T1> ownStack, std::stack<T1> originalStack, bool printValue)
{
    if (ownStack.empty())
    {
        if (printValue)
            std::cout << "=====own===== "
                      << "(empty: " << ownStack.empty() << ", size: " << ownStack.size()
                      << ") "
                      << " | "
                      << "(empty: " << originalStack.empty() << ", size: " << originalStack.size()
                      << ") "
                      << " =====ref====="
                      << std::endl;
        if ((ownStack.empty() == originalStack.empty()) && (ownStack.size() == originalStack.size()))
            return true;
    }
    else
    {
        if (printValue)
            std::cout << "=====own===== "
                      << "(top: " << ownStack.top() << ", empty: " << ownStack.empty() << ", size: " << ownStack.size()
                      << ") "
                      << " | "
                      << "(top: " << originalStack.top() << ", empty: " << originalStack.empty() << ", size: " << originalStack.size()
                      << ") "
                      << " =====ref====="
                      << std::endl;
        if ((ownStack.top() == originalStack.top()) && (ownStack.empty() == originalStack.empty()) && (ownStack.size() == originalStack.size()))
            return true;
    }
    return false;
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

std::chrono::microseconds getFunctionDuration(void(func1)())
{
#undef TESTED_ENV
#define TESTED_ENV ft
    std::chrono::time_point<std::chrono::high_resolution_clock> start = std::chrono::high_resolution_clock::now();
    func1();
    std::chrono::time_point<std::chrono::high_resolution_clock> stop = std::chrono::high_resolution_clock::now();
    std::chrono::microseconds duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    return duration;
}

void calculateSpeedRatio(void(func1)(), void(func2)(), bool isDebug)
{
    std::chrono::microseconds ownDuration = getFunctionDuration(func1);

    std::chrono::microseconds originalDuration = getFunctionDuration(func2);

    std::cout << " ";

    float ratio;

    long long ownDurationCount = ownDuration.count();
    long long originalDurationCount = originalDuration.count();
    if (ownDurationCount == originalDurationCount)
    {
        std::cout << GREEN << "same speed" << NOCOL;
    }
    else if (ownDurationCount < originalDurationCount)
    {
        ratio = static_cast<float>(originalDurationCount) / static_cast<float>(ownDurationCount);
        std::cout
            << std::fixed << std::setprecision(1) << BLUE << ratio << "x times faster" << NOCOL;
    }
    else if (ownDurationCount > originalDurationCount)
    {
        ratio = static_cast<float>(ownDurationCount) / static_cast<float>(originalDurationCount ? originalDurationCount : 1);
        std::cout << std::fixed << std::setprecision(1) << YELLOW << ratio << "x times slower" << NOCOL;
    }
    if (isDebug)
        std::cout << " (own: " << ownDurationCount << " ms, seed: " << originalDurationCount << " ms)";

    std::cout << std::endl;
}