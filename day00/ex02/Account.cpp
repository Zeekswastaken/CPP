#include "Account.hpp"
#include <iostream>
#include <string>
#include <ctime>

int Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;
void Account::_displayTimestamp(void)
{
	time_t	current_time;
	struct tm		*local;

	current_time = time(0);
	local = localtime(&current_time);
	std::cout << '[' << std::to_string(local->tm_year + 1900);
	if (std::to_string(local->tm_mon).length() < 2)
		std::cout << '0';
	std::cout << std::to_string(local->tm_mon);
	if (std::to_string(local->tm_mday).length() < 2)
		std::cout << '0';
	std::cout << std::to_string(local->tm_mday);
	std::cout << '_';
	if (std::to_string(local->tm_hour).length() < 2)
		std::cout << '0';
	std::cout << std::to_string(local->tm_hour);
	if (std::to_string(local->tm_min).length() < 2)
		std::cout << '0';
	std::cout << std::to_string(local->tm_min);
	if (std::to_string(local->tm_sec).length() < 2)
		std::cout << '0';
	std::cout << std::to_string(local->tm_sec);
	std::cout << ']';
	
	std::cout << "\t";
}

Account::Account (int initial_deposit)
{
	_accountIndex = _nbAccounts++;
	_amount = initial_deposit;
	_nbWithdrawals = 0;
	_nbDeposits = 0;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index: " << _accountIndex << ';';
	std::cout << "amount: " << _amount << ';';
	std::cout << "created";
	std::cout << std::endl;
}


Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index: " << _accountIndex << ";";
	std::cout << "amount: " << _amount << ";";
	std::cout << "closed";
	std::cout << std::endl;
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts: " << _nbAccounts << ";";
	std::cout << "total: " << _totalAmount << ";";
	std::cout << "deposits: " << _totalNbDeposits << ";";
	std::cout << "withdrawals: " << _totalNbWithdrawals<< ";";
	std::cout << std::endl;
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index: " << _accountIndex << ";";
	std::cout << "amount: " << _amount << ";";
	std::cout << "deposits: " << _nbDeposits << ";";
	std::cout << "withdrawals: " << _nbWithdrawals<< ";";
	std::cout << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout << "index: ";
	std::cout << _accountIndex << ';';
	std::cout << "p_amount: ";
	std::cout << _amount << ';'; 
	_amount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	_totalAmount += deposit;
	std::cout << "deposit: ";
	std::cout << deposit << ';';
	std::cout << "amount: ";
	std::cout << _amount << ';';
	std::cout << "nb_deposits: ";
	std::cout << _nbDeposits;
	std::cout << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << "index: ";
	std::cout << _accountIndex << ';';
	std::cout << "p_amount: ";
	std::cout << _amount << ';';
	std::cout << "withdrawal: ";
	if (withdrawal > _amount)
	{
		std::cout << "refused" << std::endl;
		return(false);
	}
	std::cout << withdrawal << ';';
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	_nbWithdrawals++;
	std::cout << "amount: ";
	std::cout << _amount << ';';
	std::cout << "nb_withdrawals: ";
	std::cout << _nbWithdrawals;
	std::cout << std::endl;
	return (true);
}
