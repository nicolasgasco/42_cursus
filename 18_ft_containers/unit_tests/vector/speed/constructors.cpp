#include "../../utils.hpp"
#include "../vector.hpp"

void ownDefaultConstructor()
{
    ft::vector<int **> myVector;
}
void seedDefaultConstructor()
{
    std::vector<int **> myVector;
}

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
    ft::vector<float> copy(myVector.begin(), myVector.end());
}
void seedRangeConstructor()
{
    std::vector<float> myVector(100000, 2.0f);
    std::vector<float> copy(myVector.begin(), myVector.end());
}

void constructorsSpeedTest(bool isDebug)
{
    std::cout << "  CONSTRUCTORS:" << std::endl;
    {
        std::cout << "  - Default constructor:";
        calculateSpeedRatio(ownDefaultConstructor, seedDefaultConstructor, isDebug);
    }
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
