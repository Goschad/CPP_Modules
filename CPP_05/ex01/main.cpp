#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
    std::cout << "---------------------------------" << std::endl;

    Bureaucrat employ0("Moi", 100);

    employ0.getInfo();

    Form form1("FormTest", 150, 100);
    Form form2("Form2", 10, 1);

    std::cout << "---------------------------------" << std::endl;

    Form Fail_form("Fail", 151, -1);

    std::cout << std::endl;

    Form Fail_form2("Fail", 151, 10);

    std::cout << "---------------------------------" << std::endl;
}

