/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:13:53 by suhong            #+#    #+#             */
/*   Updated: 2022/01/17 17:13:19 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_num_of_fractional_bits(8);

Fixed::Fixed() : _fixed_point_value(0)
{
	std::cout<<"Default constructor called"<<std::endl;
}

Fixed::Fixed(const Fixed &f)
{
	std::cout<<"Copy constructor called"<<std::endl; 
	//this->_fixed_point_value = f.getRawBits();
	*this = f;
}

Fixed::~Fixed()
{
	std::cout<<"Destructor called"<<std::endl;
}

Fixed	&Fixed::operator=(const Fixed &f)
{
	std::cout<<"Assignation operator called"<<std::endl;
	this->_fixed_point_value = f.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	std::cout<<"getRawBits member function called"<<std::endl;
	return (this->_fixed_point_value);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout<<"setRawBits member function called"<<std::endl;
	this->_fixed_point_value = raw;
}
