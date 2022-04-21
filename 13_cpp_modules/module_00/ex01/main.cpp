#include <iostream>

#include "Phonebook.class.hpp"

int main(void) {
    PhoneBook phoneBook;

    while (1) {
        std::string cmd;
        std::cout << "Insert either ADD, SEARCH or EXIT: ";
        std::getline(std::cin, cmd);
        if (cmd == "ADD") {
            phoneBook.addNewEntry();
        } else if (cmd == "SEARCH") {
            phoneBook.displayAllContacts();
        } else if (cmd == "EXIT") {
            return (0);
        }
    }
    return (1);
}