
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 13:14:49 by ngasco            #+#    #+#             */
/*   Updated: 2022/04/22 13:14:58 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
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
    int indexToInsert = this->_getNumberOfValidContacts();
    if (indexToInsert >= this->_totalNumberOfContacts) {
        indexToInsert = 0;
    }
    std::cout << std::endl;
    this->_contactsList[indexToInsert].addSingleField("FIRST");
    this->_contactsList[indexToInsert].addSingleField("LAST");
    this->_contactsList[indexToInsert].addSingleField("NICK");
    this->_contactsList[indexToInsert].addSingleField("PHONE");
    this->_contactsList[indexToInsert].addSingleField("SECRET");

    if (!this->_contactsList[indexToInsert].getFirstName().length() &&
        !this->_contactsList[indexToInsert].getLastName().length() &&
        !this->_contactsList[indexToInsert].getNickName().length() &&
        !this->_contactsList[indexToInsert].getPhoneNumber().length() &&
        !this->_contactsList[indexToInsert].getDarkestSecret().length()) {
        std::cout << "Empty data. ADD valid contact." << std::endl;
    } else {
        this->_contactsList[indexToInsert].setIsEmptyToFalse();
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

void PhoneBook::_outputPopulatedContacts(void) const {
    std::cout << ".__________.__________.__________.__________." << std::endl;
    std::cout << "|     index|     first|      last|      nick|" << std::endl;
    std::cout << "|——————————|——————————|——————————|——————————|" << std::endl;

    for (int i = 0; i < this->_totalNumberOfContacts; i++) {
        if (this->_contactsList[i].getIsEmpty()) {
            continue;
        }

        std::cout << "|";
        std::cout << std::setfill(' ') << std::setw(10);
        std::cout << i + 1 << "|";
        outputTruncatedValue(this->_contactsList[i].getFirstName());
        outputTruncatedValue(this->_contactsList[i].getLastName());
        outputTruncatedValue(this->_contactsList[i].getNickName());
        std::cout << std::endl;
        std::cout << "|----------|----------|----------|----------|" << std::endl;
    }
}

bool PhoneBook::displayAllContacts(void) const {
    if (this->_getNumberOfValidContacts() == 0) {
        std::cout << std::endl
                  << "No contacts to show. ADD a new one." << std::endl;
        return (false);
    }
    _outputPopulatedContacts();
    return (true);
}

void PhoneBook::promptAndShowEntryByIndex(void) const {
    while (1) {
        std::string input;
        std::cout << std::endl
                  << "Enter index of entry to show: ";
        std::getline(std::cin, input);

        int indexToShow = std::atoi(input.c_str());
        if (indexToShow <= 0 || indexToShow > this->_getNumberOfValidContacts() ||
            indexToShow > this->_totalNumberOfContacts) {
            std::cout << std::endl
                      << "Invalid index." << std::endl;
            continue;
        }
        this->_displaySingleEntryDetails(indexToShow - 1);
        return;
    }
}

void PhoneBook::_displaySingleEntryDetails(int index) const {
    std::cout << std::endl;
    std::cout << "FIRST NAME.........................." << this->_contactsList[index].getFirstName() << std::endl;
    std::cout << "LAST NAME..........................." << this->_contactsList[index].getLastName() << std::endl;
    std::cout << "NICKNAME............................" << this->_contactsList[index].getNickName() << std::endl;
    std::cout << "PHONE NUMBER........................" << this->_contactsList[index].getPhoneNumber() << std::endl;
    std::cout << "DARKEST SECRET......................" << this->_contactsList[index].getDarkestSecret() << std::endl;
}

// ************************************************************************** //
//                                                                            //
//                       Getters num of contacts                        //
//                                                                            //
// ************************************************************************** //
int PhoneBook::_getNumberOfValidContacts(void) const {
    int numberOfContacts = 0;
    for (int i = 0; i < this->_totalNumberOfContacts; i++) {
        if (!this->_contactsList[i].getIsEmpty()) {
            numberOfContacts++;
        }
    }
    return numberOfContacts;
}
