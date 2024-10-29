#include <iostream>
#include <string>

int main()
{
    std::string Brain     = "HI THIS IS BRAIN";
    std::string *BrainPtr = &Brain;
    std::string &BrainRef = Brain;

    std::cout<< &Brain    <<std::endl;
    std::cout<< BrainPtr  <<std::endl;
    std::cout<< &BrainRef <<std::endl;

    std::cout<<std::endl;

    std::cout<< Brain     <<" 🧠"<<std::endl;
    std::cout<< *BrainPtr <<" 🧠"<<std::endl;
    std::cout<< BrainRef  <<" 🧠"<<std::endl;
}