/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 20:36:50 by suhong            #+#    #+#             */
/*   Updated: 2021/12/13 18:25:46 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

phonebook::Phonebook::Phonebook()
{
	for (int i = 0; i < 8; i++)
	{
		this->container[i].set_index(i + 1);
	}
	this->size = 0;
}

phonebook::Phonebook::~Phonebook()
{
}

void	phonebook::Phonebook::printInForm(int leng, int limit, ...)
{
	va_list	ap;
	std::string	s;
	int	w_leng;

	va_start(ap, limit);
	for (int i = 0; i < leng; i++)
	{
		s = va_arg(ap, const char *);
		std::cout<<"|";
		if (s.length() < (unsigned long)limit || limit == 0)
		{
			if (limit == 0)
				w_leng = s.length();
			else
				w_leng = limit;
			std::cout<<std::left<<std::setw(limit)<<s;
		}
		else
		{
			std::cout<<std::left<<std::setw(limit - 1)<<s.substr(0, limit - 1)<<".";
		}
	}
	std::cout<<"|"<<std::endl;
	va_end(ap);
}

void	phonebook::Phonebook::showIdx()
{
	std::string	str;
	int		idx;
	char		idx_c;
	
	std::cout<<"Input index. "<<std::endl;
	while (true)
	{
		std::getline(std::cin, str);
		idx = atoi(str.c_str());
		if ((idx < 1 || idx > 8) || idx > this->size)
		{
			std::cout<<"Index out of range. "<<std::endl;
			continue ;
		}
		idx_c = '0' + this->container[idx - 1].get_index();
		this->printInForm(2, 0, "index", &idx_c);
		this->printInForm(2, 0, "first name", this->container[idx - 1].get_firstName().c_str());
		this->printInForm(2, 0, "last name", this->container[idx - 1].get_lastName().c_str());
		this->printInForm(2, 0, "nickname", this->container[idx - 1].get_nickName().c_str());
		this->printInForm(2, 0, "phone number", this->container[idx - 1].get_phoneNumber().c_str());
		this->printInForm(2, 0, "darkest secret", this->container[idx - 1].get_darkestSecret().c_str());
		break ;
	}
}

void	phonebook::Phonebook::showAll()
{
	int	max;
	char	idx;

	max = this->size < 8 ? this->size : 8;
	for (int i = 0; i < max; i++)
	{
		idx = '0' + this->container[i].get_index();
		this->printInForm(4, 10, &idx
				  , this->container[i].get_firstName().c_str()
				  , this->container[i].get_lastName().c_str()
				  , this->container[i].get_nickName().c_str());
	}
}

void	phonebook::Phonebook::search()
{
	this->showAll();
	this->showIdx();
	std::cout<<"Search complete."<<std::endl;
}

void	phonebook::Phonebook::add()
{
	std::string	str;
	int		idx;
	
	idx = this->size != 0? this->size % 8 : 0;
	std::cout<<"Input first name."<<std::endl;
	std::getline(std::cin, str);
	this->container[idx].set_firstName(str);
	std::cout<<"Input last name."<<std::endl;
	std::getline(std::cin, str);
	this->container[idx].set_lastName(str);
	std::cout<<"Input nickname."<<std::endl;
	std::getline(std::cin, str);
	this->container[idx].set_nickName(str);
	std::cout<<"Input phone number."<<std::endl;
	std::getline(std::cin, str);
	this->container[idx].set_phoneNumber(str);
	std::cout<<"Input darkest secret."<<std::endl;
	std::getline(std::cin, str);
	this->container[idx].set_darkestSecret(str);
	this->size++;
	std::cout<<"Add complete. "<<std::endl;
}
