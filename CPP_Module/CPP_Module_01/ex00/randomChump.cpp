/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 15:37:23 by suhong            #+#    #+#             */
/*   Updated: 2021/12/20 15:44:03 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	zombie::randomChump(std::string name)
{
#if 1
	zombie::Zombie	my;

	my.setName(name);
#else
	zombie::Zombie my = Zombie(name);
#endif
	my.announce();
}
