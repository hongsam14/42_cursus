/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 18:17:48 by suhong            #+#    #+#             */
/*   Updated: 2021/12/13 17:59:20 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

phonebook::Contact::Contact()
{
	this->index = 0;
}

phonebook::Contact::~Contact()
{
}

void	phonebook::Contact::set_index(int index)
{
	this->index = index;
}

void	phonebook::Contact::set_firstName(std::string input)
{
	this->first_name = input;
}

void	phonebook::Contact::set_lastName(std::string input)
{
	this->last_name = input;
}

void	phonebook::Contact::set_nickName(std::string input)
{
	this->nickname = input;
}

void	phonebook::Contact::set_phoneNumber(std::string input)
{
	this->phone_number = input;
}

void	phonebook::Contact::set_darkestSecret(std::string input)
{
	this->darkest_secret = input;
}

int	phonebook::Contact::get_index()
{
	return (this->index);
}

std::string	phonebook::Contact::get_firstName()
{
	return (this->first_name);
}

std::string	phonebook::Contact::get_lastName()
{
	return (this->last_name);
}

std::string	phonebook::Contact::get_nickName()
{
	return (this->nickname);
}

std::string	phonebook::Contact::get_phoneNumber()
{
	return (this->phone_number);
}

std::string	phonebook::Contact::get_darkestSecret()
{
	return (this->darkest_secret);
}
