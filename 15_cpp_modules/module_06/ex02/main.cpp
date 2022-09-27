#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
    Base *result;

    switch (std::rand() % 3)
    {
    case (0):
        std::cout << "New A pointer" << std::endl;
        result = new A();
        return result;
    case (1):
        std::cout << "New B pointer" << std::endl;
        result = new B();
        return result;
    case (2):
        std::cout << "New C pointer" << std::endl;
        result = new C();
        return result;
    default:
        std::cout << "new A pointer" << std::endl;
        result = new A();
        return result;
    }
}

void identify(Base *p)
{
    if (dynamic_cast<A *>(p))
        std::cout << "Pointer is A (" << p << ")" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "Pointer is B (" << p << ")" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "Pointer is C (" << p << ")" << std::endl;
    else if (dynamic_cast<Base *>(p))
        std::cout << "Pointer is base (" << p << ")" << std::endl;
    else
        std::cout << "Unknown pointer (" << p << ")" << std::endl;
}

void identify(Base &p)
{
    // A
    try
    {
        A &result = dynamic_cast<A &>(p);
        std::cout << "Pointer is A (" << &result << ")" << std::endl;
        return;
    }
    catch (...)
    {
    }

    // B
    try
    {
        B &result = dynamic_cast<B &>(p);
        std::cout << "Pointer is B (" << &result << ")" << std::endl;
        return;
    }
    catch (...)
    {
    }

    // C
    try
    {
        C &result = dynamic_cast<C &>(p);
        std::cout << "Pointer is C (" << &result << ")" << std::endl;
        return;
    }
    catch (...)
    {
    }

    // std::cout << "Pointer is unknown" << std::endl;
}

int main(void)
{
    std::srand(time(NULL));
    for (int i = 0; i < 10; i++)
    {
        Base *pointer = generate();
        std::cout << std::endl;

        identify(pointer);
        std::cout << std::endl;

        identify(*pointer);

        delete pointer;
        std::cout << "_______________________\n"
                  << std::endl;
    }

    return (0);
}