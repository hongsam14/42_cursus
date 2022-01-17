/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 19:51:18 by suhong            #+#    #+#             */
/*   Updated: 2022/01/17 17:04:30 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed &f);
		~Fixed();
		Fixed	&operator= (const Fixed &f);
		int	getRawBits(void) const;
		void	setRawBits(int const raw);

	private:
		int	_fixed_point_value;
		static const int	_num_of_fractional_bits;
};

#endif
