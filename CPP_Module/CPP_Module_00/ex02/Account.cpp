/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:52:08 by suhong            #+#    #+#             */
/*   Updated: 2021/12/17 23:52:33 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <chrono>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(void)
{
	this->_accountIndex = Account::_nbAccounts;
	Account::_nbAccounts++;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_amount = 0;
	Account::_displayTimestamp();
	std::cout<<"index:"<<this->_accountIndex<<";"
		<<"amount:"<<this->_amount<<";"
		<<"created"<<std::endl;
}

Account::Account(int initial_deposit)
{
	this->_accountIndex = Account::_nbAccounts;
	Account::_nbAccounts++;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_amount = initial_deposit;
	Account::_totalAmount += initial_deposit;
	Account::_displayTimestamp();
	std::cout<<"index:"<<this->_accountIndex<<";"
		<<"amount:"<<this->_amount<<";"
		<<"created"<<std::endl;
}

Account::~Account(void)
{
	Account::_nbAccounts--;
	Account::_totalAmount -= this->_amount;
	Account::_displayTimestamp();
	std::cout<<"index:"<<this->_accountIndex<<";"
		<<"amount:"<<this->_amount<<";"
		<<"closed"<<std::endl;
}

void	Account::_displayTimestamp(void)
{
	std::chrono::time_point<std::chrono::system_clock>	now;
	std::time_t		_time;
	struct tm		*timestamp;

	now = std::chrono::system_clock::now();
	_time = std::chrono::system_clock::to_time_t(now);
	timestamp = localtime(&_time);
	std::cout<<std::setfill('0')<<"["
		<<std::setw(4)<<timestamp->tm_year + 1900
		<<std::setw(2)<<timestamp->tm_mon
		<<std::setw(2)<<timestamp->tm_mday<<"_"
		<<std::setw(2)<<timestamp->tm_hour
		<<std::setw(2)<<timestamp->tm_min
		<<std::setw(2)<<timestamp->tm_sec
		<<"] ";
}

int	Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout<<"accounts:"<<Account::_nbAccounts<<";"
		<<"total:"<<Account::_totalAmount<<";"
		<<"deposits:"<<Account::_totalNbDeposits<<";"
		<<"withdrawals"<<Account::_totalNbWithdrawals<<std::endl;
}

void	Account::makeDeposit(int deposit)
{
	Account::_displayTimestamp();
	std::cout<<"index:"<<this->_accountIndex<<";"
		<<"p_amount:"<<this->_amount<<";"
		<<"deposit:"<<deposit<<";";
	Account::_totalNbDeposits++;
	this->_nbDeposits++;
	Account::_totalAmount += deposit;
	this->_amount += deposit;
	std::cout<<"amount:"<<this->_amount<<";"
		<<"nb_deposits:"<<this->_nbDeposits<<std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	Account::_displayTimestamp();
	std::cout<<"index:"<<this->_accountIndex<<";"
		<<"p_amount:"<<this->_amount<<";"
		<<"withdrawal:";
	if (this->_amount < withdrawal)
	{
		std::cout<<"refused"<<std::endl;
		return (false);
	}
	std::cout<<withdrawal<<";";
	this->_nbWithdrawals++;
	Account::_totalNbWithdrawals++;
	this->_amount -= withdrawal;
	Account::_totalAmount -= withdrawal;
	std::cout<<"amount:"<<this->_amount<<";"
		<<"nb_withdrawals:"<<this->_nbWithdrawals<<std::endl;
	return (true);
}

int	Account::checkAmount(void) const
{
	return (this->_amount);
}

void	Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout<<"index:"<<this->_accountIndex<<";"
		<<"amount:"<<this->_amount<<";"
		<<"deposits:"<<this->_nbDeposits<<";"
		<<"withdrawals:"<<this->_nbWithdrawals<<std::endl;
}
