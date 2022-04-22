#include <stdlib.h>

#include <iomanip>
#include <iostream>

#include "Phonebook.class.hpp"

PhoneBook::PhoneBook(void) : _totalNumberOfContacts(8) {
}

PhoneBook::~PhoneBook(void) {
}

// ************************************************************************** //
//                                                                            //
//                             Adding entry                                   //
//                                                                            //
// ************************************************************************** //
void PhoneBook::addNewEntry(void) {
    int indexToInsert = this->getNumberOfValidContacts();
    if (indexToInsert >= this->getTotalNumberOfContacts()) {
        indexToInsert = 0;
    }
    std::cout << std::endl;
    this->contactList[indexToInsert].addSingleField("FIRST");
    this->contactList[indexToInsert].addSingleField("LAST");
    this->contactList[indexToInsert].addSingleField("NICK");
    this->contactList[indexToInsert].addSingleField("PHONE");
    this->contactList[indexToInsert].addSingleField("SECRET");

    if (!this->contactList[indexToInsert].firstName.length() &&
        !this->contactList[indexToInsert].lastName.length() &&
        !this->contactList[indexToInsert].nickName.length() &&
        !this->contactList[indexToInsert].phoneNumber.length() &&
        !this->contactList[indexToInsert].darkestSecret.length()) {
        std::cout << "Empty data. ADD valid contact." << std::endl;
    } else {
        this->contactList[indexToInsert].setIsEmptyToFalse();
    }
}

// ************************************************************************** //
//                                                                            //
//                             Displaying entries                             //
//                                                                            //
// ************************************************************************** //

void outputTruncatedValue(std::string value) {
    std::cout << std::setfill(' ') << std::setw(10);
    if (value.length() <= 10) {
        std::cout << value << "|";
    } else {
        std::cout << value.substr(0, 9).append(".") << "|";
    }
}

void outputPopulatedContacts(const PhoneBook *instance) {
    std::cout << ".__________.__________.__________.__________." << std::endl;
    std::cout << "|     index|     first|      last|      nick|" << std::endl;
    std::cout << "|——————————|——————————|——————————|——————————|" << std::endl;

    for (int i = 0; i < instance->getTotalNumberOfContacts(); i++) {
        if (instance->contactList[i].getIsEmpty()) {
            continue;
        }

        std::cout << "|";
        std::cout << std::setfill(' ') << std::setw(10);
        std::cout << i + 1 << "|";
        outputTruncatedValue(instance->contactList[i].firstName);
        outputTruncatedValue(instance->contactList[i].lastName);
        outputTruncatedValue(instance->contactList[i].nickName);
        std::cout << std::endl;
        std::cout << "|----------|----------|----------|----------|" << std::endl;
    }
}

bool PhoneBook::displayAllContacts(void) const {
    if (this->getNumberOfValidContacts() == 0) {
        std::cout << std::endl
                  << "No contacts to show. ADD a new one." << std::endl;
        return (false);
    }
    outputPopulatedContacts(this);
    return (true);
}

void PhoneBook::promptAndShowEntryByIndex(void) const {
    while (1) {
        std::string input;
        std::cout << std::endl
                  << "Enter index of entry to show: ";
        std::getline(std::cin, input);

        int indexToShow = atoi(input.c_str());
        if (indexToShow <= 0 || indexToShow > this->getNumberOfValidContacts() ||
            indexToShow > this->getTotalNumberOfContacts()) {
            std::cout << std::endl
                      << "Invalid index." << std::endl;
            continue;
        }
        this->displaySingleEntryDetails(indexToShow - 1);
        return;
    }
}

void PhoneBook::displaySingleEntryDetails(int index) const {
    std::cout << std::endl;
    std::cout << "FIRST NAME.........................." << this->contactList[index].firstName << std::endl;
    std::cout << "LAST NAME..........................." << this->contactList[index].lastName << std::endl;
    std::cout << "NICKNAME............................" << this->contactList[index].nickName << std::endl;
    std::cout << "PHONE NUMBER........................" << this->contactList[index].phoneNumber << std::endl;
    std::cout << "DARKEST SECRET......................" << this->contactList[index].darkestSecret << std::endl;
}

// ************************************************************************** //
//                                                                            //
//                       Getters num of contacts                        //
//                                                                            //
// ************************************************************************** //
int PhoneBook::getNumberOfValidContacts(void) const {
    int numberOfContacts = 0;
    for (int i = 0; i < this->_totalNumberOfContacts; i++) {
        if (!this->contactList[i].getIsEmpty()) {
            numberOfContacts++;
        }
    }
    return numberOfContacts;
}

int PhoneBook::getTotalNumberOfContacts(void) const {
    return this->_totalNumberOfContacts;
}