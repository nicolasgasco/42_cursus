#ifndef __PHONE_BOOK_H__
#define __PHONE_BOOK_H__

#include "Contact.class.hpp"
class PhoneBook {
   public:
    Contact contactList[8];

    PhoneBook(void);
    ~PhoneBook(void);

    void displayAllContacts(void);
    int getNumberOfContacts(void);
    // add new contact
    // search contact
    // Display all contacts
    // Display summary
    // Dsiplay full info

   private:
    int _totalNumberOfContacts;
};

#endif
