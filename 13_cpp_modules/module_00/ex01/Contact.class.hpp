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

#pragma once
#ifndef __CONTACT_H__
#define __CONTACT_H__

class Contact {
   public:
    Contact(void);
    ~Contact(void);

    void addSingleField(std::string id);

    bool getIsEmpty(void) const;
    void setIsEmptyToFalse(void);

    std::string getFirstName(void) const;
    std::string getLastName(void) const;
    std::string getNickName(void) const;
    std::string getPhoneNumber(void) const;
    std::string getDarkestSecret(void) const;

    void setFirstName(std::string value);
    void setLastName(std::string value);
    void setNickName(std::string value);
    void setPhoneNumber(std::string value);
    void setDarkestSecret(std::string value);

   private:
    std::string _firstName;
    std::string _lastName;
    std::string _nickName;
    std::string _phoneNumber;
    std::string _darkestSecret;

    bool _isEmpty;
};

#endif
