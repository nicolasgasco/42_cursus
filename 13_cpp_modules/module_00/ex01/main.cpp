#include <iostream>

#include "Phonebook.class.hpp"

int main(void) {
    PhoneBook phoneBook;

    while (1) {
        std::string cmd;
        std::cout << std::endl
                  << "Insert either ADD, SEARCH or EXIT: ";
        std::getline(std::cin, cmd);
        if (cmd == "ADD") {
            phoneBook.addNewEntry();
        } else if (cmd == "SEARCH") {
            int areContactsToShow = phoneBook.displayAllContacts();
            if (areContactsToShow) {
                phoneBook.promptAndShowEntryByIndex();
            }
        } else if (cmd == "EXIT") {
            return (0);
        }
    }
    return (1);
}