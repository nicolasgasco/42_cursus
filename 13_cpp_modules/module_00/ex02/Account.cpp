
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngasco <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 13:14:49 by ngasco            #+#    #+#             */
/*   Updated: 2022/04/22 13:14:58 by ngasco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

#include <iomanip>
#include <iostream>

#define BLUE "\033[1;34m"
#define RED "\033[1;31m"
#define YELLOW "\033[1;33m"
#define CCLOSE "\033[0m"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) : _amount(initial_deposit) {
    this->_displayTimestamp();
    std::cout
        << "index:" << this->getNbAccounts() << ";amount:" << initial_deposit << ";created" << std::endl;
    this->_accountIndex = Account::_nbAccounts;
    Account::_nbAccounts += 1;
    Account::_totalAmount += initial_deposit;
}

Account::~Account(void) {
    Account::_nbAccounts -= 1;
    this->_displayTimestamp();
    std::cout
        << "index:" << this->getNbAccounts() << ";amount:" << this->_amount << ";closed" << std::endl;
}

// Getters
int Account::getNbAccounts(void) {
    return Account::_nbAccounts;
}

int Account::getTotalAmount(void) {
    return Account::_totalAmount;
}

int Account::getNbDeposits(void) {
    return Account::_totalNbDeposits;
}

int Account::getNbWithdrawals(void) {
    return Account::_totalNbWithdrawals;
}

void Account::displayAccountsInfos(void) {
    _displayTimestamp();
    std::cout << YELLOW
              << "accounts:" << getNbAccounts()
              << ";"
              << "total:" << getTotalAmount()
              << ";"
              << "deposits:" << getNbDeposits()
              << ";"
              << "withdrawals:" << getNbWithdrawals()
              << CCLOSE
              << std::endl;
}

// Deposit
void Account::makeDeposit(int deposit) {
    if (deposit > 0) {
        _displayTimestamp();
        std::cout << BLUE << "index" << this->_accountIndex
                  << ";"
                  << "p_amount" << this->_amount;
        this->_nbDeposits += 1;
        this->_amount += deposit;
        Account::_totalNbDeposits += 1;
        Account::_totalAmount += deposit;
        std::cout << ";"
                  << "deposit:" << deposit
                  << ";"
                  << "amount:" << this->_amount
                  << ";"
                  << "nb_deposits:" << this->_nbDeposits
                  << CCLOSE
                  << std::endl;
    } else {
        std::cout << "Deposit is negative" << std::endl;
    }
}

bool Account::makeWithdrawal(int withdrawal) {
    if (withdrawal > 0) {
        if (this->_amount > withdrawal) {
            _displayTimestamp();
            std::cout << RED << "index" << this->_accountIndex
                      << ";"
                      << "p_amount" << this->_amount;
            this->_nbWithdrawals += 1;
            this->_amount -= withdrawal;
            Account::_totalNbWithdrawals += 1;
            Account::_totalAmount -= withdrawal;
            std::cout << ";"
                      << "withdrawal:" << withdrawal
                      << ";"
                      << "amount:" << this->_amount
                      << ";"
                      << "nb_withdrawals:" << this->_nbWithdrawals
                      << CCLOSE
                      << std::endl;
            return (true);
        } else {
            _displayTimestamp();
            std::cout << RED << "index" << this->_accountIndex
                      << ";"
                      << "p_amount" << this->_amount
                      << ";"
                      << "withdrawal:refused"
                      << CCLOSE
                      << std::endl;
            return (false);
        }
    }
    std::cout
        << "Withdrawal is negative" << std::endl;
    return (false);
}
int Account::checkAmount(void) const {
    return (0);
}
void Account::displayStatus(void) const {
    this->_displayTimestamp();
    std::cout
        << "index:" << this->_accountIndex
        << ";"
        << "amount:" << this->_amount
        << ";"
        << "deposits:" << this->_nbDeposits
        << ";"
        << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

void Account::_displayTimestamp(void) {
    time_t now = time(0);
    tm *ltm = localtime(&now);

    std::cout << "[";
    std::cout << 1900 + ltm->tm_year;
    std::cout << std::setw(2) << std::setfill('0') << 1 + ltm->tm_mon;
    std::cout << std::setw(2) << std::setfill('0') << ltm->tm_mday;
    std::cout << "_";
    std::cout << std::setw(2) << std::setfill('0') << 5 + ltm->tm_hour;
    std::cout << std::setw(2) << std::setfill('0') << 30 + ltm->tm_min;
    std::cout << std::setw(2) << std::setfill('0') << ltm->tm_sec;
    std::cout << "] ";
}
