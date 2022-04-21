#include <iostream>

#include "Phonebook.class.hpp"

std::string colletCmdFromUser() {
    std::string cmd;

    std::cout << "Insert either ADD, SEARCH or EXIT: ";
    std::cin >> cmd;
    return (cmd);
}

void actionSearch(PhoneBook *phoneBook) {
    phoneBook->displayAllContacts();
}

void addSingleContactField(std::string id, PhoneBook *phoneBook) {
    std::string value;
    std::cout << "Insert ";
    if (id == "FIRST") {
        std::cout << "first name: ";
        std::cin >> value;
        phoneBook->contactList[phoneBook->getNumberOfContacts()].setFirstName(value);
    } else if (id == "LAST") {
        std::cout << "last name: ";
        std::cin >> value;
        phoneBook->contactList[phoneBook->getNumberOfContacts()].setLastName(value);
    }
}

void actionAdd(PhoneBook *phoneBook) {
    addSingleContactField("FIRST", phoneBook);
    addSingleContactField("LAST", phoneBook);
    std::cout << "First name of newContact is " << phoneBook->contactList[phoneBook->getNumberOfContacts()].firstName << std::endl;
    std::cout << "First name of newContact is " << phoneBook->contactList[phoneBook->getNumberOfContacts()].lastName << std::endl;
}

int main(void) {
    PhoneBook phoneBook;

    while (1) {
        std::string cmd = colletCmdFromUser();
        if (cmd == "ADD") {
            actionAdd(&phoneBook);
        } else if (cmd == "SEARCH") {
            actionSearch(&phoneBook);
        } else if (cmd == "EXIT") {
            return (0);
        }
    }
    std::cout << "End of program" << std::endl;
    return (1);
}