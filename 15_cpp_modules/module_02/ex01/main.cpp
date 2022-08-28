#include <iostream>
#include "Fixed.hpp"

int main(void)
{
    Fixed a;
    Fixed const b(10);
    Fixed const c(42.43f); // FPV should be 10862
    Fixed const d(b);

    a = Fixed(1234.4321f); // FPV should be 316015

    // More float examples
    Fixed const e(24885.438943f); // FVP should be 6370672
    Fixed const f(0.0f);          // FVP should be 0
    Fixed const g(0.025f);        // FVP should be 6
    Fixed const h(33.3333f);      // FVP should be 8533
    Fixed const i(12345.54321f);  // FVP should be 3160459
    Fixed const l(0.99f);         // FVP should be 253

    std::cout << std::endl;

    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;
    std::cout << "e is " << e << std::endl;
    std::cout << "f is " << f << std::endl;
    std::cout << "g is " << g << std::endl;
    std::cout << "h is " << h << std::endl;
    std::cout << "i is " << i << std::endl;
    std::cout << "l is " << l << std::endl;

    std::cout << std::endl;

    std::cout
        << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;
    std::cout << "e is " << e.toInt() << " as integer" << std::endl;
    std::cout << "f is " << f.toInt() << " as integer" << std::endl;
    std::cout << "g is " << g.toInt() << " as integer" << std::endl;
    std::cout << "h is " << h.toInt() << " as integer" << std::endl;
    std::cout << "i is " << i.toInt() << " as integer" << std::endl;
    std::cout << "l is " << l.toInt() << " as integer" << std::endl;

    std::cout << std::endl;

    return 0;
}