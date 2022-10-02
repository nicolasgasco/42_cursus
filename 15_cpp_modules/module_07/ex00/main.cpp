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

    std::cout << std::endl;
    std::cout << "MAIN PROVIDED BY 42" << std::endl;
    a = 2;
    b = 3;
    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
    std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
    std::string c1 = "chaine1";
    std::string d1 = "chaine2";
    ::swap(c1, d1);
    std::cout << "c = " << c1 << ", d = " << d1 << std::endl;
    std::cout << "min( c, d ) = " << ::min(c1, d1) << std::endl;
    std::cout << "max( c, d ) = " << ::max(c1, d1) << std::endl;

    // std::cout << std::endl;
    // Awesome aa(2), bb(4);
    // swap(aa, bb);
    // std::cout << aa << " " << bb << std::endl;
    // std::cout << max(aa, bb) << std::endl;
    // std::cout << min(aa, bb) << std::endl;
    return (0);
}