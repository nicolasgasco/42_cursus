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

    bool displayAllContacts(void);
    void promptAndShowEntryByIndex(void);
    void displaySingleEntryDetails(int index);

    int getNumberOfValidContacts(void) const;
    int getTotalNumberOfContacts(void) const;

   private:
    int _totalNumberOfContacts;
};

#endif
