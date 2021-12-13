/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 19:53:42 by suhong            #+#    #+#             */
/*   Updated: 2021/12/13 18:05:43 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

static void	prompt(phonebook::Phonebook *phone)
{
	std::string	str;
	
	std::cout<<"Input command. "<<std::endl;
	while (true)
	{
		std::getline(std::cin, str);
		if (str == "ADD")
		{
			phone->add();
		}
		else if (str == "SEARCH")
		{
			phone->search();
		}
		else if (str == "EXIT")
		{
			break ;
		}
		else
		{
			std::cout<<"Nonvalid command. "<<std::endl;
		}
	}
}

int	main(void)
{
	phonebook::Phonebook	book;

	prompt(&book);
	return (0);
}
