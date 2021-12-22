/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 16:59:14 by suhong            #+#    #+#             */
/*   Updated: 2021/12/23 01:28:12 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	zombie::Zombie	*horde = zombieHorde(10, "horde");

	for (int i = 0; i < 10; i++)
	{
		horde[i].announce();
	}
	delete[] horde;
	return (0);
}
