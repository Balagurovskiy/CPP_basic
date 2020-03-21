/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igaliuk <igaliuk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 13:08:41 by igaliuk           #+#    #+#             */
/*   Updated: 2018/04/02 17:30:41 by igaliuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.class.hpp"
#include <iostream>

int	Account::getNbAccounts(void){	return (_nbAccounts);}

int	Account::getTotalAmount(void){	return (_totalAmount);}

int	Account::getNbDeposits(void){	return (_totalNbDeposits);}

int	Account::getNbWithdrawals(void){	return (_totalNbWithdrawals);}


void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";";
	std::cout << "total:" << getTotalAmount() << ";";
	std::cout << "deposits:" << getNbDeposits() << ";";
	std::cout << "withdrawals:" << getNbWithdrawals();
	std::cout << std::endl;
}

Account::Account(void) {}

Account::Account(int initial_deposit)
{
	_displayTimestamp();
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "created" << std::endl;
	_totalAmount += _amount;
	_nbAccounts++;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "closed" << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:";
	_amount += deposit;
	std::cout << _amount << ";" << "nb_deposits:";
	if (deposit)
	{
		_nbDeposits++;
		_totalAmount += deposit;
		_totalNbDeposits++;
	}
	std::cout << _nbDeposits;
	std::cout << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	bool	hasAmount;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	std::cout << "withdrawal:";
	if (_amount - withdrawal >= 0)
	{
		std::cout << withdrawal << ";";
		std::cout << "amount:";
		_amount -= withdrawal;
		std::cout << _amount << ";";
		std::cout << "nb_withdrawals:";
		_nbWithdrawals++;
		std::cout << _nbWithdrawals;
		_totalNbWithdrawals++;
		_totalAmount -= withdrawal;
		hasAmount = true;
	}
	else
	{
		std::cout << "refused";
		hasAmount = false;
	}
	std::cout << std::endl;
	return (hasAmount);
}

int		Account::checkAmount( void ) const{ return (0);}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals;
	std::cout << std::endl;
}


int		Account::_nbAccounts = 0;
int		Account::_totalAmount = 0;
int		Account::_totalNbDeposits = 0;
int		Account::_totalNbWithdrawals = 0;


void	Account::_displayTimestamp(void)
{
	std::cout << "[20150406_153629] ";
}
