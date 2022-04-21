#include <iostream>

#include "Contact.class.hpp"

Contact::Contact(void) : _isEmpty(true) {
    std::cout << "Contact constructor" << std::endl;
}

Contact::~Contact(void) {
    std::cout << "Contact destructor" << std::endl;
}

bool Contact::getIsEmpty(void) {
    return (this->_isEmpty);
}

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