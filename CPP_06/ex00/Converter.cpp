#include "Converter.hpp"

Converter::Converter( void ) : _input("0")
{
    int Type = 0;

    _c = '\0';
    _i = 0;
    _f = 0.0f;
    _d = 0.0;
    Type = DefineInput();
    if (Type == PSEUDO)
        printPseudoInf();
    else if (Type == CHAR)
        printChar(getInput().c_str()[0]);
    else if (Type == INT)
        printInt();
    else if (Type == DOUBLE || Type == FLOAT)
        printDeci();
    else
        std::cout << "Error Unknown Input" << std::endl;
}

Converter::Converter( std::string input ) : _input(input)
{
    int Type = 0;

    _c = '\0';
    _i = 0;
    _f = 0.0f;
    _d = 0.0;
    Type = DefineInput();
    if (Type == PSEUDO)
        printPseudoInf();
    else if (Type == CHAR)
        printChar(getInput().c_str()[0]);
    else if (Type == INT)
        printInt();
    else if (Type == DOUBLE || Type == FLOAT)
        printDeci();
    else
        std::cout << "Error Unknown Input" << std::endl;
}

Converter::Converter( Converter const & src ) : _input(src.getInput())
{
    _c = src.getChar();
    _i = src.getInt();
    _f = src.getFloat();
    _d = src.getDouble();
}

int Converter::DefineInput( void )
{
    int first = 0;
    bool doubleCheck = false;
    bool floatCheck = false;

    if (getInput() == "+inf" || getInput() == "-inf" || getInput() == "nan" || getInput() == "+inff" || getInput() == "-inff" || getInput() == "nanf")
        return (PSEUDO);
    else if (getInput().length() == 1 && (getInput().c_str()[0] < '0' || getInput().c_str()[0] > '9'))
        return (CHAR);
    
    if (getInput().c_str()[0] == '-' || getInput().c_str()[0] == '+')
        first = 1;
    for (int i = 0 + first; getInput().c_str()[i] ; i += 0)
    {
        if (getInput().c_str()[0] != '.' && getInput().c_str()[i] == '.'
            && getInput().c_str()[getInput().length() - 1] != '.' && doubleCheck == false && floatCheck == false)
            doubleCheck = true;
        else if (getInput().c_str()[i] == 'f' && !getInput().c_str()[i + 1] && floatCheck == false && doubleCheck == true)
            floatCheck = true;
        else if (!isdigit(getInput().c_str()[i]))
            break;
        i++;
        if (!getInput().c_str()[i] && doubleCheck == false && floatCheck == false)
            return (INT);
        else if (!getInput().c_str()[i] && floatCheck == true && doubleCheck == true)
            return (FLOAT);
        else if (!getInput().c_str()[i] && doubleCheck == true)
            return (DOUBLE);
    }
    return (ERROR); 
}

void Converter::printPseudoInf( void )
{
    std::string copy = getInput();

    std::cout << "char: "   << "impossible"<< std::endl;
    std::cout << "int: "    << "impossible" << std::endl;
    if (getInput() == "+inff" || getInput() == "-inff" || getInput() == "nanf")
    {
        std::cout << "float: "  << getInput() << std::endl;
        copy.erase(copy.length() - 1);
    }
    else
        std::cout << "float: "  << getInput() << "f" << std::endl;
    std::cout << "double: " << copy << std::endl;
}

void Converter::printChar( char c )
{
    std::string result;

    result = c;
    if ((c >= 0 && c <= 33) || c == 127)
        result = "Non displayable";

    _i = c;
    _f = c;
    _d = c;
    std::cout << "char: "   << "'" << result << "'" << std::endl;
    std::cout << "int: "    << getInt() << std::endl;
    std::cout << "float: "  << getFloat() << ".0f" << std::endl;
    std::cout << "double: " << getDouble() << ".0" << std::endl;
}

void Converter::printInt( void )
{
    std::string result = "impossible";

    _d = std::atof(getInput().c_str());
    if (std::atof(getInput().c_str()) >= 0 && std::atof(getInput().c_str()) <= 127)
    {
        if (std::atof(getInput().c_str()) <= 33 || std::atof(getInput().c_str()) == 127)
        {
            result = "Non displayable";
            std::cout << "char: "   << result << std::endl;
        }
        else
        {
            _c = std::atof(getInput().c_str());
            std::cout << "char: "   << "'" << getChar() << "'" << std::endl;
        }
    }
    else
        std::cout << "char: "   << result << std::endl;
    _i = static_cast<int>(getDouble());
    if (!(std::atof(getInput().c_str()) < INT_MAX && std::atof(getInput().c_str()) > INT_MIN))
        std::cout << "int: "   << "impossible" << std::endl;
    else
        std::cout << "int: "    << getInt() << std::endl;
    _f = static_cast<float>(getDouble());
    if (getFloat() > 3.402823466e+38 || getFloat() < 1.175494351e-38)
        std::cout << "float: "  << getFloat() << "f" << std::endl;
    else
        std::cout << "float: "  << getFloat() << ".0f" << std::endl;
    if (getDouble() < 1.7976931348623158e+308 && getDouble() > 12.2250738585072014e-308)
        std::cout << "double: " << getDouble() << ".0" << std::endl;
    else
        std::cout << "double: " << getDouble() << std::endl;
}

void Converter::printDeci( void )
{
    std::string result = "impossible";

    _d = std::atof(getInput().c_str());
    if (std::atof(getInput().c_str()) >= 0 && std::atof(getInput().c_str()) <= 127)
    {
        if (std::atof(getInput().c_str()) <= 33 || std::atof(getInput().c_str()) == 127)
        {
            result = "Non displayable";
            std::cout << "char: "   << result << std::endl;
        }
        else
        {
            _c = std::atof(getInput().c_str());
            std::cout << "char: "   << "'" << getChar() << "'" << std::endl;
        }
    }
    else
        std::cout << "char: "   << result << std::endl;
    _i = static_cast<int>(getDouble());
    if (!(std::atof(getInput().c_str()) < INT_MAX && std::atof(getInput().c_str()) > INT_MIN))
        std::cout << "int: "   << "impossible" << std::endl;
    else
        std::cout << "int: "    << getInt() << std::endl;
    _f = static_cast<float>(getDouble());
    if (_i == _f)
    {
        std::cout << "float: "  << getFloat() << ".0f" << std::endl;
        std::cout << "double: " << getDouble() << ".0" << std::endl;
    }
    else
    {
        std::cout << "float: "  << getFloat() << "f" << std::endl;
        std::cout << "double: " << getDouble() << std::endl;
    }
}

char Converter::getChar( void ) const
{
    return (_c);
}

int Converter::getInt( void ) const
{
    return (_i);
}

float Converter::getFloat( void ) const
{
    return (_f);
}

double Converter::getDouble( void ) const
{
    return (_d);
}

const std::string Converter::getInput( void ) const
{
    return (_input);
}

Converter & Converter::operator=( Converter const & rhs )
{
    _c = rhs.getChar();
    _i = rhs.getInt();
    _f = rhs.getFloat();
    _d = rhs.getDouble();

    return (*this);
}

Converter::~Converter( void )
{
    return ;
}