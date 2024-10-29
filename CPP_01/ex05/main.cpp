#include "Harl.hpp"

int main(void)
{
    Harl harl;
    std::string level;

    while (harl.stat != 1)
    {
        std::cout << "Please insert the level for Harl : ";
        std::cout << LEVEL1 << " ";
        std::cout << LEVEL2 << " ";
        std::cout << LEVEL3 << " ";
        std::cout << LEVEL4 <<std::endl;
        std::cout << "Harl : ";

        std::getline(std::cin, level);
        std::cout << std::endl;
        harl.complain(level);
    }
    return (0);
}