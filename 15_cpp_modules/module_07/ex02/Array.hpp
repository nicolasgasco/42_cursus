#ifndef __ARRAY_HPP__
#define __ARRAY_HPP__
#include <iostream>

#define PURPLE "\033[0;35m"
#define NOCOL "\033[0m"

template <typename T>
class Array {
   public:
    Array(void) {
        values = {};
    }
    Array(Array const &src);

    ~Array(void);

    Array &operator=(Array const &src);

   private:
    T values[];
};

#endif