#pragma once
#ifndef __CONTACT_H__
#define __CONTACT_H__

class Contact {
   public:
    std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string phoneNumber;
    std::string darkestSecret;

    Contact(void);
    ~Contact(void);

    void addSingleField(std::string id);

    bool getIsEmpty(void) const;
    void setIsEmptyToFalse(void);

   private:
    bool _isEmpty;
};

#endif
