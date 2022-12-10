#include "../../utils.hpp"
#include "../../../vector.hpp"
#include <vector>

void sizeUnitTests(bool isDebug)
{
    outputSuiteTitle("SIZE");
    {
        std::cout << "Is initialized equal to STL vector value:" << std::endl;
        {
            ft::vector<int> own;
            std::vector<int> original;
            outputAssertion("with empty constructor:", isStrictEqual<std::size_t>(own.size(), original.size(), isDebug));
        }
        {
            std::allocator<int> alloc = std::allocator<int>();
            ft::vector<int> own(alloc);
            std::vector<int> original(alloc);
            outputAssertion("with empty constructor (custom allocator):", isStrictEqual<std::size_t>(own.size(), original.size(), isDebug));
        }
        {
            ft::vector<int> own(9);
            std::vector<int> original(9);
            outputAssertion("with fill constructor:", isStrictEqual<std::size_t>(own.size(), original.size(), isDebug));
        }
        {
            ft::vector<int> own(9, 5);
            std::vector<int> original(9, 5);
            outputAssertion("with fill constructor + value:", isStrictEqual<std::size_t>(own.size(), original.size(), isDebug));
        }
        {
            std::allocator<int> alloc = std::allocator<int>();
            ft::vector<int> own(9, 5, alloc);
            std::vector<int> original(9, 5, alloc);
            outputAssertion("with fill constructor + value + custom allocator:", isStrictEqual<std::size_t>(own.size(), original.size(), isDebug));
        }
        {
            ft::vector<int> ownRef(10, 5);
            ft::vector<int> own(ownRef.begin(), ownRef.end());

            std::vector<int> originalRef(10, 5);
            std::vector<int> original(originalRef.begin(), originalRef.end());
            outputAssertion("with range constructor + fill constructor (10, 5):", isStrictEqual<std::size_t>(own.size(), original.size(), isDebug));
        }
        {
            ft::vector<int> ownRef;
            ft::vector<int> own(ownRef.begin(), ownRef.end());

            std::vector<int> originalRef;
            std::vector<int> original(originalRef.begin(), originalRef.end());
            outputAssertion("with range constructor + default constructor:", isStrictEqual<std::size_t>(own.size(), original.size(), isDebug));
        }
        {
            std::allocator<int> alloc = std::allocator<int>();

            ft::vector<int> ownRef(10, 5, alloc);
            ft::vector<int> own(ownRef.begin(), ownRef.end());

            std::vector<int> originalRef(10, 5, alloc);
            std::vector<int> original(originalRef.begin(), originalRef.end());
            outputAssertion("with range constructor + fill constructor (10, 5) + custom allocator:", isStrictEqual<std::size_t>(own.size(), original.size(), isDebug));
        }
        {
            ft::vector<int> ownSeed(10, 5);
            ft::vector<int> own(ownSeed);

            std::vector<int> originalSeed(10, 5);
            std::vector<int> original(originalSeed);
            outputAssertion("with copy constructor:", isStrictEqual<bool>(own.size(), original.size(), isDebug));
        }
    }

    {
        std::cout << std::endl
                  << "Is incremented like STL vector value:" << std::endl;
        {
            ft::vector<int> own;
            own.reserve(1);
            own.push_back(1);
            std::vector<int> original;
            original.reserve(1);
            original.push_back(1);
            outputAssertion("after a push_back inside reserved memory:", isStrictEqual<std::size_t>(own.size(), original.size(), isDebug));
        }
        {
            ft::vector<int> own;
            own.push_back(1);
            std::vector<int> original;
            original.push_back(1);
            outputAssertion("after a push_back without memory preservation and capacity = 0:", isStrictEqual<std::size_t>(own.size(), original.size(), isDebug));
        }
        {
            ft::vector<int> own(1, 5);
            own.push_back(1);
            std::vector<int> original(1, 5);
            original.push_back(1);
            outputAssertion("after a push_back without memory preservation and capacity = 1:", isStrictEqual<std::size_t>(own.size(), original.size(), isDebug));
        }
        {
            ft::vector<int> own(2, 5);
            own.push_back(1);
            std::vector<int> original(2, 5);
            original.push_back(1);
            outputAssertion("after a push_back without memory preservation and capacity = 2:", isStrictEqual<std::size_t>(own.size(), original.size(), isDebug));
        }
        {
            ft::vector<int> own(2, 5);
            own.insert(own.begin(), 1);

            std::vector<int> original(2, 5);
            original.insert(original.begin(), 1);
            outputAssertion("after adding 1 value with insert (one value) in a vector with size 2:", isStrictEqual<std::size_t>(own.size(), original.size(), isDebug));
        }
        {
            ft::vector<int> own;
            own.insert(own.begin(), 1);

            std::vector<int> original;
            original.insert(original.begin(), 1);
            outputAssertion("after adding 1 value with insert (one value) in a vector with size 0:", isStrictEqual<std::size_t>(own.size(), original.size(), isDebug));
        }
        {
            ft::vector<int> own(2, 5);
            own.insert(own.begin(), 3, 1);

            std::vector<int> original(2, 5);
            original.insert(original.begin(), 3, 1);
            outputAssertion("after adding 3 values with insert (with n values) in a vector with size 2:", isStrictEqual<std::size_t>(own.size(), original.size(), isDebug));
        }
        {
            ft::vector<int> own;
            own.insert(own.begin(), 0, 1);

            std::vector<int> original;
            original.insert(original.begin(), 0, 1);
            outputAssertion("after adding 0 values with insert (with n values) in a vector with size 0:", isStrictEqual<std::size_t>(own.size(), original.size(), isDebug));
        }
        {
            ft::vector<int> own(2, 5);
            ft::vector<int> ownRef(3, 1);
            own.insert(own.begin(), ownRef.begin(), ownRef.end());

            std::vector<int> original(2, 5);
            std::vector<int> originalRef(3, 1);
            original.insert(original.begin(), originalRef.begin(), originalRef.end());
            outputAssertion("after adding 3 values with insert (with iterators) in a vector with size 2:", isStrictEqual<std::size_t>(own.size(), original.size(), isDebug));
        }
        {
            ft::vector<int> own;
            ft::vector<int> ownRef;
            own.insert(own.begin(), ownRef.begin(), ownRef.end());

            std::vector<int> original;
            std::vector<int> originalRef;
            original.insert(original.begin(), originalRef.begin(), originalRef.end());
            outputAssertion("after adding 0 values with insert (with iterators) in a vector with size 0:", isStrictEqual<std::size_t>(own.size(), original.size(), isDebug));
        }
        {
            int values[10] = {30, 27, 24, 21, 18, 15, 12, 9, 6, 3};

            ft::vector<int> own;
            own.insert(own.end(), 42);
            own.insert(own.begin(), 2, 21);
            own.insert(own.end() - 2, 42);
            own.insert(own.end(), 2, 84);
            own.resize(4);

            ft::vector<int> ownRef(values, values + 10);
            own.insert(own.begin() + 2, ownRef.begin(), ownRef.end());

            std::vector<int> original;
            original.insert(original.end(), 42);
            original.insert(original.begin(), 2, 21);
            original.insert(original.end() - 2, 42);
            original.insert(original.end(), 2, 84);
            original.resize(4);

            std::vector<int> originalRef(values, values + 10);
            original.insert(original.begin() + 2, originalRef.begin(), originalRef.end());
            outputAssertion("after adding 10 values at index 2 with insert (iterators) in a vector with size 4:", isStrictEqual<std::size_t>(own.size(), original.size(), isDebug));
        }
    }

    {
        std::cout << std::endl
                  << "Is incremented after an assign like STL vector value:" << std::endl;
        {
            int values[5] = {1, 2, 3, 4, 5};

            ft::vector<int> own(50, 10);
            own.assign(values, values + 5);

            std::vector<int> original(50, 10);
            original.assign(values, values + 5);

            outputAssertion("after assigning 5 values (iterators) in a vector with size 50:", isStrictEqual<std::size_t>(own.size(), original.size(), isDebug));
        }
        {
            int values[17] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17};

            ft::vector<int> own(63, 10);
            own.assign(values, values + 17);

            std::vector<int> original(63, 10);
            original.assign(values, values + 17);

            outputAssertion("after assigning 17 values (iterators) in a vector with size 63:", isStrictEqual<std::size_t>(own.size(), original.size(), isDebug));
        }
        {
            int values[17] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17};

            ft::vector<int> own;
            own.reserve(17);
            own.assign(values, values + 17);

            std::vector<int> original;
            original.reserve(17);
            original.assign(values, values + 17);

            outputAssertion("after assigning 17 values (iterators) in a vector with reserved capacity of 17:", isStrictEqual<std::size_t>(own.size(), original.size(), isDebug));
        }
        {
            int values[5] = {1, 2, 3, 4, 5};

            ft::vector<int> own(1, 5);
            own.assign(values, values + 5);

            std::vector<int> original(1, 5);
            original.assign(values, values + 5);

            outputAssertion("after assigning 5 values (iterators) in a vector with size 1:", isStrictEqual<std::size_t>(own.capacity(), original.capacity(), isDebug));
        }
        {
            int values[5] = {1, 2, 3, 4, 5};

            ft::vector<int> own;
            own.assign(values, values + 5);

            std::vector<int> original;
            original.assign(values, values + 5);

            outputAssertion("after assigning 5 values (iterators) a vector with size 0:", isStrictEqual<std::size_t>(own.capacity(), original.capacity(), isDebug));
        }
        {
            int values[5] = {1, 2, 3, 4, 5};

            ft::vector<int> own(3, 10);
            own.assign(values, values + 5);

            std::vector<int> original(3, 10);
            original.assign(values, values + 5);

            outputAssertion("after assigning 5 values (iterators) in a vector with size 3:", isStrictEqual<std::size_t>(own.capacity(), original.capacity(), isDebug));
        }
        {
            int values[17] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17};

            ft::vector<int> own(3, 10);
            own.assign(values, values + 17);

            std::vector<int> original(3, 10);
            original.assign(values, values + 17);

            outputAssertion("after assigning 17 values (iterators) in a vector with size 3:", isStrictEqual<std::size_t>(own.capacity(), original.capacity(), isDebug));
        }
        {
            ft::vector<int> own(50, 10);
            own.assign(5, 1);

            std::vector<int> original(50, 10);
            original.assign(5, 1);

            outputAssertion("after assigning 5 values (range) in a vector with size 50:", isStrictEqual<std::size_t>(own.size(), original.size(), isDebug));
        }
        {
            ft::vector<int> own(63, 10);
            own.assign(17, 1);

            std::vector<int> original(63, 10);
            original.assign(17, 1);

            outputAssertion("after assigning 17 values (range) in a vector with size 63:", isStrictEqual<std::size_t>(own.size(), original.size(), isDebug));
        }
        {
            ft::vector<int> own;
            own.reserve(17);
            own.assign(17, 1);

            std::vector<int> original;
            original.reserve(17);
            original.assign(17, 1);

            outputAssertion("after assigning 17 values (range) in a vector with reserved capacity of 17:", isStrictEqual<std::size_t>(own.size(), original.size(), isDebug));
        }
        {
            ft::vector<int> own(1, 5);
            own.assign(5, 1);

            std::vector<int> original(1, 5);
            original.assign(5, 1);

            outputAssertion("after assigning 5 values (range) in a vector with size 1:", isStrictEqual<std::size_t>(own.capacity(), original.capacity(), isDebug));
        }
        {
            ft::vector<int> own;
            own.assign(5, 1);

            std::vector<int> original;
            original.assign(5, 1);

            outputAssertion("after assigning 5 values (range) a vector with size 0:", isStrictEqual<std::size_t>(own.capacity(), original.capacity(), isDebug));
        }
        {
            ft::vector<int> own(3, 10);
            own.assign(5, 1);

            std::vector<int> original(3, 10);
            original.assign(5, 1);

            outputAssertion("after assigning 5 values (range) in a vector with size 3:", isStrictEqual<std::size_t>(own.capacity(), original.capacity(), isDebug));
        }
        {
            ft::vector<int> own(3, 10);
            own.assign(17, 1);

            std::vector<int> original(3, 10);
            original.assign(17, 1);

            outputAssertion("after assigning 17 values (range) in a vector with size 3:", isStrictEqual<std::size_t>(own.capacity(), original.capacity(), isDebug));
        }
    }
    {
        std::cout << std::endl
                  << "Is decremented after a pop_back like STL vector value:" << std::endl;
        {
            ft::vector<int> own(1, 10);
            own.pop_back();
            std::vector<int> original(1, 10);
            original.pop_back();
            outputAssertion("with size = 1:", isStrictEqual<std::size_t>(own.size(), original.size(), isDebug));
        }
        {
            ft::vector<int> own(2, 10);
            own.pop_back();
            std::vector<int> original(2, 10);
            original.pop_back();
            outputAssertion("with size = 2:", isStrictEqual<std::size_t>(own.size(), original.size(), isDebug));
        }
        {
            ft::vector<int> own(3, 10);
            own.pop_back();
            std::vector<int> original(3, 10);
            original.pop_back();
            outputAssertion("with size = 3:", isStrictEqual<std::size_t>(own.size(), original.size(), isDebug));
        }
        {
            ft::vector<int> own(4, 10);
            own.pop_back();
            std::vector<int> original(4, 10);
            original.pop_back();
            outputAssertion("with size = 4:", isStrictEqual<std::size_t>(own.size(), original.size(), isDebug));
        }
    }
    {
        std::cout << std::endl
                  << "Is decremented after a resize like STL vector value:" << std::endl;
        {
            ft::vector<int> own(10, 5);
            own.resize(1);
            std::vector<int> original(10, 5);
            original.resize(1);
            outputAssertion("with size = 10 and resize = 1:", isStrictEqual<std::size_t>(own.size(), original.size(), isDebug));
        }
        {
            ft::vector<int> own(10, 5);
            own.resize(9);
            std::vector<int> original(10, 5);
            original.resize(9);
            outputAssertion("with size = 10 and resize = 9:", isStrictEqual<std::size_t>(own.size(), original.size(), isDebug));
        }
        {
            ft::vector<int> own(1, 5);
            own.resize(0);
            std::vector<int> original(1, 5);
            original.resize(0);
            outputAssertion("with size = 1 and resize = 0:", isStrictEqual<std::size_t>(own.size(), original.size(), isDebug));
        }
    }
    {
        std::cout << std::endl
                  << "Stays constant after a resize like STL vector value:" << std::endl;
        {
            ft::vector<int> own(10, 5);
            own.resize(10);
            std::vector<int> original(10, 5);
            original.resize(10);
            outputAssertion("with size = 10 and resize = 10:", isStrictEqual<std::size_t>(own.size(), original.size(), isDebug));
        }
        {
            ft::vector<int> own;
            own.resize(0);
            std::vector<int> original;
            original.resize(0);
            outputAssertion("with size = 0 and resize = 0:", isStrictEqual<std::size_t>(own.size(), original.size(), isDebug));
        }
        {
            ft::vector<int> own(1, 5);
            own.resize(1);
            std::vector<int> original(1, 5);
            original.resize(1);
            outputAssertion("with size = 1 and resize = 1:", isStrictEqual<std::size_t>(own.size(), original.size(), isDebug));
        }
    }

    {
        std::cout << std::endl
                  << "Is decremented after an erase like STL vector value:" << std::endl;
        {
            ft::vector<int> own(2, 5);
            own.erase(own.begin());

            std::vector<int> original(2, 5);
            original.erase(original.begin());

            outputAssertion("after erasing index 0 (iterator) in a vector with size 2:", isStrictEqual<std::size_t>(own.size(), original.size(), isDebug));
        }
        {
            ft::vector<int> own(2, 5);
            own.erase(own.begin() + 1);

            std::vector<int> original(2, 5);
            original.erase(original.begin() + 1);

            outputAssertion("after erasing index 1 (iterator) in a vector with size 2 (is equal to end()):", isStrictEqual<std::size_t>(own.size(), original.size(), isDebug));
        }
        {
            int values[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

            ft::vector<int> own(values, values + 10);
            own.erase(own.begin() + 9);

            std::vector<int> original(values, values + 10);
            original.erase(original.begin() + 9);

            outputAssertion("after erasing index 9 (iterator) in a vector with size 10 (varied values):", isStrictEqual<std::size_t>(own.size(), original.size(), isDebug));
        }
        {
            ft::vector<int> own(10, 5);
            own.erase(own.begin() + 5);

            std::vector<int> original(10, 5);
            original.erase(original.begin() + 5);

            outputAssertion("after erasing index 5 (iterator) in a vector with size 10:", isStrictEqual<std::size_t>(own.size(), original.size(), isDebug));
        }
        {
            int values[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

            ft::vector<int> own(values, values + 10);
            own.erase(own.begin() + 5);

            std::vector<int> original(values, values + 10);
            original.erase(original.begin() + 5);

            outputAssertion("after erasing index 5 (iterator) in a vector with size 10 (varied values):", isStrictEqual<std::size_t>(own.size(), original.size(), isDebug));
        }
        {
            ft::vector<int> own(2, 5);
            own.erase(own.begin(), own.begin());

            std::vector<int> original(2, 5);
            original.erase(original.begin(), original.begin());

            outputAssertion("after erasing 1 value at index 0 in a vector with size 2:", isStrictEqual<std::size_t>(own.size(), original.size(), isDebug));
        }
        {
            ft::vector<int> own(2, 5);
            own.erase(own.begin() + 1, own.begin() + 1);

            std::vector<int> original(2, 5);
            original.erase(original.begin() + 1, original.begin() + 1);

            outputAssertion("after erasing 1 value at index 1 in a vector with size 2 (is equal to end()):", isStrictEqual<std::size_t>(own.size(), original.size(), isDebug));
        }
        {
            int values[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

            ft::vector<int> own(values, values + 10);
            own.erase(own.begin() + 7, own.begin() + 9);

            std::vector<int> original(values, values + 10);
            original.erase(original.begin() + 7, original.begin() + 9);

            outputAssertion("after erasing 2 values at index 7 in a vector with size 10 (varied values):", isStrictEqual<std::size_t>(own.size(), original.size(), isDebug));
        }
        {
            ft::vector<int> own(10, 5);
            own.erase(own.begin() + 4, own.begin() + 9);

            std::vector<int> original(10, 5);
            original.erase(original.begin() + 4, original.begin() + 9);

            outputAssertion("after erasing 5 values at index 4 in a vector with size 10:", isStrictEqual<std::size_t>(own.size(), original.size(), isDebug));
        }
        {
            int values[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

            ft::vector<int> own(values, values + 10);
            own.erase(own.begin() + 5, own.begin() + 7);

            std::vector<int> original(values, values + 10);
            original.erase(original.begin() + 5, original.begin() + 7);

            outputAssertion("after erasing 2 values at index 5 in a vector with size 10 (varied values):", isStrictEqual<std::size_t>(own.size(), original.size(), isDebug));
        }
        {
            int values[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

            ft::vector<int> own(values, values + 10);
            own.erase(own.begin(), own.begin() + 5);

            std::vector<int> original(values, values + 10);
            original.erase(original.begin(), original.begin() + 5);

            outputAssertion("after erasing 5 values at index 0 in a vector with size 10 (varied values):", isStrictEqual<std::size_t>(own.size(), original.size(), isDebug));
        }
        {
            int values[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

            ft::vector<int> own(values, values + 10);
            own.erase(own.begin() + 1, own.begin() + 9);

            std::vector<int> original(values, values + 10);
            original.erase(original.begin() + 1, original.begin() + 9);

            outputAssertion("after erasing 8 values at index 1 in a vector with size 10 (varied values):", isStrictEqual<std::size_t>(own.size(), original.size(), isDebug));
        }
        {
            ft::vector<int> own(2, 5);
            own.erase(own.begin(), own.begin());

            std::vector<int> original(2, 5);
            original.erase(original.begin(), original.begin());

            outputAssertion("after erasing 1 value at index 0 in a vector with size 2:", isStrictEqual<std::size_t>(own.size(), original.size(), isDebug));
        }
        {
            ft::vector<int> own(2, 5);
            own.erase(own.begin() + 1, own.begin() + 1);

            std::vector<int> original(2, 5);
            original.erase(original.begin() + 1, original.begin() + 1);

            outputAssertion("after erasing 1 value at index 1 in a vector with size 2 (is equal to end()):", isStrictEqual<std::size_t>(own.size(), original.size(), isDebug));
        }
        {
            int values[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

            ft::vector<int> own(values, values + 10);
            own.erase(own.begin() + 7, own.begin() + 9);

            std::vector<int> original(values, values + 10);
            original.erase(original.begin() + 7, original.begin() + 9);

            outputAssertion("after erasing 2 values at index 7 in a vector with size 10 (varied values):", isStrictEqual<std::size_t>(own.size(), original.size(), isDebug));
        }
        {
            ft::vector<int> own(10, 5);
            own.erase(own.begin() + 4, own.begin() + 9);

            std::vector<int> original(10, 5);
            original.erase(original.begin() + 4, original.begin() + 9);

            outputAssertion("after erasing 5 values at index 4 in a vector with size 10:", isStrictEqual<std::size_t>(own.size(), original.size(), isDebug));
        }
        {
            int values[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

            ft::vector<int> own(values, values + 10);
            own.erase(own.begin() + 5, own.begin() + 7);

            std::vector<int> original(values, values + 10);
            original.erase(original.begin() + 5, original.begin() + 7);

            outputAssertion("after erasing 2 values at index 5 in a vector with size 10 (varied values):", isStrictEqual<std::size_t>(own.size(), original.size(), isDebug));
        }
        {
            int values[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

            ft::vector<int> own(values, values + 10);
            own.erase(own.begin(), own.begin() + 5);

            std::vector<int> original(values, values + 10);
            original.erase(original.begin(), original.begin() + 5);

            outputAssertion("after erasing 5 values at index 0 in a vector with size 10 (varied values):", isStrictEqual<std::size_t>(own.size(), original.size(), isDebug));
        }
        {
            int values[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

            ft::vector<int> own(values, values + 10);
            own.erase(own.begin() + 1, own.begin() + 9);

            std::vector<int> original(values, values + 10);
            original.erase(original.begin() + 1, original.begin() + 9);

            outputAssertion("after erasing 8 values at index 1 in a vector with size 10 (varied values):", isStrictEqual<std::size_t>(own.size(), original.size(), isDebug));
        }
    }

    {
        std::cout << std::endl
                  << "Stays constant after an assign like STL vector value:" << std::endl;
        {
            int values[] = {};

            ft::vector<int> own(5, 10);
            own.assign(values, values);

            std::vector<int> original(5, 10);
            original.assign(values, values);

            outputAssertion("after inserting 0 values (iterators) in a vector with size 5:", isStrictEqual<std::size_t>(own.capacity(), original.capacity(), isDebug));
        }
        {
            ft::vector<int> own(5, 10);
            own.assign(0, 1);

            std::vector<int> original(5, 10);
            original.assign(0, 1);

            outputAssertion("after inserting 0 values (range) in a vector with size 5:", isStrictEqual<std::size_t>(own.capacity(), original.capacity(), isDebug));
        }
    }

    {
        std::cout << std::endl
                  << "Is swapped after a ft::swap like STL vector value:" << std::endl;
        {
            ft::vector<int> oneOwn;
            ft::vector<int> twoOwn(5, 2);
            oneOwn.swap(twoOwn);

            std::vector<int> oneOriginal;
            std::vector<int> twoOriginal(5, 2);
            oneOriginal.swap(twoOriginal);
            outputAssertion("with two vectors of different size (0, 5):", isStrictEqual<int>(oneOwn.size(), oneOriginal.size(), isDebug));
        }
        {
            ft::vector<int> oneOwn(5, 2);
            ft::vector<int> twoOwn;
            oneOwn.swap(twoOwn);

            std::vector<int> oneOriginal(5, 2);
            std::vector<int> twoOriginal;
            oneOriginal.swap(twoOriginal);
            outputAssertion("with two vectors of different size (5, 0):", isStrictEqual<int>(oneOwn.size(), oneOriginal.size(), isDebug));
        }
        {
            ft::vector<int> oneOwn(1, 2);
            ft::vector<int> twoOwn(100, 2);
            oneOwn.swap(twoOwn);

            std::vector<int> oneOriginal(1, 2);
            std::vector<int> twoOriginal(100, 2);
            oneOriginal.swap(twoOriginal);
            outputAssertion("with two vectors of different size (1, 100):", isStrictEqual<int>(oneOwn.size(), oneOriginal.size(), isDebug));
        }
        {
            ft::vector<int> oneOwn(1, 2);
            ft::vector<int> twoOwn(1, 2);
            oneOwn.swap(twoOwn);

            std::vector<int> oneOriginal(1, 2);
            std::vector<int> twoOriginal(1, 2);
            oneOriginal.swap(twoOriginal);
            outputAssertion("with two vectors of different size (100, 1):", isStrictEqual<int>(oneOwn.size(), oneOriginal.size(), isDebug));
        }
    }
}
