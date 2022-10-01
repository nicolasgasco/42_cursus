#include <stdint.h>

#include <iostream>

#include "Data.hpp"

uintptr_t serialize(Data *ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data *deserialize(uintptr_t raw) {
    return reinterpret_cast<Data *>(raw);
}

int main(void) {
    std::cout << "New Data pointer (ptr) initialized with 10" << std::endl;
    Data *ptr = new Data(10);
    std::cout << std::endl;

    uintptr_t serialized = serialize(ptr);
    std::cout << "Serialized value is: " << serialized << std::endl;
    std::cout << std::endl;

    Data *ptr2 = deserialize(serialized);
    std::cout << "Deserialized value (ptr2) is: " << ptr2->getValue() << std::endl;
    std::cout << std::endl;

    std::cout << "Equality check (ptr2 == ptr): " << std::boolalpha << (ptr2 == ptr) << std::endl;
    std::cout << std::endl;

    delete ptr;

    return (0);
}