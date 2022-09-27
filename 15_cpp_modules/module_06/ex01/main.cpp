#include <iostream>
#include <stdint.h>

#include "Data.hpp"

uintptr_t serialize(Data *ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data *deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data *>(raw);
}

int main(void)
{
    std::cout << "New Data pointer initialized with 10" << std::endl;
    Data *ptr = new Data(10);
    std::cout << std::endl;

    uintptr_t serialized = serialize(ptr);
    std::cout << "Serialized value is: " << serialized << std::endl;
    delete ptr;
    std::cout << std::endl;

    Data *ptr2 = deserialize(serialized);
    std::cout << "Deserialized value is: " << ptr2->getValue() << std::endl;

    return (0);
}