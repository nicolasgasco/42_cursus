#include <iostream>
#include <string>

#include "iter.hpp"

void outputToUpper(std::string const &str)
{
    std::cout << "- ";
    for (unsigned int i = 0; i < str.length(); i++)
    {
        std::cout << static_cast<char>(toupper(str[i]));
    }
    std::cout << std::endl;
}

// class Awesome
// {
// public:
//     Awesome(void) : _n(42) { return; }
//     int get(void) const { return this->_n; }

// private:
//     int _n;
// };
// std::ostream &operator<<(std::ostream &o, Awesome const &rhs)
// {
//     o << rhs.get();
//     return o;
// }
// template <typename T>
// void print(T const &x)
// {
//     std::cout << x << std::endl;
//     return;
// }

int main(void)
{
    std::cout << "STRING ARRAY:" << std::endl;

    std::string strArr[] = {"ciao", "hola", "hallo"};

    std::cout << "Apply template function:" << std::endl;
    iter(strArr, sizeof(strArr) / sizeof(std::string), outputArrayValue);
    std::cout << std::endl;

    std::cout << "Apply outPutToUpper:" << std::endl;
    iter(strArr, sizeof(strArr) / sizeof(std::string), outputToUpper);
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << "INT ARRAY:" << std::endl;

    int intArr[] = {2, 3, 4};

    iter(intArr, sizeof(intArr) / sizeof(int), outputArrayValue);

    std::cout << std::endl;
    std::cout << "FLOAT ARRAY:" << std::endl;

    float floatArr[] = {2.1f, 3.4f, 4.7f};

    iter(floatArr, sizeof(floatArr) / sizeof(float), outputArrayValue);

    std::cout << std::endl;
    std::cout << "DOUBLE ARRAY:" << std::endl;

    double doubleArray[] = {253445234545, 234542352345, 6787867868};

    iter(doubleArray, sizeof(doubleArray) / sizeof(double), outputArrayValue);

    std::cout << std::endl;
    std::cout << "CHAR ARRAY:" << std::endl;

    char charArray[] = {'a', 'b', 'c'};

    iter(charArray, sizeof(charArray) / sizeof(char), outputArrayValue);

    std::cout << std::endl;
    // int tab[] = {0, 1, 2, 3, 4}; // <--- I never understood why you can't write int[] tab. Wouldn't that make more sense?
    // Awesome tab2[5];
    // iter(tab, 5, print);
    // iter(tab2, 5, print);

    return (0);
}