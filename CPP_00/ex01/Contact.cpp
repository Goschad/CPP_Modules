#include "Contact.class.hpp"

void Contact::RegisterFirstName(std::string firstname)
{
    this->firstname = firstname;
}

void Contact::RegisterLastName(std::string lastname)
{
    this->lastname = lastname;
}

void Contact::RegisterNickName(std::string nickname)
{
    this->nickname = nickname;
}

void Contact::RegisterNumber(std::string number)
{
    this->number = number;
}

void Contact::RegisterDarkestSecret(std::string darkest_secret)
{
    this->darkest_secret = darkest_secret;
}

const std::string& Contact::GetFirstName(void)
{
    return (this->firstname);
}

const std::string& Contact::GetLastName(void)
{
    return (this->lastname);
}

const std::string& Contact::GetNickName(void)
{
    return (this->nickname);
}

const std::string& Contact::GetNumber(void)
{
    return (this->number);
}

const std::string& Contact::GetDarkestSecret(void)
{
    return (this->darkest_secret);
}

