#include "../../utils.hpp"
#include "../vector.hpp"

void ownRandomAccessOperator()
{
    ft::vector<char> myVector(100000, 10);
    myVector[10];
}
void seedRandomAccessOperator()
{
    std::vector<char> myVector(100000, 10);
    myVector[10];
}

void ownAtOperator()
{
    ft::vector<int> myVector(100000, 10);
    myVector.at(10);
}
void seedAtOperator()
{
    std::vector<int> myVector(100000, 10);
    myVector.at(10);
}

void ownFront()
{
    ft::vector<int> myVector(100000, 10);
    myVector.front();
}
void seedFront()
{
    std::vector<int> myVector(100000, 10);
    myVector.front();
}

void ownBack()
{
    ft::vector<int> myVector(100000, 10);
    myVector.back();
}
void seedBack()
{
    std::vector<int> myVector(100000, 10);
    myVector.back();
}

void ownData()
{
    ft::vector<int> myVector(100000, 10);
    myVector.data();
}
void seedData()
{
    std::vector<int> myVector(100000, 10);
    myVector.data();
}

void accessSpeedTest(bool isDebug)
{
    std::cout << std::endl
              << "  ACCESS:" << std::endl;
    {
        std::cout << "  - [] operator:";
        calculateSpeedRatio(ownRandomAccessOperator, seedRandomAccessOperator, isDebug);
    }
    {
        std::cout << "  - at:";
        calculateSpeedRatio(ownAtOperator, seedAtOperator, isDebug);
    }
    {
        std::cout << "  - front:";
        calculateSpeedRatio(ownFront, seedFront, isDebug);
    }
    {
        std::cout << "  - back:";
        calculateSpeedRatio(ownBack, seedBack, isDebug);
    }
    {
        std::cout << "  - data:";
        calculateSpeedRatio(ownData, seedData, isDebug);
    }
}
