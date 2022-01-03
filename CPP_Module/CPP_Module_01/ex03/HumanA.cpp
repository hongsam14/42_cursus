/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 19:59:45 by suhong            #+#    #+#             */
/*   Updated: 2021/12/31 02:05:35 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon):weapon_(weapon), name_(name)
{
}

HumanA::~HumanA()
{
}

void	HumanA::attack(void)
{
	std::cout<<this->name_<<" attacks with his "
		<<this->weapon_.getType()
		<<std::endl;
}
