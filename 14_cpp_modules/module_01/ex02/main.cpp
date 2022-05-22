#include <iostream>

int main(void) {
    std::string myString = "HI THIS IS BRAIN";
    std::string * stringPTR = &myString;
    std::string & stringREF = myString;

    std::cout << "String add: " << &myString << std::endl;
    std::cout << "Pointer add: " << stringPTR << std::endl;
    std::cout << "Reference add: " << &stringREF << std::endl;

    std::cout << std::endl;

    std::cout << "String value: " << myString << std::endl;
    std::cout << "Pointer value: " << *stringPTR << std::endl;
    std::cout << "Reference value: " << stringREF << std::endl;
    return (0);
}