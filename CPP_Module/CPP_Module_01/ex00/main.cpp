/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 15:39:28 by suhong            #+#    #+#             */
/*   Updated: 2021/12/20 15:49:04 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	zombie::Zombie	*heap;

	zombie::randomChump("stack");
	heap = zombie::newZombie("heap");
	heap->announce();
	delete heap;
	return (0);
}
