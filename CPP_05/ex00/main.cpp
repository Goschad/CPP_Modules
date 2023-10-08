#include "Bureaucrat.hpp"

int main(void)
{
    std::cout << "---------------------------------" << std::endl;

    Bureaucrat employ0("Moi", 5000);

    employ0.getInfo();

    std::cout << "---------------------------------" << std::endl;

    Bureaucrat employ1("Salah", 149);

    std::cout << std::endl;

    employ1.Retrograde();

    employ1.getInfo();

    employ1.Retrograde();

    employ1.getInfo();

    std::cout << "---------------------------------" << std::endl;

    Bureaucrat employ2("Romain", 2);

    std::cout << std::endl;

    employ2.Promotion();

    employ2.getInfo();

    employ2.Promotion();

    employ2.getInfo();

    std::cout << "---------------------------------" << std::endl;

    Bureaucrat bureau = employ0;

    bureau.getInfo();

    std::cout << "---------------------------------" << std::endl;
}