#ifndef __PHONE_BOOK_H__
#define __PHONE_BOOK_H__

#include "Contact.class.hpp"
class PhoneBook {
   public:
    Contact contactList[8];

    PhoneBook(void);
    ~PhoneBook(void);

    void displayAllContacts(void);

    int getNumberOfValidContacts(void);
    int getTotalNumberOfContacts(void);

    void promptAndShowSingleEntry(void);
    void displaySingleEntryDetails(int index);

    void addNewEntry(void);

   private:
    int _totalNumberOfContacts;
};

#endif
