#include <iostream>

#include "Phonebook.class.hpp"

PhoneBook::PhoneBook(void) : _totalNumberOfContacts(8) {
    std::cout << "PhoneBook constructor" << std::endl;
}

PhoneBook::~PhoneBook(void) {
    std::cout << "PhoneBook destructor" << std::endl;
    return;
}

void PhoneBook::displayAllContacts(void) {
    if (this->getNumberOfContacts() == 0) {
        std::cout << "No contacts to show. ADD a new one." << std::endl;
    } else {
        std::cout << "Show contacts" << std::endl;
    }
}

int PhoneBook::getNumberOfContacts(void) {
    int numberOfContacts = 0;
    for (int i = 0; i < this->_totalNumberOfContacts; i++) {
        if (!this->contactList[i].getIsEmpty()) {
            numberOfContacts++;
        }
    }
    return numberOfContacts;
}