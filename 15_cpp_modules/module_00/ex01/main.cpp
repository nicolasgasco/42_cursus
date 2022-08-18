/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 13:14:49 by ngasco            #+#    #+#             */
/*   Updated: 2022/04/22 13:14:58 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>

#include "Phonebook.class.hpp"

int main(void)
{
    PhoneBook phoneBook;
    std::string cmd;

    while (cmd != "EXIT")
    {
        std::cout << std::endl
                  << "Insert either ADD, SEARCH or EXIT: ";
        std::getline(std::cin, cmd);

        if (cmd == "ADD")
            phoneBook.addNewEntry();
        else if (cmd == "SEARCH")
        {
            if (phoneBook.getNumberOfValidContacts())
            {
                phoneBook.displayAllContacts();
                phoneBook.promptAndShowEntryByIndex();
            }
            else
            {
                std::cout << std::endl
                          << "No contacts. ADD a new one." << std::endl;
            }
        }
    }
    return (0);
}