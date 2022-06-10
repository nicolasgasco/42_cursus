/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 13:14:49 by ngasco            #+#    #+#             */
/*   Updated: 2022/04/22 13:14:58 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#pragma once
#ifndef __PHONE_BOOK_H__
#define __PHONE_BOOK_H__

#include "Contact.class.hpp"

class PhoneBook
{
public:
    PhoneBook(void);
    ~PhoneBook(void);

    void addNewEntry(void);

    void displayAllContacts(void) const;
    void promptAndShowEntryByIndex(void) const;
    int getNumberOfValidContacts(void) const;

private:
    const int _totalNumberOfContacts;
    Contact _contactsList[8];

    void _outputPopulatedContacts(void) const;
    void _displaySingleEntryDetails(int index) const;
    int _getIndexToInsert(void) const;
};

#endif
