/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 14:52:51 by suhong            #+#    #+#             */
/*   Updated: 2021/12/20 15:50:23 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

zombie::Zombie::Zombie()
{
	this->_name = "";
}

zombie::Zombie::Zombie(std::string name)
{
	this->_name = name;
}

zombie::Zombie::~Zombie()
{
	std::cout<<this->_name<<" destroyed."<<std::endl;
}

std::string	zombie::Zombie::getName(void) const
{
	return (this->_name);
}

void	zombie::Zombie::setName(std::string name)
{
	this->_name = name;
}

void	zombie::Zombie::announce(void) const
{
	std::cout<<"<"<<this->_name<<"> "
		<<"BraiiiiiiinnnzzzZ..."<<std::endl;
}
