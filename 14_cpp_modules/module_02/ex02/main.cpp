#include <iostream>
#include "Fixed.hpp"

int main(void)
{
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));
    std::cout << a << std::endl;
    // std::cout << ++a << std::endl;
    // std::cout << a << std::endl;
    // std::cout << a++ << std::endl;
    // std::cout << a << std::endl;
    std::cout << b << std::endl;
    // std::cout << Fixed::max(a, b) << std::endl;

    std::cout << std::endl
              << "Testing + operator:" << std::endl;
    Fixed const d(Fixed(5.05f) + Fixed(2));
    std::cout << "D is " << d << std::endl;
    std::cout << std::endl
              << "Testing - operator:" << std::endl;
    Fixed const e(Fixed(5.05f) - Fixed(2));
    std::cout << "E is " << e << std::endl;
    std::cout << std::endl
              << "Testing / operator:" << std::endl;
    Fixed const f(Fixed(5.05f) / Fixed(2));
    std::cout << "F is " << f << std::endl;
    std::cout << std::endl
              << "Testing * operator:" << std::endl;
    Fixed const c(Fixed(5.05f) * Fixed(2));
    std::cout << "C is " << c << std::endl;
    return 0;
}