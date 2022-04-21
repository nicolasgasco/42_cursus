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

    void setFirstName(std::string firstName);
    void setLastName(std::string lastName);
    void setNickName(std::string nickName);
    void setPhoneNumber(std::string phoneNumber);
    void setDarkestSecret(std::string darkestSecret);

    bool getIsEmpty(void);

   private:
    bool _isEmpty;
};

#endif
