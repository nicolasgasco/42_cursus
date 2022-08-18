#include <iostream>
#include <iomanip>

#define STD_FORMAT std::setfill(' ') << std::setw(20) << std::left

int main(void)
{
    std::string myString = "HI THIS IS BRAIN";
    std::string *stringPTR = &myString;
    std::string &stringREF = myString;

    std::cout << STD_FORMAT << "String address:" << &myString << std::endl;
    std::cout << STD_FORMAT << "Pointer add: " << stringPTR << std::endl;
    std::cout << STD_FORMAT << "Reference add: " << &stringREF << std::endl;

    std::cout << std::endl;

    std::cout << STD_FORMAT << "String value:" << myString << std::endl;
    std::cout << STD_FORMAT << "Pointer value:" << *stringPTR << std::endl;
    std::cout << STD_FORMAT << "Reference value:" << stringREF << std::endl;
    return (0);
}
