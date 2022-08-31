#include <iostream>
#include "Fixed.hpp"

int main(void)
{
    Fixed a(0.3f);
    Fixed b(1.0f);
    Fixed c(3.02f);

    std::cout << std::boolalpha;

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
    std::cout << "a + b + c: " << (a + b + c) << std::endl;
    std::cout << "c - b - a: " << (c - b - a) << std::endl;
    std::cout << "b * a * c: " << (a * b * c) << std::endl;
    std::cout << "c * b: " << (c * b) << std::endl;
    std::cout << "c * a: " << (c * a) << std::endl;
    std::cout << "c / a / b: " << (c / a / b) << std::endl;
    std::cout << "b / a: " << (b / a) << std::endl;
    std::cout << "c / b: " << (c / b) << std::endl;
    std::cout << "c / a: " << (c / a) << std::endl;

    std::cout << std::endl;
    std::cout << "INCREMENT OPERATORS:" << std::endl;
    std::cout << "b before incrementing: " << b << std::endl;
    std::cout << "++b: " << ++b << std::endl;
    std::cout << "b after pre-increment: " << b << std::endl;
    std::cout << "b++: " << b++ << std::endl;
    std::cout << "b after post-increment: " << b << std::endl;

    std::cout << std::endl;
    std::cout << "DECREMENT OPERATORS:" << std::endl;
    std::cout << "b before decrementing: " << b << std::endl;
    std::cout << "--b: " << --b << std::endl;
    std::cout << "b after pre-decrement: " << b << std::endl;
    std::cout << "b--: " << b-- << std::endl;
    std::cout << "b after post-decrement: " << b << std::endl;

    std::cout << std::endl;
    std::cout << "MIN:" << std::endl;
    std::cout
        << "Value of a is: " << a << std::endl;
    std::cout
        << "Value of b is: " << b << std::endl;
    std::cout
        << "Min (member) between a and b: " << Fixed::min(a, b) << std::endl;
    std::cout
        << "Min (overload) between a and b: " << Fixed::min((Fixed const)a, (Fixed const)b) << std::endl;

    std::cout << std::endl;
    std::cout << "MAX:" << std::endl;
    std::cout
        << "Value of a is: " << a << std::endl;
    std::cout
        << "Value of b is: " << b << std::endl;
    std::cout
        << "Max (member) between a and b: " << Fixed::max(a, b) << std::endl;
    std::cout
        << "Max (overload) between a and b: " << Fixed::max((Fixed const)a, (Fixed const)b) << std::endl;

    std::cout << std::endl;
    return 0;
}