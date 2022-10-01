#include <iostream>

#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"

#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define NOCOL "\033[0m"

Base *generate(void) {
    Base *result;

    switch (std::rand() % 3) {
        case (0):
            std::cout << GREEN << "New A pointer" << NOCOL << std::endl;
            result = new A();
            return result;
        case (1):
            std::cout << YELLOW << "New B pointer" << NOCOL << std::endl;
            result = new B();
            return result;
        case (2):
            std::cout << BLUE << "New C pointer" << NOCOL << std::endl;
            result = new C();
            return result;
        default:
            std::cout << GREEN << "new A pointer" << NOCOL << std::endl;
            result = new A();
            return result;
    }
}

void identify(Base *p) {
    if (dynamic_cast<A *>(p))
        std::cout << GREEN << "Pointer is A (" << p << ")" << NOCOL << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << YELLOW << "Pointer is B (" << p << ")" << NOCOL << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << BLUE << "Pointer is C (" << p << ")" << NOCOL << std::endl;
    else
        std::cout << "Unknown pointer (" << p << ")" << NOCOL << std::endl;
}

void identify(Base &p) {
    // A
    try {
        A &result = dynamic_cast<A &>(p);
        std::cout << GREEN << "Pointer is A (" << &result << ")" << NOCOL << std::endl;
        return;
    } catch (...) {
    }

    // B
    try {
        B &result = dynamic_cast<B &>(p);
        std::cout << YELLOW << "Pointer is B (" << &result << ")" << NOCOL << std::endl;
        return;
    } catch (...) {
    }

    // C
    try {
        C &result = dynamic_cast<C &>(p);
        std::cout << BLUE << "Pointer is C (" << &result << ")" << NOCOL << std::endl;
        return;
    } catch (...) {
    }

    std::cout << "Pointer is unknown" << std::endl;
}

int main(void) {
    std::srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        Base *pointer = generate();
        std::cout << std::endl;

        identify(pointer);
        std::cout << std::endl;

        identify(*pointer);

        delete pointer;
        std::cout << "__________________________________\n"
                  << std::endl;
    }

    return (0);
}