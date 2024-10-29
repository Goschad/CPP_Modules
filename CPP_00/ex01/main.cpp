#include "PhoneBook.class.hpp"
#include "Contact.class.hpp"

int check_exist(std::string word)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (word[i])
    {
        i++;
        if (word[j] == ' ' || word[j] == '\t')
            j++;
    }
    if (i == j)
        return (1);
    return (0);
}

std::string tab_to_space(std::string word)
{
    int i;

    i = 0;
    while (word[i])
    {
        if (word[i] == '\t')
            word[i] = ' ';
        i++;
    }
    return (word);
}

int main(void)
{
    PhoneBook Phone;
    std::string choice;
    std::string info[5];
    int me = 1;

    Phone.PhoneBookIntro();
    while (1)
    {
        std::getline(std::cin, choice);
        std::cout<<std::endl;
        if (choice == "ADD")
        {
            while (1)
            {
                std::cout<<"1️⃣  First Name : ";
                std::getline(std::cin, info[0]);
                if (check_exist(info[0]) == 0)
                    break;
                std::cout<<"Invalid input, please retry ! 🤬"<<std::endl;
            }
            info[0] = tab_to_space(info[0]);
            while (1)
            {
                std::cout<<"2️⃣  Last Name : ";
                std::getline(std::cin, info[1]);
                if (check_exist(info[1]) == 0)
                    break;
                std::cout<<"Invalid input, please retry ! 🤬"<<std::endl;
            }
            info[1] = tab_to_space(info[1]);
            while (1)
            {
                std::cout<<"3️⃣  Nickname : ";
                std::getline(std::cin, info[2]);
                if (check_exist(info[2]) == 0)
                    break;
                std::cout<<"Invalid input, please retry ! 🤬"<<std::endl;
            }
            info[2] = tab_to_space(info[2]);
            while (1)
            {
                std::cout<<"4️⃣  Number : ";
                std::getline(std::cin, info[3]);
                if (Phone.PhoneBookCheckIsNumber(info[3]) == 1 &&  check_exist(info[3]) == 0)
                    break;
                std::cout<<"Invalid Number, please retry ! 🤬"<<std::endl;
            }
            info[3] = tab_to_space(info[3]);
            while (1)
            {
                std::cout<<"5️⃣  Dakest Secret : ";
                std::getline(std::cin, info[4]);
                if (check_exist(info[4]) == 0)
                    break;
                std::cout<<"Invalid input, please retry ! 🤬"<<std::endl;
            }
            info[4] = tab_to_space(info[4]);
            Phone.PhoneBookAdd(info);
            std::cout<<"\033[1;32mContact Was Successfuly Added ! 🥳\033[0;0m\n"<<std::endl;
            me = 0;
        }
        else if (choice == "SEARCH")
        {
            Phone.PhoneBookSearchIntro();
            me = 0;
            continue;
        }
        else if (choice == "EXIT")
        {
            break;
        }
        else if (me == 1)
        {
            std::cout<<"Invalide input, please retry ! 🤬\n"<<std::endl;
        }
        std::cout<<"Please choose an option, ADD / SEARCH / EXIT"<<std::endl;
        std::cout<<"🤔 I want : ";
        me = 1;
    }
    return (0);
}