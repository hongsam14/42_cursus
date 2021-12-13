/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 12:07:09 by suhong            #+#    #+#             */
/*   Updated: 2021/12/13 18:03:46 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <vector>
# include <cstdarg>
# include <cstdlib>

namespace phonebook
{
	class Contact
	{
		public:
			Contact();
			~Contact();
			void	set_index(int index);
			void	set_firstName(std::string input);
			void	set_lastName(std::string input);
			void	set_nickName(std::string input);
			void	set_phoneNumber(std::string input);
			void	set_darkestSecret(std::string input);
			int	get_index();
			std::string	get_firstName();
			std::string	get_lastName();
			std::string	get_nickName();
			std::string	get_phoneNumber();
			std::string	get_darkestSecret();
		private:
			int	index;
			std::string	first_name;
			std::string	last_name;
			std::string	nickname;
			std::string	phone_number;
			std::string	darkest_secret;
	};

	class Phonebook
	{
		public:
			Phonebook();
			~Phonebook();
			void	add();
			void	search();
		private:
			Contact container[8];
			void	printInForm(int leng, int limit, ...);
			void	showAll();
			void	showIdx();
			int	size;
	};
}

#endif
