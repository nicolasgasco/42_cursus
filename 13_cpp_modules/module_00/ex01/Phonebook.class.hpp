#pragma once
#ifndef __PHONE_BOOK_H__
#define __PHONE_BOOK_H__

#include "Contact.class.hpp"

class PhoneBook {
   public:
    Contact contactList[8];

    PhoneBook(void);
    ~PhoneBook(void);

    void addNewEntry(void);

    bool displayAllContacts(void) const;
    void promptAndShowEntryByIndex(void) const;
    void displaySingleEntryDetails(int index) const;

    int getNumberOfValidContacts(void) const;
    int getTotalNumberOfContacts(void) const;

   private:
    int const _totalNumberOfContacts;
};

#endif
