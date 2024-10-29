#include "Account.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount= 0;
int Account::_totalNbDeposits= 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void )
{
    return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
    return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
    return (_totalNbDeposits);
}   

int	Account::getNbWithdrawals( void )
{
    return (_totalNbWithdrawals);
}

void	 Account::_displayTimestamp( void )
{
    std::time_t result = std::time(NULL);

    int month =  1 + std::localtime(&result)->tm_mon;
    int day = std::localtime(&result)->tm_mday;

    std::cout << "[";
    std::cout << 1900 + std::localtime(&result)->tm_year;
    if (month > 9)
        std::cout << 1 + std::localtime(&result)->tm_mon;
    else
        std::cout << "0" << 1 + std::localtime(&result)->tm_mon;
    if (day > 9)
        std::cout << std::localtime(&result)->tm_mday;
    else
        std::cout << "0" << std::localtime(&result)->tm_mday;
    std::cout << "_";
    std::cout << std::localtime(&result)->tm_hour;
    std::cout << std::localtime(&result)->tm_min;
    std::cout << std::localtime(&result)->tm_sec;
    std::cout << "] ";
}

void Account::displayAccountsInfos( void )
{
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() << ";";
    std::cout << "total:" << getTotalAmount() << ";";
    std::cout << "deposits:" << getNbDeposits() << ";";
    std::cout << "withdrawals:" << getNbWithdrawals() << std::endl;
}

Account::Account( int initial_deposit )
{
    _nbAccounts++;
    this->_accountIndex = _nbAccounts - 1;
    this->_amount = initial_deposit;
    _totalAmount += this->_amount;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    _displayTimestamp();
    std::cout << "accounts:" << this->_nbAccounts << ";";
    std::cout << "total:" << this->_totalAmount << ";";
    std::cout << "deposits:" << this->_nbDeposits << ";";
    std::cout << "withdrawals:" << this->_nbWithdrawals << ";" << std::endl;
}

Account::~Account( void )
{
    _nbAccounts--;
    this->_displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "closed" << std::endl;
}

void	Account::makeDeposit( int deposit )
{
    _nbDeposits++;
    _totalNbDeposits++;
    _totalAmount += deposit;
    _amount += deposit;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "p_amount:" << _amount << ";";
    std::cout << "deposit:" << deposit << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "nb_deposit:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "p_amount:" << _amount << ";";
    std::cout << "withdrawal:" << std::endl;
    return (true);
}

int		Account::checkAmount( void ) const
{
    return (_amount);
}

void	Account::displayStatus( void ) const
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "deposits:" << _nbDeposits << ";";
    std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}  