#include <iostream>

#include "Phonebook.class.hpp"

std::string colletCmdFromUser() {
    std::string cmd;

    std::cout << "Insert either ADD, SEARCH or EXIT: ";
    std::getline(std::cin, cmd);
    return (cmd);
}

int main(void) {
    PhoneBook phoneBook;

    while (1) {
        std::string cmd = colletCmdFromUser();
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