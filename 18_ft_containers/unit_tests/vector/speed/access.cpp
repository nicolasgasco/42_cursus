#include "../../utils.hpp"
#include "../../../vector.hpp"
#include <vector>

void ownRandomAccessOperator()
{
    ft::vector<char> myVector(100000, 'a');
    myVector[10];
}
void seedRandomAccessOperator()
{
    std::vector<char> myVector(100000, 'a');
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
    ft::vector<std::string> myVector(100000, "foo");
    myVector.front();
}
void seedFront()
{
    std::vector<std::string> myVector(100000, "foo");
    myVector.front();
}

void ownBack()
{
    ft::vector<long> myVector(100000, 10);
    myVector.back();
}
void seedBack()
{
    std::vector<long> myVector(100000, 10);
    myVector.back();
}

void ownData()
{
    ft::vector<float> myVector(100000, 10.10f);
    myVector.data();
}
void seedData()
{
    std::vector<float> myVector(100000, 10.10f);
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
