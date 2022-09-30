#include <iostream>
#include "whatever.hpp"

int main(void)
{
    std::cout << "SWAP FUNCTION:" << std::endl;
    std::string s1 = "ciao";
    std::string s2 = "hola";

    std::cout << "s1: " << s1 << std::endl;
    std::cout << "s2: " << s2 << std::endl;
    swap(s1, s2);
    std::cout << "AFTER SWAP:" << std::endl;
    std::cout << "s1: " << s1 << std::endl;
    std::cout << "s2: " << s2 << std::endl;

    std::cout << std::endl;
    std::cout << "MIN FUNCTION:" << std::endl;
    int a = 1;
    int b = 2;
    std::cout << "Min between 1 and 2 is: " << min(a, b) << std::endl;

    a = 30;
    b = -20;
    std::cout << "Min between 30 and -20 is: " << min(a, b) << std::endl;

    a = 100;
    b = 100;
    std::cout << "Min between 100 and 100 is: " << min(a, b) << std::endl;

    std::cout << std::endl;
    std::cout << "MAX FUNCTION:" << std::endl;
    float c = 1.1f;
    float d = 2.8f;
    std::cout << "Max between 1.1 and 2.8 is: " << max(c, d) << std::endl;

    c = 30.02f;
    d = -20.01f;
    std::cout << "Max between 30.02 and -20.01 is: " << max(c, d) << std::endl;

    c = 100.0009f;
    d = 100.0009f;
    std::cout << "Max between 100.0009 and 100.0009 is: " << max(c, d) << std::endl;
    return (0);
}