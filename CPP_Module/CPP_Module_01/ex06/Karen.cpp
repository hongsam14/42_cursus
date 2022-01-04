/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:06:13 by suhong            #+#    #+#             */
/*   Updated: 2022/01/04 18:10:49 by suhong           ###   ########.fr       */
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
	typedef std::array<std::string, 4>	Level;
	typedef	std::array<void	(customer::Karen::*)(void), 4>	Action;

	Level	_level = {"DEBUG", "INFO", "WARNING", "ERROR"};
	Action	_action = {&customer::Karen::debug,
			&customer::Karen::info,
			&customer::Karen::warning,
			&customer::Karen::error};
	
	Level::iterator	l_ittr(_level.begin());
	Action::iterator	a_ittr(_action.begin());
	
	for ( ;l_ittr != _level.end() && *l_ittr != level;)
	{
	     l_ittr++, a_ittr++;
	}
	if (l_ittr == _level.end())
		return ;
	std::cout<<"["<<*l_ittr<<"]"<<std::endl;
	(this->*(*a_ittr))();
}
