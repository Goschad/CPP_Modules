#include "Converter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Argument error." << std::endl;
        return (1);
    }
    Converter convert(argv[1]);
}