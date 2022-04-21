#include <iostream>

std::string colletCmdFromUser() {
    std::string cmd;

    std::cout << "Insert either ADD, SEARCH or EXIT: ";
    std::cin >> cmd;
    return (cmd);
}

int main(void) {
    PhoneBook phoneBook();
    
    while (1) {
        std::string cmd = colletCmdFromUser();
        if (cmd == "ADD") {
            std::cout << "You typed ADD!!" << std::endl;
        } else if (cmd == "SEARCH") {
            std::cout << "You typed SEARCH!!" << std::endl;
        } else if (cmd == "EXIT") {
            return (0);
        }
    }
    return (1);
}