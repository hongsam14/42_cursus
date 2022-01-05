/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:06:13 by suhong            #+#    #+#             */
/*   Updated: 2022/01/05 15:57:35 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

customer::Karen::Karen()
{
}

customer::Karen::~Karen()
{
}

void	customer::Karen::debug(void)
{
	std::cout<<"I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!"<<std::endl;
}

void	customer::Karen::info(void)
{
	std::cout<<"I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!"<<std::endl;
}

void	customer::Karen::warning(void)
{
	std::cout<<"I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month."<<std::endl;
}

void	customer::Karen::error(void)
{
	std::cout<<"This is unacceptable, I want to speak to the manager now."<<std::endl;
}

void	customer::Karen::complain(std::string level)
{
	std::string	_level[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	enum { DEBUG, INFO, WARNING, ERROR };
	int	i(0);
	
	for (; _level[i] != level && i < 4; )
	{
	     i++;
	}
	switch (i)
	{
		case DEBUG:
			this->debug();
		case INFO:
			this->info();
		case WARNING:
			this->warning();
		case ERROR:
			this->error();
			break ;
		default:
			std::cout<<"[ Probably complaining about insignificant problems ]"<<std::endl;
	}
}
