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
        this->setFirstName(value);
    } else if (id == "LAST") {
        std::cout << "last name: ";
        std::getline(std::cin, value);
        this->setLastName(value);
    } else if (id == "NICK") {
        std::cout << "nickname: ";
        std::getline(std::cin, value);
        this->setNickName(value);
    } else if (id == "PHONE") {
        std::cout << "phone number: ";
        std::getline(std::cin, value);
        this->setPhoneNumber(value);
    } else if (id == "SECRET") {
        std::cout << "darkest secret: ";
        std::getline(std::cin, value);
        this->setDarkestSecret(value);
    }
}

// ************************************************************************** //
//                                                                            //
//                             Set properties                                 //
//                                                                            //
// ************************************************************************** //
void Contact::setFirstName(std::string firstName) {
    this->firstName = firstName;
}

void Contact::setLastName(std::string lastName) {
    this->lastName = lastName;
}

void Contact::setNickName(std::string nickName) {
    this->nickName = nickName;
}

void Contact::setPhoneNumber(std::string phoneNumber) {
    this->phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(std::string darkestSecret) {
    this->darkestSecret = darkestSecret;
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
