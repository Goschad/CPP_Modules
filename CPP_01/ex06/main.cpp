#include "Harl.hpp"

void UpperChar(char *str)
{
    int i = 0;

    while (str[i])
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i] - 32;
        i++;
    }
}

int main(int argc, char **argv)
{
    Harl harl;

    if (argc == 2)
    {
        UpperChar(argv[1]);
        std::string level(argv[1]);
        harl.complain(level);
    }
    else
        std::cout << "• Usage: [LEVEL]" << std::endl;
    return (0);
}