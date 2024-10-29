#include "PhoneBook.class.hpp"

void PhoneBook::PhoneBookIntro(void)
{
    std::cout<<"\nYou have 3 choice :"<<std::endl;
    std::cout<<"\n• ADD : register a new contact"<<std::endl;
    std::cout<<"• SEARCH: displays the requested contact"<<std::endl;
    std::cout<<"• EXIT : quit and delete the PhoneBook\n"<<std::endl;
    std::cout<<"I want : ";
}

void PhoneBook::PhoneBookSearchIntro(void)
{
    std::string first;
    std::string last;
    std::string nickname;
    std::string input;
    int index_choose;
    size_t space = 0;

    std::cout<<" ____________\033[0;44m PHONEBOOK CONTACT \033[0;0m____________"<<std::endl;
    std::cout<<" ___________________________________________"<<std::endl;
    std::cout<<"|          |          |          |          |"<<std::endl;
    std::cout<<"|  index   |first name| last name| nick name|"<<std::endl;
    std::cout<<"|__________|__________|__________|__________|"<<std::endl;

    if (this->ContactNumber == 0)
    {
        std::cout<<"\nActualy you have 0 Contact : Rip Bozo 🤡\n"<<std::endl;
        std::cout<<"Please choose an option, ADD / SEARCH / EXIT"<<std::endl;
        std::cout<<"🤔 I want : ";
        return;
        // SI LE PREMIER CHOIX EST UNE ERREUR BAH C AFFICHE PAS INVALIDE INDEX
    }
    else
    {
        std::cout<<" ___________________________________________"<<std::endl;
        for (int i = 0; i < this->ContactNumber; i++)
        {
            first = this->contact[i].GetFirstName();
            last = this->contact[i].GetLastName();
            nickname = this->contact[i].GetNickName();
            if (first.size() >= 10)
            {
                first = first.substr(0, 9);
                first = first.insert(9, ".");
            }
            if (last.size() >= 10)
            {
                last = last.substr(0, 9);
                last = last.insert(9, ".");
            }
            if (nickname.size() >= 10)
            {
                nickname = nickname.substr(0, 9);
                nickname = nickname.insert(9, ".");
            }
            std::cout<<"|          |          |          |          |"<<std::endl;
            std::cout<<"|    "<<i + 1<<"     ";
            std::cout<<"|";
            for (space = 0; space < (10 - first.size()); space++)
                std::cout<<" ";
            std::cout<<first;
            std::cout<<"|";
            for (space = 0; space < (10 - last.size()); space++)
                std::cout<<" ";
            std::cout<<last;
            std::cout<<"|";
            for (space = 0; space < (10 - nickname.size()); space++)
                std::cout<<" ";
            std::cout<<nickname;
            std::cout<<"|"<<std::endl;
            std::cout<<"|__________|__________|__________|__________|"<<std::endl;
        }
        std::cout<<std::endl;
        while (true)
    {
        std::cout << "Please insert an index: ";
        std::cin >> input;

        std::istringstream iss(input);
        if (iss >> index_choose)
        {
            break;
        }
        else
        {
            std::cout << "Invalid input, please try again ... 👀" << std::endl;
        }
    }
        PhoneBookInfoIndex(index_choose);
    }
}

int PhoneBook::PhoneBookCheckIsNumber(std::string number)
{
    int i = 0;

    while (number[i])
    {
        if (number[0] == '+')
            i++;
        else if (number[i] == ' ' || (number[i] >= '0' && number[i] <= '9'))
            i++;
        else
            return (-1);
    }
    return (1);
}

void PhoneBook::PhoneBookAdd(std::string info[5])
{
    int index = this->index;
    static int first_message = 0;

    this->contact[index % 8].RegisterFirstName(info[0]);
    this->contact[index % 8].RegisterLastName(info[1]);
    this->contact[index % 8].RegisterNickName(info[2]);
    this->contact[index % 8].RegisterNumber(info[3]);
    this->contact[index % 8].RegisterDarkestSecret(info[4]);
    if (this->ContactNumber < 8)
        this->ContactNumber++;
    if (this->index == 7)
    {
        if (first_message++ == 0)
        {
            std::cout<<"\n🤖  Warning : Your Phonebook is full ..."<<std::endl;
            std::cout<<"The next contact to add delete the first until reaching the 8th\n"<<std::endl;
        }
    }
    if (this->index == 8)
    {
        this->index = 1;
    }
    else
        this->index++;
    return;
}

void PhoneBook::PhoneBookInfoIndex(int index)
{

    if (index > this->ContactNumber || index <= 0)
    {
        std::cout<<"\nInvalid index ☠️"<<std::endl;
    }
    else
    {
        index = index - 1;
        std::cout<<std::endl;
        std::cout<<"First Name : "<<contact[index].GetFirstName()<<std::endl;
        std::cout<<"Last Name : "<<contact[index].GetLastName()<<std::endl;
        std::cout<<"NickName : "<<contact[index].GetNickName()<<std::endl;
        std::cout<<"Number : "<<contact[index].GetNumber()<<std::endl;
        std::cout<<"Darkest Secret : "<<contact[index].GetDarkestSecret()<<std::endl;
    }
    return;
}

PhoneBook::~PhoneBook(void)
{
    return;
}