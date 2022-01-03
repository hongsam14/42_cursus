/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 17:48:14 by suhong            #+#    #+#             */
/*   Updated: 2021/12/30 22:07:38 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>

class Weapon
{
	public:
		Weapon();
		Weapon(std::string type);
		~Weapon();
		
		void		setType(std::string type);
		std::string	getType(void) const;

	private:
		std::string	_type;
};

#endif
