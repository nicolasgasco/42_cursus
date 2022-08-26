#include <iostream>
#include "Fixed.hpp"

int main(void)
{
    Fixed const a(0.3f);
    Fixed const b(1.1f);

    std::cout << std::boolalpha << std::endl;

    std::cout << "COMPARISON OPERATORS:" << std::endl;
    std::cout << "a > b: " << (a > b) << std::endl;
    std::cout << "a < b: " << (a < b) << std::endl;
    std::cout << "--------------------------------------" << std::endl;
    std::cout << "a >= a: " << (a >= a) << std::endl;
    std::cout << "a <= a: " << (a <= a) << std::endl;
    std::cout << "--------------------------------------" << std::endl;
    std::cout << "a == b: " << (a == b) << std::endl;
    std::cout << "b == b: " << (b == b) << std::endl;
    std::cout << "a == a: " << (a == a) << std::endl;
    std::cout << "--------------------------------------" << std::endl;
    std::cout << "a != b: " << (a != b) << std::endl;
    std::cout << "a != a: " << (a != a) << std::endl;
    std::cout << "b != b: " << (b != b) << std::endl;
    std::cout << std::endl;

    std::cout << "ARITHMETIC OPERATORS:" << std::endl;
    std::cout << "a + b: " << (a + b) << std::endl;
    std::cout << "b - a: " << (b - a) << std::endl;
    std::cout << "b * a: " << (a * b) << std::endl;
    std::cout << "b / a: " << (b / a) << std::endl;

    std::cout << std::endl;
    return 0;
}