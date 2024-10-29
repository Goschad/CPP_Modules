#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

// include //

#include "Contact.class.hpp"

// class //

class PhoneBook {

private:
    Contact contact[8];
    int index;
    int ContactNumber;

public:
    PhoneBook() : index (0), ContactNumber (0) {}
    ~PhoneBook(void);
    void PhoneBookAdd(std::string info[5]);
    void PhoneBookIntro(void);
    void PhoneBookSearchIntro(void);
    void PhoneBookInfoIndex(int index);
    int PhoneBookCheckIsNumber(std::string number);

};

#endif