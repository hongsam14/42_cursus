/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 19:51:18 by suhong            #+#    #+#             */
/*   Updated: 2022/01/18 18:24:19 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	public:
		Fixed();
		Fixed(const int param);
		Fixed(const float param);
		
		Fixed(const Fixed &f);
		~Fixed();
		Fixed	&operator= (const Fixed &f);
		
		int	getRawBits(void) const;
		void	setRawBits(int const raw);

		float	toFloat(void) const;
		int	toInt(void) const;

	private:
		int	_fixed_point_value;
		static const int	_num_of_fractional_bits;
};

std::ostream	&operator<<(std::ostream &os, const Fixed &fixed);

#endif
