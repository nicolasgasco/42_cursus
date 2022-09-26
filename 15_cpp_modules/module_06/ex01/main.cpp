#include <iostream>
#include <stdint.h>

#include "Data.hpp"

uintptr_t serialize(Data *ptr)
{
    return static_cast<uintptr_t>(*ptr);
}

Data *deserialize(uintptr_t raw)
{
    return new Data(raw);
}

int main(void)
{
    Data *ptr = new Data(10);

    uintptr_t serialized = serialize(ptr);
    std::cout << serialized << std::endl;
    delete ptr;

    Data *ptr2 = deserialize(serialized);
    std::cout << ptr2->getValue() << std::endl;
    delete ptr2;

    return (0);
}