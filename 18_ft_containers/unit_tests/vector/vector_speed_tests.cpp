#include <vector>

#include "utils.hpp"
#include "../vector.hpp"

void ownFillConstructor()
{
    ft::vector<int> myVector(100000, 2);
}
void seedFillConstructor()
{
    std::vector<int> myVector(100000, 2);
}

void ownCopyConstructor()
{
    ft::vector<std::string> myVector(100000, "foo");
    ft::vector<std::string> copy = myVector;
}
void seedCopyConstructor()
{
    std::vector<std::string> myVector(100000, "foo");
    std::vector<std::string> copy = myVector;
}

void ownRangeConstructor()
{
    ft::vector<float> myVector(100000, 2.0f);
    std::vector<float> copy(myVector.begin(), myVector.end());
}
void seedRangeConstructor()
{
    std::vector<float> myVector(100000, 2.0f);
    std::vector<float> copy(myVector.begin(), myVector.end());
}

void ownPushBack()
{
    ft::vector<long> myVector;
    for (int i = 0; i < 100000; ++i)
        myVector.push_back(i);
}
void seedPushBack()
{
    std::vector<long> myVector;
    for (int i = 0; i < 100000; ++i)
        myVector.push_back(i);
}

void ownPopBack()
{
    ft::vector<unsigned long> myVector(100000, 1);
    for (int i = 0; i < 100000; ++i)
        myVector.pop_back();
}
void seedPopBack()
{
    std::vector<unsigned long> myVector(100000, 1);
    for (int i = 0; i < 100000; ++i)
        myVector.pop_back();
}

void ownClear()
{
    int values[2] = {1, 2};
    ft::vector<int *> myVector(100000, values);
    myVector.clear();
}
void seedClear()
{
    int values[2] = {1, 2};
    std::vector<int *> myVector(100000, values);
    myVector.clear();
}

void ownSwap()
{
    ft::vector<const char *> myVector1(100000, static_cast<const char *>("bar"));
    ft::vector<const char *> myVector2(100000, static_cast<const char *>("bar"));

    myVector1.swap(myVector2);
}
void seedSwap()
{
    std::vector<const char *> myVector1(100000, static_cast<const char *>("bar"));
    std::vector<const char *> myVector2(100000, static_cast<const char *>("bar"));

    myVector1.swap(myVector2);
}

void ownReserve()
{
    ft::vector<char> myVector;
    myVector.reserve(100000);
}
void seedReserve()
{
    std::vector<char> myVector;
    myVector.reserve(100000);
}

void ownResize()
{
    ft::vector<char> myVector(1, 10);
    myVector.resize(100000, 5);
}
void seedResize()
{
    std::vector<char> myVector(1, 10);
    myVector.resize(100000, 5);
}

void ownSize()
{
    ft::vector<char> myVector(100000, 10);
    myVector.size();
}
void seedSize()
{
    std::vector<char> myVector(100000, 10);
    myVector.size();
}

void speedUnitTests(bool isDebug)
{
    outputSuiteTitle("SPEED:");
    {
        {
            std::cout << "  CONSTRUCTORS:" << std::endl;
            {
                std::cout << "  - Fill constructor with 100000 values:";
                calculateSpeedRatio(ownFillConstructor, seedFillConstructor, isDebug);
            }
            {
                std::cout << "  - Copy constructor with 100000 values:";
                calculateSpeedRatio(ownCopyConstructor, seedCopyConstructor, isDebug);
            }
            {
                std::cout << "  - Range constructor with 100000 values:";
                calculateSpeedRatio(ownRangeConstructor, seedRangeConstructor, isDebug);
            }
        }
        {
            std::cout << std::endl
                      << "  MODIFIERS:" << std::endl;
            {
                std::cout << "  - push_back 100000 times:";
                calculateSpeedRatio(ownPushBack, seedPushBack, isDebug);
            }
            {
                std::cout << "  - pop_back 100000 times:";
                calculateSpeedRatio(ownPopBack, seedPopBack, isDebug);
            }
            {
                std::cout << "  - clear with 100000 values:";
                calculateSpeedRatio(ownClear, seedClear, isDebug);
            }
            {
                std::cout << "  - swap with 100000 values:";
                calculateSpeedRatio(ownSwap, seedSwap, isDebug);
            }
        }
        {
            std::cout << std::endl
                      << "  CAPACITY:" << std::endl;
            {
                std::cout << "  - reserve 100000 elements:";
                calculateSpeedRatio(ownReserve, seedReserve, isDebug);
            }
            {
                std::cout << "  - resize from 1 element to 100000:";
                calculateSpeedRatio(ownResize, seedResize, isDebug);
            }
            {
                std::cout << "  - size of vector with 100000 elements:";
                calculateSpeedRatio(ownSize, seedSize, isDebug);
            }
        }
    }
}
