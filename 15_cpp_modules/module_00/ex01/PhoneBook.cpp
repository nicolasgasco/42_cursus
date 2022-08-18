
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
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

PhoneBook::PhoneBook(void) : _totalNumberOfContacts(8)
{
}

PhoneBook::~PhoneBook(void)
{
}

// ************************************************************************** //
//                                                                            //
//                             Adding entry                                   //
//                                                                            //
// ************************************************************************** //
void PhoneBook::addNewEntry(void)
{
    int indexToInsert = this->_getIndexToInsert();
    std::cout << std::endl;
    this->_contactsList[indexToInsert].addSingleField("FIRST");
    this->_contactsList[indexToInsert].addSingleField("LAST");
    this->_contactsList[indexToInsert].addSingleField("NICK");
    this->_contactsList[indexToInsert].addSingleField("PHONE");
    this->_contactsList[indexToInsert].addSingleField("SECRET");

    this->_contactsList[indexToInsert].setIsEmptyToFalse();
}

// ************************************************************************** //
//                                                                            //
//                             Displaying entries                             //
//                                                                            //
// ************************************************************************** //

void outputTruncatedValue(std::string value)
{
    std::cout << std::setfill(' ') << std::setw(10);
    if (value.length() <= 10)
        std::cout << value << "|";
    else
        std::cout << value.substr(0, 9).append(".") << "|";
}

void PhoneBook::_outputPopulatedContacts(void) const
{
    std::cout << ".__________.__________.__________.__________." << std::endl;
    std::cout << "|     index|     first|      last|      nick|" << std::endl;
    std::cout << "|——————————|——————————|——————————|——————————|" << std::endl;

    for (int i = 0; i < this->_totalNumberOfContacts; i++)
    {
        if (this->_contactsList[i].getIsEmpty())
            continue;

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

void PhoneBook::displayAllContacts(void) const
{
    if (this->getNumberOfValidContacts() == 0)
    {
        std::cout << std::endl
                  << "No contacts to show. ADD a new one." << std::endl;
    }
    else
        _outputPopulatedContacts();
}

void PhoneBook::promptAndShowEntryByIndex(void) const
{
    std::string input;

    while (1)
    {
        std::cout << std::endl
                  << "Enter index of entry to show: ";
        std::getline(std::cin, input);

        int indexToShow = std::atoi(input.c_str());
        if (!input.length())
            continue;
        if (indexToShow <= 0 || indexToShow > this->getNumberOfValidContacts() ||
            indexToShow > this->_totalNumberOfContacts)
        {
            std::cout << std::endl
                      << "Invalid index." << std::endl;
            continue;
        }
        this->_displaySingleEntryDetails(indexToShow - 1);
        return;
    }
}

void PhoneBook::_displaySingleEntryDetails(int index) const
{
    std::cout << std::endl;
    std::cout << std::setfill('.') << std::setw(25) << std::left << "FIRST NAME" << this->_contactsList[index].getFirstName() << std::endl;
    std::cout << std::setfill('.') << std::setw(25) << std::left << "LAST NAME" << this->_contactsList[index].getLastName() << std::endl;
    std::cout << std::setfill('.') << std::setw(25) << std::left << "NICKNAME" << this->_contactsList[index].getNickName() << std::endl;
    std::cout << std::setfill('.') << std::setw(25) << std::left << "PHONE NUMBER" << this->_contactsList[index].getPhoneNumber() << std::endl;
    std::cout << std::setfill('.') << std::setw(25) << std::left << "DARKEST SECRET" << this->_contactsList[index].getDarkestSecret() << std::endl;
}

// ************************************************************************** //
//                                                                            //
//                       Getters                                              //
//                                                                            //
// ************************************************************************** //
int PhoneBook::getNumberOfValidContacts(void) const
{
    int numberOfContacts = 0;
    for (int i = 0; i < this->_totalNumberOfContacts; i++)
    {
        if (!this->_contactsList[i].getIsEmpty())
        {
            numberOfContacts++;
        }
    }
    return numberOfContacts;
}

int PhoneBook::_getIndexToInsert(void) const
{
    int indexToInsert = this->getNumberOfValidContacts();
    if (this->getNumberOfValidContacts() >= this->_totalNumberOfContacts)
        return (0);
    else
        return (indexToInsert);
}
