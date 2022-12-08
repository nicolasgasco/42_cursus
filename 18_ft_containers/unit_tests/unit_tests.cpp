
#include <iostream>
#include "algorithms/algorithms_tests.cpp"
#include "reverse_iterator/reverse_iterator.cpp"
#include "pair/pair.cpp"
#include "pair/make_pair.cpp"
#include "vector/vector_tests.cpp"
#include "stack/stack.cpp"

int main(int argc, char *argv[])
{
    bool IS_DEBUG = false;
    if (argc > 1)
        IS_DEBUG = (static_cast<std::string>(argv[1]) == "debug") ? true : false;

    // ALGORITHMS
    algorithmsUnitTests(IS_DEBUG);

    // PAIR
    pairUnitTests(IS_DEBUG);
    makePairUnitTests(IS_DEBUG);

    // REVERSE ITERATOR
    reverseIteratorUnitTests(IS_DEBUG);

    // VECTOR
    vectorUnitTests(IS_DEBUG);

    // STACK
    stackUnitTests(IS_DEBUG);

    std::cout << std::endl;
    return (0);
}