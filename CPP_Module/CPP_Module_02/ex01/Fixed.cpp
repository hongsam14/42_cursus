/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:13:53 by suhong            #+#    #+#             */
/*   Updated: 2022/01/18 18:33:56 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_num_of_fractional_bits(8);

Fixed::Fixed() : _fixed_point_value(0)
{
	std::cout<<"Default constructor called"<<std::endl;
}

Fixed::Fixed(const int param)
{
	std::cout<<"Int constructor called"<<std::endl;
	this->_fixed_point_value = param << this->_num_of_fractional_bits;
}

Fixed::Fixed(const float param)
{
	std::cout<<"Float constructor called"<<std::endl;
	this->_fixed_point_value = roundf(param * (1 << this->_num_of_fractional_bits));
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

std::ostream	&operator<<(std::ostream &os, const Fixed &fixed)
{
	os<<fixed.toFloat();
	return (os);
}

int	Fixed::getRawBits(void) const
{
	return (this->_fixed_point_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixed_point_value = raw;
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(this->_fixed_point_value) / (1 << this->_num_of_fractional_bits));
}

int	Fixed::toInt(void) const
{
	return (this->_fixed_point_value >> this->_num_of_fractional_bits);
}
