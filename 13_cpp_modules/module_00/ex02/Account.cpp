
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

Account::Account(void) {
}

Account::~Account(void) {
}

// Getters
int Account::getNbAccounts(void) {
    return (0);
}
int Account::getTotalAmount(void) {
    return (0);
}
int Account::getNbDeposits(void) {
    return (0);
}
int Account::getNbWithdrawals(void) {
    return (0);
}
void Account::displayAccountsInfos(void) {
}

// Deposit
void Account::makeDeposit(int deposit) {
    if (deposit) {
        // 
    }
    return;
}
bool Account::makeWithdrawal(int withdrawal) {
    if (withdrawal) {
        //
    }
    return (false);
}
int Account::checkAmount(void) const {
    return (0);
}
void Account::displayStatus(void) const {
    return;
}

void Account::_displayTimestamp(void) {
    return;
}
