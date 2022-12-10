#include "../../utils.hpp"
#include "../../../vector.hpp"
#include <vector>

void ownSize()
{
    ft::vector<char> myVector(100000, 'a');
    myVector.size();
}
void seedSize()
{
    std::vector<char> myVector(100000, 'a');
    myVector.size();
}

void ownMaxSize()
{
    ft::vector<int> myVector(100000, 10);
    myVector.max_size();
}
void seedMaxSize()
{
    std::vector<int> myVector(100000, 10);
    myVector.max_size();
}

void ownCapacitySize()
{
    ft::vector<std::string> myVector(100000, "foo");
    myVector.capacity();
}
void seedCapacitySize()
{
    std::vector<std::string> myVector(100000, "foo");
    myVector.capacity();
}

void ownEmptySize()
{
    ft::vector<unsigned int> myVector(100000, 42);
    myVector.empty();
}
void seedEmptySize()
{
    std::vector<unsigned int> myVector(100000, 42);
    myVector.empty();
}

void ownReserve()
{
    ft::vector<long> myVector;
    myVector.reserve(100000);
}
void seedReserve()
{
    std::vector<long> myVector;
    myVector.reserve(100000);
}

void ownResize()
{
    ft::vector<float> myVector(1, 10.10f);
    myVector.resize(100000, 5);
}
void seedResize()
{
    std::vector<float> myVector(1, 10.10f);
    myVector.resize(100000, 5);
}

void capacitySpeedTest(bool isDebug)
{
    std::cout << std::endl
              << "  CAPACITY:" << std::endl;
    {
        std::cout << "  - size of vector with 100000 elements:";
        calculateSpeedRatio(ownSize, seedSize, isDebug);
    }
    {
        std::cout << "  - max_size of vector with 100000 elements:";
        calculateSpeedRatio(ownMaxSize, seedMaxSize, isDebug);
    }
    {
        std::cout << "  - resize from 1 element to 100000:";
        calculateSpeedRatio(ownCapacitySize, seedCapacitySize, isDebug);
    }
    {
        std::cout << "  - capacity of vector with 100000 elements:";
        calculateSpeedRatio(ownResize, seedResize, isDebug);
    }
    {
        std::cout << "  - empty of vector with 100000 elements:";
        calculateSpeedRatio(ownEmptySize, seedEmptySize, isDebug);
    }
    {
        std::cout << "  - reserve 100000 elements:";
        calculateSpeedRatio(ownReserve, seedReserve, isDebug);
    }
}
