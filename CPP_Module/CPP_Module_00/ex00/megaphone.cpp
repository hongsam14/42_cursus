/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 12:06:21 by suhong            #+#    #+#             */
/*   Updated: 2021/10/27 12:06:28 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <cctype>
#include <cstring>
#include <cstddef>

void print_upper_str(char *str)
{
	for (size_t i = 0; i < std::strlen(str); i++)
	{
		str[i] = std::toupper(str[i]);
	}
	std::cout << str;
}

int main(int argc, char *argv[])
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < argc; i++)
		{
			print_upper_str(argv[i]);
		}
		std::cout << std::endl;
	}
	return 0;
}
