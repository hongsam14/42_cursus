/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 18:24:05 by suhong            #+#    #+#             */
/*   Updated: 2021/12/21 22:28:35 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

namespace zombie
{
	class Zombie
	{
		public:
			Zombie();
			Zombie(std::string name);
			~Zombie();

			std::string	getName(void) const;
			void	setName(std::string name);
			void	announce(void) const;
		private:
			std::string	_name;
	};

}
zombie::Zombie	*zombieHorde(int N, std::string name);

#endif
