#include <vector>

#include "utils.hpp"
#include "../../vector/vector.hpp"

void assignUnitTests(bool isDebug)
{
    outputSuiteTitle("ASSIGN OPERATOR");
    std::cout
        << "Values are equal to STL vector value:" << std::endl;
    {
        int values[5] = {1, 2, 3, 4, 5};

        ft::vector<int> seedOwn;
        fillVectorWithValues<int>(seedOwn, values, 5);
        ft::vector<int> own(5, 10);
        own = seedOwn;

        std::vector<int> seedOriginal;
        fillVectorWithValues<int>(seedOriginal, values, 5);
        std::vector<int> original(5, 10);
        original = seedOriginal;
        outputAssertion("after assigning from vector with same size (5):", isStrictEqual<int>(own.data(), original.data(), 5, isDebug));
    }
    {
        int values[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

        ft::vector<int> seedOwn;
        fillVectorWithValues<int>(seedOwn, values, 10);
        ft::vector<int> own(10);
        own = seedOwn;

        std::vector<int> seedOriginal;
        fillVectorWithValues<int>(seedOriginal, values, 10);
        std::vector<int> original(10);
        original = seedOriginal;
        outputAssertion("after assigning from vector with bigger size (5 vs 10):", isStrictEqual<int>(own.data(), original.data(), 10, isDebug));
    }
    {
        int values[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

        ft::vector<int> seedOwn;
        fillVectorWithValues<int>(seedOwn, values, 10);
        ft::vector<int> own;
        own = seedOwn;

        std::vector<int> seedOriginal;
        fillVectorWithValues<int>(seedOriginal, values, 10);
        std::vector<int> original;
        original = seedOriginal;
        outputAssertion("after assigning from vector with bigger size (0 vs 10):", isStrictEqual<int>(own.data(), original.data(), 10, isDebug));
    }
    {

        ft::vector<int> seedOwn;
        seedOwn.push_back(3);
        ft::vector<int> own(10);
        own = seedOwn;

        std::vector<int> seedOriginal;
        seedOriginal.push_back(3);
        std::vector<int> original(10);
        original = seedOriginal;
        outputAssertion("after assigning from vector with smaller size (5 vs 1):", isStrictEqual<int>(own.data(), original.data(), 1, isDebug));
    }

    std::cout << std::endl
              << "Size is equal to STL vector value:" << std::endl;
    {
        int values[5] = {1, 2, 3, 4, 5};

        ft::vector<int> seedOwn;
        fillVectorWithValues<int>(seedOwn, values, 5);
        ft::vector<int> own(5, 10);
        own = seedOwn;

        std::vector<int> seedOriginal;
        fillVectorWithValues<int>(seedOriginal, values, 5);
        std::vector<int> original(5, 10);
        original = seedOriginal;
        outputAssertion("after assigning from vector with same size (5):", isStrictEqual<std::size_t>(own.size(), original.size(), isDebug));
    }
    {
        int values[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

        ft::vector<int> seedOwn;
        fillVectorWithValues<int>(seedOwn, values, 10);
        ft::vector<int> own(10);
        own = seedOwn;

        std::vector<int> seedOriginal;
        fillVectorWithValues<int>(seedOriginal, values, 10);
        std::vector<int> original(10);
        original = seedOriginal;
        outputAssertion("after assigning from vector with bigger size (5 vs 10):", isStrictEqual<std::size_t>(own.size(), original.size(), isDebug));
    }
    {
        int values[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

        ft::vector<int> seedOwn;
        fillVectorWithValues<int>(seedOwn, values, 10);
        ft::vector<int> own;
        own = seedOwn;

        std::vector<int> seedOriginal;
        fillVectorWithValues<int>(seedOriginal, values, 10);
        std::vector<int> original;
        original = seedOriginal;
        outputAssertion("after assigning from vector with bigger size (0 vs 10):", isStrictEqual<std::size_t>(own.size(), original.size(), isDebug));
    }
    {

        ft::vector<int> seedOwn;
        seedOwn.push_back(3);
        ft::vector<int> own(10);
        own = seedOwn;

        std::vector<int> seedOriginal;
        seedOriginal.push_back(3);
        std::vector<int> original(10);
        original = seedOriginal;
        outputAssertion("after assigning from vector with smaller size (5 vs 1):", isStrictEqual<std::size_t>(own.size(), original.size(), isDebug));
    }
    {

        ft::vector<int> seedOwn;
        ft::vector<int> own(10);
        own = seedOwn;

        std::vector<int> seedOriginal;
        std::vector<int> original(10);
        original = seedOriginal;
        outputAssertion("after assigning from vector with smaller size (5 vs 0):", isStrictEqual<std::size_t>(own.size(), original.size(), isDebug));
    }

    std::cout << std::endl
              << "Capacity is equal to STL vector value:" << std::endl;
    {
        int values[5] = {1, 2, 3, 4, 5};

        ft::vector<int> seedOwn;
        fillVectorWithValues<int>(seedOwn, values, 5);
        ft::vector<int> own(5, 10);
        own = seedOwn;

        std::vector<int> seedOriginal;
        fillVectorWithValues<int>(seedOriginal, values, 5);
        std::vector<int> original(5, 10);
        original = seedOriginal;
        outputAssertion("after assigning from vector with same size (5):", isStrictEqual<std::size_t>(own.capacity(), original.capacity(), isDebug));
    }
    {
        int values[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

        ft::vector<int> seedOwn;
        fillVectorWithValues<int>(seedOwn, values, 10);
        ft::vector<int> own(10);
        own = seedOwn;

        std::vector<int> seedOriginal;
        fillVectorWithValues<int>(seedOriginal, values, 10);
        std::vector<int> original(10);
        original = seedOriginal;
        outputAssertion("after assigning from vector with bigger size (5 vs 10):", isStrictEqual<std::size_t>(own.capacity(), original.capacity(), isDebug));
    }
    {
        int values[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

        ft::vector<int> seedOwn;
        fillVectorWithValues<int>(seedOwn, values, 10);
        ft::vector<int> own;
        own = seedOwn;

        std::vector<int> seedOriginal;
        fillVectorWithValues<int>(seedOriginal, values, 10);
        std::vector<int> original;
        original = seedOriginal;
        outputAssertion("after assigning from vector with bigger size (0 vs 10):", isStrictEqual<std::size_t>(own.capacity(), original.capacity(), isDebug));
    }
    {

        ft::vector<int> seedOwn;
        seedOwn.push_back(3);
        ft::vector<int> own(10);
        own = seedOwn;

        std::vector<int> seedOriginal;
        seedOriginal.push_back(3);
        std::vector<int> original(10);
        original = seedOriginal;
        outputAssertion("after assigning from vector with smaller size (5 vs 1):", isStrictEqual<std::size_t>(own.capacity(), original.capacity(), isDebug));
    }
    {

        ft::vector<int> seedOwn;
        ft::vector<int> own(10);
        own = seedOwn;

        std::vector<int> seedOriginal;
        std::vector<int> original(10);
        original = seedOriginal;
        outputAssertion("after assigning from vector with smaller size (5 vs 0):", isStrictEqual<std::size_t>(own.capacity(), original.capacity(), isDebug));
    }

    std::cout << std::endl
              << "Max_size is equal to STL vector value:" << std::endl;
    {
        int values[5] = {1, 2, 3, 4, 5};

        ft::vector<int> seedOwn;
        fillVectorWithValues<int>(seedOwn, values, 5);
        ft::vector<int> own(5, 10);
        own = seedOwn;

        std::vector<int> seedOriginal;
        fillVectorWithValues<int>(seedOriginal, values, 5);
        std::vector<int> original(5, 10);
        original = seedOriginal;
        outputAssertion("after assigning from vector with same size (5):", isStrictEqual<std::size_t>(own.max_size(), original.max_size(), isDebug));
    }
    {
        int values[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

        ft::vector<int> seedOwn;
        fillVectorWithValues<int>(seedOwn, values, 10);
        ft::vector<int> own(10);
        own = seedOwn;

        std::vector<int> seedOriginal;
        fillVectorWithValues<int>(seedOriginal, values, 10);
        std::vector<int> original(10);
        original = seedOriginal;
        outputAssertion("after assigning from vector with bigger size (5 vs 10):", isStrictEqual<std::size_t>(own.max_size(), original.max_size(), isDebug));
    }
    {
        int values[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

        ft::vector<int> seedOwn;
        fillVectorWithValues<int>(seedOwn, values, 10);
        ft::vector<int> own;
        own = seedOwn;

        std::vector<int> seedOriginal;
        fillVectorWithValues<int>(seedOriginal, values, 10);
        std::vector<int> original;
        original = seedOriginal;
        outputAssertion("after assigning from vector with bigger size (0 vs 10):", isStrictEqual<std::size_t>(own.max_size(), original.max_size(), isDebug));
    }
    {

        ft::vector<int> seedOwn;
        seedOwn.push_back(3);
        ft::vector<int> own(10);
        own = seedOwn;

        std::vector<int> seedOriginal;
        seedOriginal.push_back(3);
        std::vector<int> original(10);
        original = seedOriginal;
        outputAssertion("after assigning from vector with smaller size (5 vs 1):", isStrictEqual<std::size_t>(own.max_size(), original.max_size(), isDebug));
    }
    {

        ft::vector<int> seedOwn;
        ft::vector<int> own(10);
        own = seedOwn;

        std::vector<int> seedOriginal;
        std::vector<int> original(10);
        original = seedOriginal;
        outputAssertion("after assigning from vector with smaller size (5 vs 0):", isStrictEqual<std::size_t>(own.max_size(), original.max_size(), isDebug));
    }
}