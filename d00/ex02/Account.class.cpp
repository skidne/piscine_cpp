#include <iostream>
#include <ctime>
#include "Account.class.hpp"

int				Account::_nbAccounts = 0;
int				Account::_totalAmount = 0;
int				Account::_totalNbDeposits = 0;
int				Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) : _nbDeposits(0), _nbWithdrawals(0)
{

	this->_accountIndex = _nbAccounts;
	this->_amount = initial_deposit;

	_nbAccounts++;
	_totalAmount += initial_deposit;

	_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex << ";amount:"
				<< this->_amount << ";created" << std::endl;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex << ";amount:"
				<< this->_amount << ";closed" << std::endl;
}

int				Account::getNbAccounts()
{
	return _nbAccounts;
}

int				Account::getTotalAmount()
{
	return _totalAmount;
}

int				Account::getNbDeposits()
{
	return _totalNbDeposits;
}

int				Account::getNbWithdrawals()
{
	return _totalNbWithdrawals;
}

void			Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout	<< "accounts:" << getNbAccounts() << ";total:"
				<< Account::getTotalAmount() << ";deposits:"
				<< Account::getNbDeposits() << ";withdrawals:"
				<< Account::getNbWithdrawals() << std::endl;
}

void			Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex << ";p_amount:"
				<< this->_amount << ";deposit:" << deposit
				<< ";amount:" << this->_amount + deposit
				<< ";nb_deposits:" << this->_nbDeposits + 1
				<< std::endl;

	_totalAmount += deposit;
	_totalNbDeposits++;
	this->_amount += deposit;
	this->_nbDeposits++;
}

bool			Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex << ";p_amount:"
				<< this->_amount;

	if (this->_amount < withdrawal)
		std::cout << ";withdrawal:refused" << std::endl;
	else
	{
		std::cout	<< ";withdrawal:" << withdrawal << ";amount:"
					<< this->_amount - withdrawal << ";nb_withdrawals:"
					<< this->_nbWithdrawals + 1 << std::endl;

		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		this->_nbWithdrawals++;
		this->_amount -= withdrawal;
	}
	return true;
}

int				Account::checkAmount() const
{
	return this->_amount;
}

void			Account::displayStatus() const
{
	_displayTimestamp();
	std::cout	<< "index:" << this->_accountIndex << ";amount:"
				<< this->_amount << ";deposits:" << this->_nbDeposits
				<< ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void		Account::_displayTimestamp()
{
	char		buff[32];
	time_t		now = time(NULL);
	struct tm	*local = localtime(&now);

	strftime(buff, sizeof(buff), "[%Y%d%m_%H%M%S] ", local);
	std::cout << buff;
}
