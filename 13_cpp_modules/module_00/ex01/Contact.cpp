#include <iostream>

#include "Contact.class.hpp"

Contact::Contact(void) : _isEmpty(true) {
}

Contact::~Contact(void) {
}

// ************************************************************************** //
//                                                                            //
//                             Adding field                                   //
//                                                                            //
// ************************************************************************** //
void Contact::addSingleField(std::string id) {
    std::string value;
    std::cout << "Insert ";
    if (id == "FIRST") {
        std::cout << "first name: ";
        std::getline(std::cin, value);
        this->firstName = value;
    } else if (id == "LAST") {
        std::cout << "last name: ";
        std::getline(std::cin, value);
        this->lastName = value;
    } else if (id == "NICK") {
        std::cout << "nickname: ";
        std::getline(std::cin, value);
        this->nickName = value;
    } else if (id == "PHONE") {
        std::cout << "phone number: ";
        std::getline(std::cin, value);
        this->phoneNumber = value;
    } else if (id == "SECRET") {
        std::cout << "darkest secret: ";
        std::getline(std::cin, value);
        this->darkestSecret = value;
    }
}

// ************************************************************************** //
//                                                                            //
//                             Get set isEmpty                                //
//                                                                            //
// ************************************************************************** //
bool Contact::getIsEmpty(void) const {
    return (this->_isEmpty);
}

void Contact::setIsEmptyToFalse() {
    this->_isEmpty = false;
}
