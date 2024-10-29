#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

#include <iostream>
#include <string>
#include <cstring>
#include <new>  
#include <sstream>

class Contact {

private:
    std::string	firstname;
	std::string	lastname;
	std::string	nickname;
    std::string	number;
	std::string	darkest_secret;

public:
    void RegisterFirstName(std::string firstname);
    void RegisterLastName(std::string lastname);
    void RegisterNickName(std::string nickname);
    void RegisterNumber(std::string number);
    void RegisterDarkestSecret(std::string darkest_secret);

    const std::string& GetFirstName(void);
    const std::string& GetLastName(void);
    const std::string& GetNickName(void);
    const std::string& GetNumber(void);
    const std::string& GetDarkestSecret(void);

};

#endif