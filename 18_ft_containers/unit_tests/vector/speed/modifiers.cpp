#include "../../utils.hpp"
#include "../vector.hpp"

void ownAssign()
{
    ft::vector<long> myVector;
    myVector.assign(100000, 42);
}
void seedAssign()
{
    std::vector<long> myVector;
    myVector.assign(100000, 42);
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

void ownInsert()
{
    ft::vector<long> myVector;
    myVector.insert(myVector.begin(), 100000, 42);
}
void seedInsert()
{
    std::vector<long> myVector;
    myVector.insert(myVector.begin(), 100000, 42);
}

void ownErase()
{
    ft::vector<long> myVector(100000, 42);
    myVector.erase(myVector.begin(), myVector.end());
}
void seedErase()
{
    std::vector<long> myVector(100000, 42);
    myVector.erase(myVector.begin(), myVector.end());
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

void modifiersSpeedTest(bool isDebug)
{
    std::cout << std::endl
              << "  MODIFIERS:" << std::endl;
    {
        std::cout << "  - assign 100000 values:";
        calculateSpeedRatio(ownAssign, seedAssign, isDebug);
    }
    {
        std::cout << "  - push_back 100000 times:";
        calculateSpeedRatio(ownPushBack, seedPushBack, isDebug);
    }
    {
        std::cout << "  - pop_back 100000 times:";
        calculateSpeedRatio(ownPopBack, seedPopBack, isDebug);
    }
    {
        std::cout << "  - insert with 100000 values:";
        calculateSpeedRatio(ownInsert, seedInsert, isDebug);
    }
    {
        std::cout << "  - erase with 100000 values:";
        calculateSpeedRatio(ownInsert, seedInsert, isDebug);
    }
    {
        std::cout << "  - swap with 100000 values:";
        calculateSpeedRatio(ownSwap, seedSwap, isDebug);
    }
    {
        std::cout << "  - clear with 100000 values:";
        calculateSpeedRatio(ownClear, seedClear, isDebug);
    }
}