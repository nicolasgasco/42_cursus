
#include <iostream>
#include "vector/vector_tests.cpp"
#include "algorithms/algorithms_tests.cpp"

int main(int argc, char *argv[])
{
    bool IS_DEBUG = false;
    if (argc > 1)
        IS_DEBUG = (static_cast<std::string>(argv[1]) == "debug") ? true : false;

    // ALGORITHMS
    algorithmsUnitTests(IS_DEBUG);

    // VECTOR
    vectorUnitTests(IS_DEBUG);

    std::cout << std::endl;
    return (0);
}