/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhong <suhong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 01:52:45 by suhong            #+#    #+#             */
/*   Updated: 2021/12/23 18:02:34 by suhong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main(void)
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout<<"str address: "<<&str<<std::endl;
	std::cout<<"PTR address: "<<stringPTR<<std::endl;
	std::cout<<"REF address: "<<&stringREF<<std::endl;

	std::cout<<"string PTR: "<<*stringPTR<<std::endl;
	std::cout<<"string REF: "<<stringREF<<std::endl;
	return (0);
}
